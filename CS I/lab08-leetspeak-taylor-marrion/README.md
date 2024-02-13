# Lab08 - Leetspeak

## Points: 20 (Manual Review & Autograde)

## Submission
`commit` and `push` your code to the `main` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to your local machine or the cs.dsunix.net machine using the link provided on the GitHub repo page

## Description
Write a program to accept a sentence or phrase from the user and convert it to leetspeak. The conversions you should use are as follows:

| Characters | Conversion |
|---|---|
| `A` or `a` | `@` |
| `I` or `i` | `!` |
| `E` or `e` | `3` |
| `0` | `O` |
| `O` | `0` |
| `S` or `s` | `$` |
| `T` or `t` | `7` |

## Requirements
User input for the string should be done carefully and in a safe manner. Prompts should be similar to those shown in the example output below. You should be able to read a string up to 999 characters in length.

Additionally, be sure to compose a well-formatted, readable program that includes useful variable names.

## Example Output
`$` is the prompt - you do not need to reproduce the `$` and your prompts do not need to match exactly. All inputs in this program exist after the prompts (which are denoted by `:`) 

```
$ ./a.out
Enter a phrase to convert: This is a test of the leetspeak generator. Neat stuff.
Your converted string is 7h!$ !$ @ 73$7 of 7h3 l337$p3@k g3n3r@7or. N3@7 $7uff.
$
```
