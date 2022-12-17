#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void startBoard();
bool draw(int count);
bool winCond();
bool p1Move(int x, int y);
bool p2Move(int x, int y);
bool compMove(int x, int y);
void updateBoard();
void clearBoard();

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int movesMade=0;

//Tic Tac Toe game between 2 players or player vs computer
int main(){

    int menuOption;
    time_t t;
    srand((unsigned)time(&t));
    int playAgain;

    do{
        //resets all variables
        clearBoard();
        movesMade=0;
        menuOption=0;

    //prompt user for game they wish to play
    printf("Welcome to TicTacToe.\n1---person vs person\n2---person vs random computer\nEnter your choice 1 or 2\n");

    //read information from console and keeps asking until valid input
    scanf("%d",&menuOption);
    while(menuOption !=1 && menuOption != 2){
        printf("Invalid input, please try again\n");
        scanf("%d",&menuOption);
    }

    //read info and print board according to input
    if(menuOption==1){
        int x;
        int y;
        startBoard();

        //keeps asking for more moves until there is a draw or one of the players win
        while(movesMade<=9){
            
            if(movesMade%2 == 0){ //checks if it is p1's move
                //asks player1 for move
                printf("Player 1 move:\n");
                scanf("%d %d", &x,&y);
                x--;
                y--;

                //checks if the input is valid and then updates the board
                if(x>=0 && x<3 && y>=0 && x<3){
                    //update board
                    if(p1Move(x,y)){
                        updateBoard();
                        movesMade++;
                        }
                    else
                        continue;

                 }else{ //input is not valid so will ask again and continue to next iteration
                    printf("invalid input try again\n");
                    continue;
                }
            }
            
            //checks if p1 won and breaks if true
            if(winCond()){
                printf("Player 1 wins!");
                break;
            }

            if(movesMade%2 == 1){ //checks if it is p2's move
                //asks player2 for move
                printf("Player 2 move:\n");
                scanf("%d %d", &x,&y);
                x--;
                y--;

                //checks if the input is valid and then updates the board
                if(x>=0 && x<3 && y>=0 && x<3){

                    //update board
                    if(p2Move(x,y)){
                        updateBoard();
                        movesMade++;
                        }
                    else
                        continue;

                 }else{ //input is not valid so will ask again and continue to next iteration
                    printf("invalid input try again\n");
                    continue;
                }
            }

            //checks if p2 won and breaks
            if(winCond()){
                printf("Player 2 wins!");
                break;
            }

        }

    }else if(menuOption==2){ //plays player vs computer
        int x;
        int y;
        startBoard();

        while(movesMade<=9){

            if(movesMade%2 == 0){ //checks if it is p1's move
                //asks player1 for move
                printf("Player move:\n");
                scanf("%d %d", &x,&y);
                x--;
                y--;

                //checks if the input is valid and then updates the board
                if(x>=0 && x<3 && y>=0 && x<3){
                    //update board
                    if(p1Move(x,y)){
                        updateBoard();
                        movesMade++;
                        }
                    else
                        continue;

                 }else{ //input is not valid so will ask again and continue to next iteration
                    printf("invalid input try again\n");
                    continue;
                }
            }
            
            //checks if p1 won and breaks if true
            if(winCond()){
                printf("Player wins!");
                break;
            }

            //computer makes move
            printf("Computer moves: \n");
            x=rand()%3;
            y=rand()%3;
            while(!compMove(x,y)){
                x=rand()%3;
                y=rand()%3;
            }
            movesMade++;
            updateBoard();
            if(winCond()){
                printf("Computer wins!");
                break;
            }

        }



    }
    printf("\nWould you like to play again?\n1. Yes\n2. No\n");
    scanf("%d",&playAgain);
    }while(playAgain==1);
    
   

    return 0;
}

void startBoard(){
    printf("+------+\n");
    printf("| | | |\n");
    printf("+------+\n");
    printf("| | | |\n");
    printf("+------+\n");
    printf("| | | |\n");
    printf("+------+\n");

}

//checks if the game has become a draw
bool draw(int count){
    if(count>=9)
    return true;
    
    return false;
}

//checks win condition
bool winCond(){
     // Rows and Columns
    if ((board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])){
        
        return true;

    }else if ((board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])){
       
        return true;
    
    }else if ((board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2]) || (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])){
        
        return true;
    
    }// Diagonals
    else if ((board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])){

        return true;
    
    }
    return false;
}

//updates the board with O for p1, returns true or false depending on valid input
bool p1Move(int x, int y){

    if(board[x][y]!='X' && board[x][y]==' '){
        board[x][y]='O';
    }else if(board[x][y] == 'X'){
        printf("invalid move\n");
        return false;
    }

    return true;


}

bool p2Move(int x, int y){
    if(board[x][y]!='O' && board[x][y]==' '){
        board[x][y]='X';
    }else if(board[x][y] == 'O'){
        printf("invalid move\n");
        return false;
    }

    return true;
}

bool compMove(int x, int y){
    if(board[x][y]!='O' && board[x][y]==' '){
        board[x][y]='X';
    }else if(board[x][y] == 'O'){
        return false;
    }

    return true;
}

void updateBoard(){
    for(int i =0; i<3; i++){
        printf("+------+\n");
        for(int j =0; j<3; j++){
            printf("|%c",board[i][j]);
        }
        printf("|\n");
    }
}

void clearBoard(){
    for(int i =0; i< 3; i++){
        for(int j =0; j<3; j++){
            board[i][j]=' ';
        }
    }
}
