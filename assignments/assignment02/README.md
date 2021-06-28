# INTRODUCTION TO SCIENTIFIC AND ENGINEERING COMPUTATION

## Assignment 2 | Spring 2021


**Objective:** Making airline reservations for individuals and groups.

## Description

In this assignment, you will be developing an airline reservation system that may be adapted to different flights operated by a variety of aircraft types with distinct layouts. The reservation system will allow individual and group reservations. The features and working principles of your program should follow the below-listed specifications.

1. Your program should first determine the seating layout of the specific aircraft that you are going to make reservations for. To this end, the number of seating rows (min: 1, max: 99), the number seats per row (min: 1, max: 20), the number of aisles (min: 1, max: 5), and the location of aisles are needed. The location of each aisle will be requested separately, and an aisle location will be specified as the number of seats to its left (here, left refers to the left of your screen). Once the layout information is provided by the user, your program will draw the layout on the screen as shown below. Each row is numbered numerically, and each column is marked with capital case letters in alphabetical order. Each dash (“-“) represent an empty seat, and vertical bars (“|“) mark the aisle borders.

```
Number of rows: 12
Number of seats per row: 7
Number of aisles: 2
Add aisle 1 after seat: 2
Add aisle 2 after seat: 5

   A B | | C D E | | F G
1  - - | | - - - | | - -
2  - - | | - - - | | - -
3  - - | | - - - | | - -
4  - - | | - - - | | - -
5  - - | | - - - | | - -
6  - - | | - - - | | - -
7  - - | | - - - | | - -
8  - - | | - - - | | - -
9  - - | | - - - | | - -
10 - - | | - - - | | - -
11 - - | | - - - | | - -
12 - - | | - - - | | - -

The number of people in the reservation
 (0: print current reservations, -1: exit):
```

2. Below the layout, the program will ask the number of people for whom you want to make reservation. The program will not allow the customers to choose their seats. It will automatically assign the seats. To determine the seat assignments, it will follow the below-listed rules.

    a) Considering the COVID-19 situation, your program will try to assign seats to the passengers to place them as far as possible from each other to minimize the risk of infection. To this end, for a passenger, it will assign a new seat that has the largest total distance to the already reserved seats. The distance between a seat s1 (located at row i1, column j1) and another seat s2 (located at row i2, column j2) will be computed as follows:

    <img src="https://latex.codecogs.com/svg.image?dist(s_{1},&space;s_{2})&space;=&space;|&space;i_{1}&space;-&space;i_{2}|&space;&plus;&space;\frac{|&space;j_{1}&space;-&space;j_{2}|}{2}" title="dist(s_{1}, s_{2}) = | i_{1} - i_{2}| + \frac{| j_{1} - j_{2}|}{2}" />

    where each aisle location should also be taken into consideration as equivalent to one seat space.

    <img src="https://latex.codecogs.com/svg.image?adjusted_-dist(s_{1},&space;s_{2})&space;=&space;\left\{\begin{matrix}&space;0&space;&space;&space;&&space;if&space;dist(s_{1},&space;s_{2})&space;=&space;0&space;\\&space;100&space;-&space;(100)^{\frac{1/}{dist(s_{1},&space;s_{2})}}&space;&&space;&space;otherwise\end{matrix}\right." title="adjusted_-dist(s_{1}, s_{2}) = \left\{\begin{matrix} 0 & if dist(s_{1}, s_{2}) = 0 \\ 100 - (100)^{\frac{1/}{dist(s_{1}, s_{2})}} & otherwise\end{matrix}\right." />

    Then, the score of a seat sx is computed as:

    <img src="https://latex.codecogs.com/svg.image?score(s_{x})=&space;\sum&space;s_{i}\epsilon&space;\textit{Already&space;reserved&space;seats&space;&space;}&space;adjusted_-dist(s_{x},&space;s_{i})&space;" title="score(s_{x})= \sum s_{i}\epsilon \textit{Already reserved seats } adjusted_-dist(s_{x}, s_{i}) " />

    b) For a single passenger reservation, an empty seat with the maximum score is assigned. If there are different seat candidates with the same score, then the one with lower row number will be chosen. If the row numbers are also the same, the one with the lower column number will be assigned.

    c) For a family reservation that includes n individuals (n > 1), your program will look for a consecutive block of n seats located in the same row (note that a seat block is allowed to span one or more aisles). If there is no such block of seats, your program will not make group reservation by printing an appropriate message as illustrated in the following examples. For a block of n seats the distance-based score will be computed as follows:

    <img src="https://latex.codecogs.com/svg.image?seat_-block_-score&space;(s_{1},&space;s_{2}&space;...&space;s_{n})=&space;&space;\sum_{i=1}^{n}&space;score(s_{i})" title="seat_-block_-score (s_{1}, s_{2} ... s_{n})= \sum_{i=1}^{n} score(s_{i})" />

    If there are different seat blocks with the same score, then the one with the least number of aisles passing through the block will be assigned. For instance, seat blocks which are not divided with aisles in the same row will be preferred over those where one or more aisles divide the block. For two different seat blocks, if seat block scores are the same, and the number of aisles passing through these blocks are also the same, then the seat block with the lower row number will be preferred. If the row numbers are also the same, then the one with the lower column number (of the leftmost seat in the block) will be assigned.

    d) After an appropriate empty seat is assigned based on the above-explained score considerations, the row number and column letter of the assigned seat (s) will be listed on the same line. Then, this message will be followed by the aircraft layout showing the just reserved seats as shown in the following example where X represent seats that are reserved in previous iterations, + shows the seats that are just reserved in the most recent step, and – shows empty seats.

    ```
    The number of people in the reservation
    (0: print current reservations, -1: exit): 4
    Reserved seats: 4A 4B 4C 4D

    A B | | C D E | | F G
    1  X X | | - - - | | - -
    2  - - | | - X X | | X X
    3  - - | | - - - | | - -
    4  + + | | + + - | | - -
    5  - - | | - - - | | X X
    6  - - | | - - - | | - -
    7  - - | | - - - | | - -
    8  - - | | X X X | | X X
    9  X - | | - - - | | - -
    10 X X | | X X X | | X X
    11 - - | | - - - | | - -
    12 - - | | - - - | | X X

    The number of people in the reservation
    (0: print current reservations, -1: exit):
    ```
