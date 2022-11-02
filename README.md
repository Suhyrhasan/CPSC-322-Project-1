# CPSC 322 Project 1
## Overview

We designed and implemented an FSA in the main function `lexer()` in `lexer.cpp`. This function reads in the tokens from the given file `input_scode.txt`.

## Collaborators
Suhyr Hasan suhyrhasan@csu.fullerton.edu

Nishan Thakar nishantt91@csu.fullerton.edu

Jackie Li jli306@csu.fullerton.edu

## How to Run
To clone repository run the following command in your terminal:
```
git clone https://github.com/Suhyrhasan/CPSC-322-Project-1
```
To compile the program run the following command in your terminal:
```
g++ -o lexer lexer.cpp
```
To run the program run the following command in your terminal:
```
./lexer
```
## Output
The output of the program is in the file `output.txt`. In the output file, the first field is the token and the second field is the lexeme. The output file is formatted in the following way:

## Example
The following is an example of the output file:
```
Token        Lexeme
---------------------
Identifier     x
Integer        5
Keyword        while
Operator       =
Real           3.14
Separator      ;
```
