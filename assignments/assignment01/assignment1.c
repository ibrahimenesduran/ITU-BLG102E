#include <stdio.h>
#include <stdlib.h>

int main(){
    int player1 = 0, player2 = 0, gameWin = 0, gameStatus = 0;
   
    while(gameStatus != 1){
        if(gameStatus == 0){
            printf("%d-%d\n", player1, player2);
        }
        printf("Point: ");
        scanf("%d", &gameWin);
        if(gameWin == 1){
            if(player1 == 0 || player1 == 15){
                player1 = player1 + 15;
            }else if(player1 == 30){
                player1 = player1 + 10;
            }else if(player1 >= 40){
                player1 = player1 + 5;
            }
        }else if(gameWin == 2){
            if(player2 == 0 || player2 == 15){
                player2 = player2 + 15;
            }else if(player2 == 30){
                player2 = player2 + 10;
            }else if(player2 >= 40){
                player2 = player2 + 5;
            }
        }
        if(player1 >= 40 && player2 >= 40 && player1 == player2){
            printf("DEUCE\n");
            gameStatus = 2;
        }else if (player1 >= 40 && player2 >= 40 && player1  == player2 + 5){
            printf("ADVANTAGE: PLAYER 1\n");
        }else if(player1 >= 40 && player2 >= 40 && player2 == player1 + 5){
            printf("ADVANTAGE: PLAYER 2\n");
        }else if(player1 >= 40 && player2 >= 40 && player2 == player1 + 10){
            printf("GAME: PLAYER 2\n");
            gameStatus = 1;
            return EXIT_SUCCESS;
        }else if(player1 >= 40 && player2 >= 40 && player1 == player2 + 10){
            printf("GAME: PLAYER 1\n");
            gameStatus = 1;
            return EXIT_SUCCESS;
        }else if(player1 == 45 && player2 < 40){
            printf("GAME: PLAYER 1\n");
            gameStatus = 1;
            return EXIT_SUCCESS;
        }else if(player2 == 45 && player1 < 40){
            printf("GAME: PLAYER 2\n");
            gameStatus = 1;
            return EXIT_SUCCESS;
        }
    }
    
}