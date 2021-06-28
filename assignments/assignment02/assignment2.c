/*
Coded by Ibrahim Enes Duran
Assignment 2 | Reservation Systems with COVID19 Situtions
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char alphabet[26]  = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; // Alphabet Constant 
/*
Info | Seats Array
 0 = Empty Seat = -
 1 = Reserved Seats = X
 2 = Just Reserved Seats = +
-1 = Aisles = | |
*/
/*  Seats Layout Printer Function   */
void printSeats(int seats[][99], int rows, int realLength){
    int countChar = 0; 
    printf("\n");
    printf("   ");
    countChar = 0;
    for(int i = 0; i < realLength; i++){
        if(seats[0][i] == -1)
            printf("| | ");
        else{
            printf("%c ", alphabet[countChar]);
            countChar++;
        }
    }
    printf("\n");
    for(int A = 0; A < rows; A++){
        if(A < 9)
        printf("%d  ", A + 1);
        else
        printf("%d ", A + 1);
        for(int B = 0; B < realLength; B++){
            if(seats[A][B] == -1)
                printf("| | ");
            if(seats[A][B] == 0)
                printf("- ");
            if(seats[A][B] == 1)
                printf("X ");
            if(seats[A][B] == 2){
                printf("+ ");
                seats[A][B] = 1;
            }
        }
        printf("\n");
    }
    printf("\n");
}
/*  Main Assign Seat Function  */
void engine(int seats[][99], int rows, int realLength, int countSeat){
    int theBestRow, theBestCol, realSeatRowLength = 0;
    float tempScore = 0.0, maxScore = -100000000000000000000.0;
    if(countSeat == 1){
        realSeatRowLength = -1;
        for(int A = 0; A < rows; A++){
            for(int B = 0; B < realLength; B++){
                if(seats[A][B] == 0){
                    A =+ 10000;
                    B =+ 10000;
                    realSeatRowLength = 0;
                }
            }
        }
        if(realSeatRowLength == -1){
            printf("\nNo available seats for the requested reservation!\n\n");
        }else{
            for(int A = 0; A < rows; A++){
                for(int B = 0; B < realLength; B++){
                    if(seats[A][B] == 0){
                        for(int C = 0; C < rows; C++){
                            for(int D = 0; D < realLength; D++){
                                if(seats[C][D] == 1){
                                    float x = (abs(A - C) + abs(B - D) / 2.0); // 0 0 | 4 4
                                    if(x == 0.0)
                                        tempScore = 0.0 + tempScore;                           
                                    else
                                        tempScore = (100.0 - pow(100.0, 1 / x)) + tempScore;
                                }
                            }
                        }
                        if(tempScore > maxScore){
                            maxScore = tempScore;
                            theBestRow = A;
                            theBestCol = B;
                        }
                    }
                    tempScore = 0.0;
                }
            }
            realSeatRowLength = 0;
            if(maxScore == 0){
                int A = 0;
                for(A = 0; A < rows; A++){
                    for(int B = 0; B < realLength; B++){
                        if(seats[A][B] == 0){
                            seats[A][B] = 2;
                            for(int i = 0; i < B; i++){
                                if(!(seats[0][i] == -1))
                                    realSeatRowLength++;
                            }
                            A += 10000;
                            B += 10000;
                        }
                    }
                }
                printf("Reserved seats: %d%c", A - 10000, alphabet[realSeatRowLength]);
            }else{
                seats[theBestRow][theBestCol] = 2;
                for(int i = 0; i < theBestCol; i++){
                    if(!(seats[0][i] == -1))
                        realSeatRowLength++;
                }
                printf("Reserved seats: %d%c", theBestRow + 1, alphabet[realSeatRowLength]);
            }
            printf("\n");
            printSeats(seats, rows, realLength);
        }
    }else{
        int tempEmptySeats, countPlaces = 0, places[99];
        for(int A = 0; A < rows; A++){
            for(int B = 0; B < realLength; B++){
                if(seats[A][B] == 0){
                    tempEmptySeats = 0;
                    for(int i = 0; i < realLength - B; i++){
                        if(seats[A][B+i] == 0)
                            tempEmptySeats++;
                        else if(seats[A][B+i] == 1)
                            break;
                    }
                    if(tempEmptySeats >= countSeat){
                        places[countPlaces] = 100 * A + B;
                        countPlaces++;
                    }
                }
            }
        } 
        if(countPlaces == 0)
            printf("\nNo available seats for the requested reservation!\n\n");
        else{
            int theBestAisles = 9999;
            for(int i = 0; i < countPlaces; i++){
                int A = places[i] / 100;
                int B = places[i] % 100;
                int a = 0;
                for(int b = 0; b < countSeat + a; b++){
                    if(seats[A][B+b] == -1)
                        a++;
                    else{
                        for(int C = 0; C < rows; C++){
                            for(int D = 0; D < realLength; D++){
                                if(seats[C][D] == 1){
                                    float x = (abs(A - C) + abs(B + b - D) / 2.0); // 0 0 | 4 4
                                    if(x == 0.0)
                                        tempScore = 0.0 + tempScore;                           
                                    else
                                        tempScore = (100.0 - pow(100.0, 1 / x)) + tempScore;
                                }
                            }
                        }
                    }
                }
                if(maxScore < tempScore){
                    theBestRow = A;
                    theBestCol = B;
                    theBestAisles = a;
                    maxScore = tempScore;
                }else if(maxScore == tempScore){
                    if(theBestAisles > a){
                        theBestRow = A;
                        theBestCol = B;
                        theBestAisles = a;
                        maxScore = tempScore;
                    }
                }
                tempScore = 0.0;
            }
            printf("Reserved seats: ");
            for(int i = 0; i < countSeat + theBestAisles; i++){
                realSeatRowLength = 0;
                if(!(seats[theBestRow][theBestCol+i] == -1)){
                    seats[theBestRow][theBestCol+i] = 2;
                    for(int a = 0; a < theBestCol+i; a++){
                        if(!(seats[0][a] == -1))
                            realSeatRowLength++;
                    }
                    printf("%d%c ", theBestRow + 1, alphabet[realSeatRowLength]);
                }
            }
            printf("\n");
            printSeats(seats, rows, realLength);
        }

    }
}
/*  Main Function */
int main(){
    int rows, perRow, aisles, aislesAfterSeat[10], tempRow, realLength = 0, seats[99][99], tempReservations;

    printf("Number of rows: ");
    scanf("%d", &rows);
    printf("Number of seats per row: ");
    scanf("%d", &perRow);
    printf("Number of aisles: ");
    scanf("%d", &aisles);
    for(int i = 0; i < aisles; i++){
        printf("Add aisle %d after seat: ", i+1);
        scanf("%d", &aislesAfterSeat[i]);
    }
    /*        Design Seats Layout in array START    */
    for(int B = 0; B < rows; B++){
        realLength = 0;
        for(int b = 0; b < aisles; b++){
            if(b == 0){
                tempRow = aislesAfterSeat[b];
            }else{
                tempRow = aislesAfterSeat[b] - aislesAfterSeat[b-1];
            }
            for(int c = 0 + realLength; c < tempRow + realLength; c++){
                seats[B][c] = 0;
            }
            realLength += tempRow;
            seats[B][realLength] = -1;
            realLength += 1;
        }

        for(int i = realLength; i < perRow + aisles; i++){
            seats[B][i] = 0;
            realLength++;
        }
    }
    /*         Design Seats Layout in array FINISH   */
    printSeats(seats, rows, realLength);
    while(1){
        printf("The number of people in the reservation\n (0: print current reservations, -1: exit): ");
        scanf("%d", &tempReservations);
        if(tempReservations == -1)
            return EXIT_SUCCESS;
        else if(tempReservations == 0)
            printSeats(seats, rows, realLength);
        else{
            engine(seats, rows, realLength, tempReservations);
        }
    }
}