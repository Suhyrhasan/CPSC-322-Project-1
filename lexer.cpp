#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

// enum for token types
enum tokenType { IDENTIFIER, INTEGER, KEYWORD, OPERATOR, REAL, SEPARATOR, STRING, UNKNOWN, END_OF_FILE };
/************************************************************************
 * tokenType lex(string token)
 * 
 * Function; This function will take a string and return the token type
 *-----------------------------------------------------------------------
 * Parameter:  token (string) - The string to be checked for token type
 *-----------------------------------------------------------------------
 * Return: tokenType - The token type of the string
************************************************************************/
tokenType lexer(string token) {
    // check if token is a keyword
    if (token == "if" || token == "else" || token == "while" || token == "do" || token == "for" || token == "int" || token == "float" || token == "double" || token == "return" || token == "void" || token == "main" || token == "upper" || token == "lower") {
        return KEYWORD;
    }
    // check if token is an operator
    else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "=" || token == "==" || token == "!=" || token == "<" || token == ">" || token == "<=" || token == ">=" || token == "++" || token == "--" || token == "&&" || token == "||" || token == "!" || token == "&" || token == "|" || token == "^" || token == "%" || token == "~" || token == "<<" || token == ">>" || token == "+=" || token == "-=" || token == "*=" || token == "/=" || token == "%=" || token == "&=" || token == "|=" || token == "^=" || token == "<<=" || token == ">>=") {
        return OPERATOR;
    }
    // check if token is a separator
    else if (token == "(" || token == ")" || token == "{" || token == "}" || token == "[" || token == "]" || token == ";" || token == "," || token == ".") {
        return SEPARATOR;
    }
    // check if token is an identifier
    else if (isalpha(token[0]) || token[0] == '_') {
        return IDENTIFIER;
    }
    // check if token is an integer
    else if (isdigit(token[0])) {
        return INTEGER;
    }
    // check if token is a real
    else if (isdigit(token[0]) && token.find('.') == string::npos) {
        return REAL;
    }
    // check if token is a string
    else if (token[0] == '"' && token[token.length() - 1] == '"') {
        return STRING;
    }
    // check if token is end of file
    else if (token == "EOF" || token == "eof") { 
        return END_OF_FILE;
    }
    // if none of the above, return error
    else {
        return UNKNOWN;
    }
}

/************************************************************************
 * main()
 * 
 * Function; This function will read in a file and output the tokens and
 *          their types to a file called "output.txt".
 *-----------------------------------------------------------------------
 * Parameter:  None
 *-----------------------------------------------------------------------
 * Return: int - 0
************************************************************************/
int main()
{
    // open input_scode.txt to read in a lexeme
    ifstream inputFile; 
    inputFile.open("input_scode.txt");
    // open output_scode.txt to output the lexeme and token
    ofstream outputFile;
    outputFile.open("output.txt");
    // create a token
    string tokenInput = "";
    outputFile << "Token" << " \t \t " << "Lexeme" << endl;
    outputFile << "-----------------------" << endl;

    /************************************************************************
     * This while loop will read in a lexeme from input_scode.txt and then
     * output the token and lexeme to output_scode.txt until the end of file
     ************************************************************************/
    while ( inputFile >> tokenInput ) 
    {

         // call lexer function to determine token type
        tokenType token = lexer(tokenInput);
        // output the lexeme and token to output_scode.txt
        if( token == IDENTIFIER) {
            outputFile << setw(15) << left << "Identifier" << setw(15) << left << tokenInput << endl;
        }
        else if (token == INTEGER) {
            outputFile << setw(15) << left << "Integer" << setw(15) << left << tokenInput << endl;
        }
        else if (token == KEYWORD) {
            outputFile << setw(15) << left << "Keyword" << setw(15) << left << tokenInput << endl;
        }
        else if (token == OPERATOR) {
            outputFile << setw(15) << left << "Operator" << setw(15) << left << tokenInput << endl;
        }
        else if (token == REAL) {
            outputFile << setw(15) << left << "Real" << setw(15) << left << tokenInput << endl;
        }
        else if (token == SEPARATOR) {
            outputFile << setw(15) << left << "Separator" << setw(15) << left << tokenInput << endl;
        }
        else if (token == STRING) {
            outputFile << setw(15) << left << "String" << setw(15) << left << tokenInput << endl;
        }
        else if (token == UNKNOWN) {
            outputFile << setw(15) << left << "Unknown" << setw(15) << left << tokenInput << endl;
        }
        else if (token == END_OF_FILE) {
            break;
        }
    }
    // close files
    inputFile.close();
    outputFile.close();
    return 0;
}
