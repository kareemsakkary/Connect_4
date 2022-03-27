# connect 4 game for asseignmet 1 
# by: kareem sakkary(20210301)
# at: 21/2/2022
# player 1 symbol is X, Player 2 symbol is O
import os

symbols = [[],[],[],[],[],[],[]]
game_on = True
def print_table():
    os.system("cls" if os.name == 'nt' else 'clear')
    for r in range(1,8):
        if r<7:
            print(7-r,end="|")
        for c in range(1,8):
            if(r==7):
                print("  ",c,end="")
            else:
                if(len(symbols[c-1])<=6-r):
                    print("   |",end="")
                else:
                    print(" "+symbols[c-1][6-r]+" |",end="")
        print()

def check_win(symbol,column):
    #In this function I check if there is win in verical row and horzntal column and diagonals
    #which pass through the cell
    win = False
    row = len(symbols[column])-1
    #vertical
    c=0
    for j in symbols[column]:
        if j==symbol:
            c+=1
            if c == 4:
                win = True
                return win
        else:
            c=0
    #horzntal
    c=0
    for j in symbols:
        if len(j)>row:
            if j[row]==symbol:
                c+=1
                if c == 4:
                    win = True
                    return win
            else:
                c=0
        else:
            c=0
    #right diagonal
    start_row =0
    start_column = 0
    if row > column:
        start_row = row-column
        start_column = 0
    elif column > row:
        start_column = column-row
        start_row = 0
    c=0
    while start_row <6 and start_column <7:
        if len(symbols[start_column])>start_row:
            if symbols[start_column][start_row]==symbol:
                c+=1
                if c == 4:
                    win = True
                    return win
            else:
                c=0
        else:
            c=0
        start_column +=1
        start_row += 1
    #left diagonal
    start_column = column + row
    if start_column>6:
        start_column = 6
        start_row = row-(start_column-column)
    else :
        start_row=0
    c=0
    while start_row <6 and start_column >=0:
        if len(symbols[start_column])>start_row:
            if symbols[start_column][start_row]==symbol:
                c+=1
                if c == 4:
                    win = True
                    return win
            else:
                c=0
        else:
            c=0
        start_column -=1
        start_row += 1
    return win
   
def add_symbol(symbol,column):
    global game_on
    symbols[column-1].append(symbol)#just add symbol to the column
    print_table()#call function that print Table
    return check_win(symbol,column-1) #call function that check if player win or not and return boolean
    
def get_inputs():
    global game_on
    syms=["X","O"]
    for i in range(0,2): #loop for switch between player one and player two
        flag= True
        player =input("Player_"+str(i+1)+"("+syms[i]+")"+" enter the number of the column : ")
        if player == "quit":# option to exit game in any time
            game_on=False
            break
        else:
            while flag:
                if player.isdigit():#check if the input is number
                    if(int(player)>0 and int(player)<8):#check if the input in range 1 to 7
                        if len(symbols[int(player)-1])<6:#check if the inputed column is full or not
                            flag=False
                            win = add_symbol(syms[i],int(player))#call function that add symbol to column and return boolean if win or not
                            if win: 
                                print("Player_"+str(i+1)+" Win")
                                game_on=False
                                break

                        else:
                            player =( input("Full column, Player_"+str(i+1)+"("+syms[i]+")"+" another enter the number of the column : "))
                    else:
                        player =( input("Invalid input, Player_"+str(i+1)+"("+syms[i]+")"+" enter the number(1 to 7) of the column : "))
                else:
                    player =( input("Invalid input, Player_"+str(i+1)+"("+syms[i]+")"+" enter the number of the column : "))
        if not game_on:
            break

def main():
    print_table()
    num_cells = (7*6)//2
    for i in range(0,num_cells) :
        get_inputs()
        if not game_on:
            break
    if game_on :
        print("Draw")
main()

input()