## Assignment

Write a C program that will get the outcome of each point (1 for player 1, and
2 for player 2) and print the status of the game. At the end of the game, the
program will report the winner.
Below is an example run (italic parts are user inputs):

```
0-0
Point: 1
15-0
Point: 1
30-0
Point: 1
40-0
Point: 2
40-15
Point: 1
GAME: PLAYER 1
```
Another example involving a deuce:

```
0-0
Point: 1
15-0
Point: 2
15-15
Point: 2
15-30
Point: 2
15-40
Point: 1
30-40
Point: 1
DEUCE
Point: 1
ADVANTAGE: PLAYER 1
Point: 2
DEUCE
Point: 2
ADVANTAGE: PLAYER 2
Point: 2
GAME: PLAYER 2
```
You don't need to validate user inputs; you can assume that the user always
enters 1 or 2.

## Rules


* Your source code le has to have the name assignment1.c.
* Your program will be compiled using the following command on a Linux
system. If it cannot be compiled and linked using this command, it will
not be graded (failed submission).

```
gcc -std=c99 -Wall -Werror assignment1.c -o assignment
```
* Your program will be checked using an automatic checker. Therefore,
make sure you print the messages exactly as given in the example runs.
You will be given a Calico test file for some basic I/O tests; run your
assignment through Calico before submitting.

* Do NOT use statements for clearing the terminal or waiting for a keypress
before exiting the program; these might cause your program to fail in
the automatic tests. Some IDEs generate such statements, remove them.
Running your program through Calico is the safest way to make sure that
your program works as expected.

* Do NOT use any construct that hasn't been covered in the course before
this week, such as arrays or functions. Do NOT use any C++ features
such as cout and cin.

* Do NOT use any external functions except for printf and scanf.

* Make sure your coding style is proper and consistent. Use the clang-format
tool if necessary. Don't use any variable names in a language other than
English.

* This is an individual assignment. Collaboration in any form is NOT al-
lowed. No working together, no sharing code in any form including
showing code to your classmates to give them ideas.

* All the code you submit must be your own. Don't copy/paste any piece of
code from any resource including anything you've found on the Internet.

* The assignments will be checked for plagiarism using both automated
tools and manual inspection. Any assignment involving plagiarism and/or
infringement of intellectual property will be not be graded and is subject
to further disciplinary actions.


