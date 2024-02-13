# Lab01 - Variables

## Points: 20 (Autograde & Manual Review)

## Submission
`commit` and `push` your code to the `master` branch on the remote GitHub repository **before** the deadline.

You must utilize the included C source file for the autograding to work. Autograding requires that outputs are formatted identical to the example (you can copy the example output as necessary).

## Clone
`clone` this repo to your local machine or the cs.dsunix.net machine using the link provided on the GitHub repo page

## Description
In this assignment, you are to create a program that reads in basic product information and provides it back to the user. It's simple, but a necessary step
towards the more complex programs of later in the term.

## Requirements
You should read in the following items using appropriate types.

1. A 3 character product identifier (ex: `AZJ`)
2. A price for the product (ex: `4.99`)
3. A single character representing quality of the product (ex: `B`)
4. The quantity of the product that's currently available (ex: `33`)

Additionally, be sure to compose a well-formatted, readable program that includes useful variable names.

## Example Output
`$` is the prompt - you do not need to reproduce the `$`. The first four lines are for user input. The last line is output.

```
$ ./a.out
Product ID: AAA
     Price: 4.56
   Quality: C
  Quantity: 34
There are 34 AAA of quality score C available at a price of $4.56 each
$
```
