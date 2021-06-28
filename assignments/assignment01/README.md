# INTRODUCTION TO SCIENTIFIC AND ENGINEERING COMPUTATION

## Assignment 1 | March 2021


**Objective:** Tracking the score of one game in tennis.

## Description

(taken from Wikipedia) In tennis, a game consists of a sequence of points played
with the same player serving. A game is won by the rst player to have won
at least four points in total and at least two points more than the opponent.
Scores from zero to three points are described as "0", "15", "30", and "40". If
at least three points have been scored by each player, making the game score
(40-40), the score is called out as "deuce". If at least three points have been
scored by each side and a player has one more point than the opponent, the
score of the game is "advantage" for the player in the lead.

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


* Your source code le has to have the name assignment1.c.
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


