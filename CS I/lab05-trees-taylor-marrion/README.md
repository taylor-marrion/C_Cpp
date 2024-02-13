# Lab05 - Trees

## Points: 20 (Autograde & Manual Review)

## Submission
`commit` and `push` your code to the `main` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to your local machine or the cs.dsunix.net machine using the link provided on the GitHub repo page

## Description
This assignment will allow a user to enter one or more sizes of trees to be printed. It will require up to 4 loops to complete.

## Requirements
Your only input will be the size (height) of the tree. Width of the tree is calculated by multiplying height by 2 and subtracting 1. (Ex: a tree of height 5 is 9 characters wide at it's lowest point, excluding the trunk). You may read more than one size. A size less than 1 is the terminal condition (exit the outer loop).

Output will be trees of the specified size.

Additionally, be sure to compose a well-formatted, readable program that includes useful variable names.

## Example Output
`$` is the prompt - you do not need to reproduce the `$`. The lines labeled Size of Tree are prompts for input, all numbers are input, all other lines are output.

```
$ ./a.out
Size of Tree: 1
#
#
Size of Tree: 2
 #
###
 #
Size of Tree: 5
    #
   ###
  #####
 #######
#########
    #
Size of Tree: 10
         #
        ###
       #####
      #######
     #########
    ###########
   #############
  ###############
 #################
###################
         #
Size of Tree: 0

$
```
