#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int boardSize, xPos, yPos, i, j;
char **gameBoard;
char move;

void readFile(){
    FILE *file;
    file = fopen("puzzle.txt", "r");
    fscanf(file, "%d", &boardSize);
    
    gameBoard = (char**) malloc(sizeof(char*) * boardSize);
    for(i = 0; i < boardSize; i++) gameBoard[i] = (char*) malloc(sizeof(char) * boardSize); 
    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardSize; j++){
            gameBoard[i][j] = (char) fgetc(file);
            if(gameBoard[i][j] == '\n') gameBoard[i][j] = (char) fgetc(file);
            if(gameBoard[i][j] == 'k' || gameBoard[i][j] == 'K'){
                xPos = i;
                yPos = j;
            }
        }
    }
}

void printMenu(){
    printf("[1] Start Game\n[2] View High Scores\n[3] Quit Game\n>>");
    scanf("%c", &move);
}

void printBoard(){
    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardSize; j++){
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

int checkWin(){
    return 1;
}

void checkMove(int newX, int newY, int newX2, int newY2){
    // if floor  tile
    if(gameBoard[newX][newY] == 'e'){
        gameBoard[newX][newY] = 'k';
        if(gameBoard[xPos][yPos] == 'K') gameBoard[xPos][yPos] = 's';
        else gameBoard[xPos][yPos] = 'e';
        xPos = newX;
        yPos = newY;
    }
    else if(gameBoard[newX][newY] == 's'){
        gameBoard[newX][newY] = 'K';
        if(gameBoard[xPos][yPos] == 'K') gameBoard[xPos][yPos] = 's';
        else gameBoard[xPos][yPos] = 'e';
        xPos = newX;
        yPos = newY;
    }
    else if(gameBoard[newX][newY] == 'b' || gameBoard[newX][newY] == 'B'){
        if(gameBoard[newX2][newY2] == 'e'){
            gameBoard[newX2][newY2] = 'b';
            if(gameBoard[newX][newY] == 'B') gameBoard[newX][newY] = 'K';
            else gameBoard[newX][newY] = 'k';
            if(gameBoard[xPos][yPos] == 'K') gameBoard[xPos][yPos] = 's';
            else gameBoard[xPos][yPos] = 'e';
            xPos = newX;
            yPos = newY;
        }else if(gameBoard[newX2][newY2] == 's'){
            gameBoard[newX2][newY2] = 'B';
            if(gameBoard[newX][newY] == 'B') gameBoard[newX][newY] = 'K';
            else gameBoard[newX][newY] = 'k';
            if(gameBoard[xPos][yPos] == 'K') gameBoard[xPos][yPos] = 's';
            else gameBoard[xPos][yPos] = 'e';
            xPos = newX;
            yPos = newY;
        }
    }
}

int main(){
    // Main Menu
    while(1){
        printMenu();
        if(move == '1'){
            // Read file   
            readFile();

            // Start game
            while(move != '3'){
                printBoard();
                printf("Enter Move:");
                scanf("%s", &move);
                // getchar();
                move = tolower(move);
                switch(move){
                    case 'w':
                        checkMove(xPos - 1, yPos, xPos - 2, yPos);
                        break;
                    case 'a':
                        checkMove(xPos, yPos - 1, xPos, yPos - 2);
                        break;
                    case 's':
                        checkMove(xPos + 1, yPos, xPos + 2, yPos);
                        break;
                    case 'd':
                        checkMove(xPos, yPos + 1, xPos, yPos + 2);
                        break;
                    default:
                        break;
                }
            }

        }else if (move == '2'){}
        
        if (move == '3') break;
    }
    return 0;
}