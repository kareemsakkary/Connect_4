#include <iostream>

using namespace std;

void print_table(char symbols[7][6]);
int get_input(char symbols[7][6],int p);
int get_length_of_column(char symbols[7][6],int column);
bool check_win(char symbols[7][6],int column,int p);
int main()
{  
    char symbols[7][6]; //create 2d array to store the symbol in each cell
    // asign symbols " " at the begining
    for(int i = 0;i<7;i++){
        for(int j =0; j<6;j++){
            symbols[i][j]=' ';
        }
    }
    print_table(symbols);
    bool not_end = true;
    int c=0;
    int i=0;
    while (not_end && i<42)
    {
        int p =c%2;
        c++;
        int inp = get_input(symbols,p+1)-1;
        if(p==0)
            symbols[inp][get_length_of_column(symbols,inp)]='X';
        else
            symbols[inp][get_length_of_column(symbols,inp)]='O';
        print_table(symbols);
        not_end=check_win(symbols,inp,p);
        i++;
    }
    if(not_end){
        cout<<"Draw";
    }
    char x ;
    cin >>x;
    return 0;
    }

void print_table(char symbols[7][6]){
    system("CLS");
    cout <<"       Connect 4 Game \n";
    for(int j = 0;j<7;j++){
            for(int i =0;i<7;i++){
                if(j==6){
                    if(i==0)
                        cout << "  " << i+1 << "  ";
                    else
                        cout << " " << i+1 << "  ";
                }else{
                    if(i==0)
                        cout << "| "<<symbols[i][5-j]<<" |" ;
                    else
                        cout << " "<<symbols[i][5-j]<<" |" ;
                }
            }
            cout  << endl;
        }
    cout <<"\n";
}

int get_input(char symbols[7][6],int p){
    int inp;
    cout <<"player_"<<p<<" enter column number : ";
    cin >> inp;
    while (inp>7 || get_length_of_column(symbols,inp-1)>=6)
    {
        /* code */
        cout <<"invalid input, player_"<<p<<" enter column number : ";
        cin >> inp;
    }
    cout<<"\n";
    return inp;
}

int get_length_of_column(char symbols[7][6],int column){
    int count = 0;
    for(int i=0;i<6;i++){
        if(symbols[column][i]!=' '){
            count++;
        }
        else{
            break;
        }
    }
    return count;
}

bool check_win(char symbols[7][6],int column,int p){
    int row = get_length_of_column(symbols,column)-1;
    bool not_end=true;
    char sym;
    if (p==0)
        sym = 'X';
    else
        sym = 'O';
    // check vertical
    int c = 0;
    for(int i=0;i<=row;i++){
        if(symbols[column][i]==sym)
            c++;
        else
            c=0;
        if(c==4){
            cout << "player_" << p+1 <<" Win !";
            not_end=false;
            return not_end;
        }
    }
    // check horzontal
    c = 0;
    for(int i=0;i<=6;i++){
        if(symbols[i][row]==sym)
            c++;
        else
            c=0;
        if(c==4){
            cout << "player_" << p+1 <<" Win !";
            not_end=false;
            return not_end;
        }
    }
    //check right_horzntal
    int start_row =0;
    int start_column = 0;
    if (row > column){
        start_row = row-column;
        start_column = 0;
    }else if( column > row ){
        start_column = column-row;
        start_row = 0;
    }
    c=0;
    while (start_row<6 && start_column<7)
    {
        if(symbols[start_column][start_row]==sym)
            c++;
        else
            c=0;
        if(c==4){
            cout << "player_" << p+1 <<" Win !";
            not_end=false;
            return not_end;
        }
        start_row++;
        start_column++;
    }
    // check left_horzontal
    start_row =0;
    start_column = column + row;
    if (start_column>6){
        start_column = 6;
        start_row = row-(start_column-column);
    }else {
        start_row=0;
    }
    c=0;
    while (start_row<6 && start_column>=0)
    {
        if(symbols[start_column][start_row]==sym)
            c++;
        else
            c=0;
        if(c==4){
            cout << "player_" << p+1 <<" Win !";
            not_end=false;
            return not_end;
        }
        start_row++;
        start_column--;
    }
    return not_end ;
}
