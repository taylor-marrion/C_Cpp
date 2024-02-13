# Lab02 - Math

## Points: 20 (Manual Review)

## Submission
`commit` and `push` your code to the `master` branch on the remote GitHub repository **before** the deadline. As autograding isn't used, your output doesn't need to match exactly.

## Clone
`clone` this repo to your local machine or the cs.dsunix.net machine using the link provided on the GitHub repo page

## Description
In this assignment you'll create a program to accept input related to a person's income and output their available funds to budget after rent is paid.

## Requirements
You should read in the following items using appropriate types. Your user will only enter floats or integers in this program. There will be no other characters (ex: `$`).

1. The hourly wage of the person
2. The number of hours worked for the month (will only be integers)
3. The tax rate (this can be made up)
4. The cost of rent

Output should consist of the following items:

1. Gross income for the month
2. Total tax (tax rate * gross income)
3. Net income (income - tax)
4. Available to budget (net income - rent)

Additionally, be sure to compose a well-formatted, readable program that includes useful variable names.

## Example Output
`$` is the prompt - you do not need to reproduce the `$`. The first four lines are for user input. The last 5 lines are output.

```
$ ./a.out
    Wage: $15.45
   Hours: 80
Tax rate: .21
    Rent: $600
--------------------------
Gross Income: $1236.00
         Tax: $259.56
  Net Income: $976.44
 Tot. Budget: $376.44
$
```
