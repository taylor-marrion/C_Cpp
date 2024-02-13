# Lab07 - Store

## Points: 20 (Manual Review Only)

## Submission
`commit` and `push` your code to the `main` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to your local machine or the cs.dsunix.net machine using the link provided on the GitHub repo page

## Description
Write a program that uses an array to track which items a user has selected to purchase and prints the status of those items. Each item has two states, available and sold out. An item is available at program run time and sold out if the user selects it.

Additionally, you should both welcome and thank your customer by their name.

## Requirements
Whether or not an item is sold should be tracked using an array. The user's name must be read in and stored as a string. The status of all items should be printed each time the user is prompted. Cases where an item doesn't exist or is sold out should be handled.

Additionally, be sure to compose a well-formatted, readable program that includes useful variable names.

## Example Output
`$` is the prompt - you do not need to reproduce the `$` and your prompts do not need to match exactly. All inputs in this program exist after the prompts (which are denoted by `:`) 

```
$ ./a.out
Enter your name: Dale
Welcome Dale!


Select an item to buy:
  0) available
  1) available
  2) available
  3) available
  4) available
Item (-1 to quit): 1


Select an item to buy:
  0) available
  1) sold out
  2) available
  3) available
  4) available
Item (-1 to quit): 100
***Item 100 doesn't exist


Select an item to buy:
  0) available
  1) sold out
  2) available
  3) available
  4) available
Item (-1 to quit): 4


Select an item to buy:
  0) available
  1) sold out
  2) available
  3) available
  4) sold out
Item (-1 to quit): 4
***Item 4 is sold out!


Select an item to buy:
  0) available
  1) sold out
  2) available
  3) available
  4) sold out
Item (-1 to quit): -1
Thanks for shopping with us, Dale
$
```
