# Lab03 - Calculator

## Points: 20 (Autograde & Manual Review)

## Submission
`commit` and `push` your code to the `main` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to your local machine or the cs.dsunix.net machine using the link provided on the GitHub repo page

## Description
In this assignment you'll create a basic calculator that determines the operation requested by the user using either if statements or switch statements and then performs that operation.

## Requirements
You should read in the following items using appropriate types. Your user will only enter integers and characters in this program.

1. The first integer
2. An operator from the list `+ - * /`
3. The second integer

Output should consist of the following items:

1. The result of the operation specified by the user (addition for +, subtraction for -, etc.)

Additionally, be sure to compose a well-formatted, readable program that includes useful variable names.

## Example Output
`$` is the prompt - you do not need to reproduce the `$`. The first three lines are for user input. The last line is output

```
$ ./a.out
Enter Value: 4
Enter Operator: +
Enter Value: 5
4 + 5 is 9
$
```
```
$ ./a.out
Enter Value: 4
Enter Operator: -
Enter Value: 5
4 - 5 is -1
$
```
```
$ ./a.out
Enter Value: 4
Enter Operator: *
Enter Value: 5
4 * 5 is 20
$
```
```
$ ./a.out
Enter Value: 4
Enter Operator: /
Enter Value: 5
4 / 5 is 0
$
```
```
$ ./a.out
Enter Value: 25
Enter Operator: /
Enter Value: 5
25 / 5 is 5
$
```
```
$ ./a.out
Enter Value: 10
Enter Operator: &
Enter Value: 5
Invalid operator: &
$
```
