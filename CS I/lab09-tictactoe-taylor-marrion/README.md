# Lab09 - TicTacToe

## Points: 20 (Manual Review & Autograde)

## Submission
`commit` and `push` your code to the `main` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to your local machine or the cs.dsunix.net machine using the link provided on the GitHub repo page

## Description
Create a program to allow two users to play TicTacToe as discussed in class.

## Requirements
The only input for the program is positions of either `x` or `o` on the board. Output should alert the user if someone has won, and if so - who. Stalemates should be announced, as should invalid moves. This is demonstrated in detail in the class video.

`x` always should go first

The output of the game must contain `x won` or `o won` if x or o win, and `no winner` if there's a stalemate.

If a space is occupied and a user attempts to add something to that space, the output must contain `occupied`.

Additionally, be sure to compose a well-formatted, readable program that includes useful variable names.

## Example Output
`$` is the prompt - you do not need to reproduce the `$` and your prompts do not need to match exactly. All inputs in this program exist after the prompts (which are denoted by `:`) 

```
$ ./a.out
Enter a row and column for x: 0 0
x| |
-+-+-
 | |
-+-+-
 | |
Enter a row and column for o: 0 1
x|o|
-+-+-
 | |
-+-+-
 | |
Enter a row and column for x: 1 1
x|o|
-+-+-
 |x|
-+-+-
 | |
Enter a row and column for o: 0 2
x|o|o
-+-+-
 |x|
-+-+-
 | |
Enter a row and column for x: 2 2
x|o|o
-+-+-
 |x|
-+-+-
 | |x
The player using x won the game
$
```

```
$ ./a.out
Enter a row and column for x: 0 0
x| |
-+-+-
 | |
-+-+-
 | |
Enter a row and column for o: 0 0
That space is occupied - try again
Enter a row and column for o: 1 0
x| |
-+-+-
o| |
-+-+-
 | |
Enter a row and column for x: 0 1
x|x|
-+-+-
o| |
-+-+-
 | |
Enter a row and column for o: 1 1
x|x|
-+-+-
o|o|
-+-+-
 | |
Enter a row and column for x: 0 2
x|x|x
-+-+-
o|o|
-+-+-
 | |
The player using x won the game
$
```

```
$ ./a.out
Enter a row and column for x: 2 2
 | |
-+-+-
 | |
-+-+-
 | |x
Enter a row and column for o: 0 0
o| |
-+-+-
 | |
-+-+-
 | |x
Enter a row and column for x: 2 1
o| |
-+-+-
 | |
-+-+-
 |x|x
Enter a row and column for o: 2 0
o| |
-+-+-
 | |
-+-+-
o|x|x
Enter a row and column for x: 1 0
o| |
-+-+-
x| |
-+-+-
o|x|x
Enter a row and column for o: 1 1
o| |
-+-+-
x|o|
-+-+-
o|x|x
Enter a row and column for x: 0 2
o| |x
-+-+-
x|o|
-+-+-
o|x|x
Enter a row and column for o: 1 2
o| |x
-+-+-
x|o|o
-+-+-
o|x|x
Enter a row and column for x: 0 1
o|x|x
-+-+-
x|o|o
-+-+-
o|x|x
There is no winner
$
```
