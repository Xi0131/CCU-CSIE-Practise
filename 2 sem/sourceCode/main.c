#include "myIO.h"
#include "myConv.h"
#include "myCalc.h"
#include "basic.h"

int main(int argc, char **argv){    // command line argumens
    int tokenLen;
    char **tokens = (char **) malloc(sizeof(char *) * MAXBUF);
    int notation;
    int action[2] = {0};    // 0: calc, 1: convert

    int (*calcs[3])(char **, int) = {infixCalc, prefixCalc, postfixCalc};   //function pointer
    void (*convert[6])(char **, int) = {infixToPrefix, infixToPostfix, prefixToInfix, prefixToPostfix, postfixToInfix, postfixToPrefix};
    _check_args(argc, argv, &notation, action);

    // start the program
    tokenLen = _get_input(tokens);
    while(tokenLen != 0){   // get nothing means to stop
        if (action[0] == TRUE) calcs[notation](tokens, tokenLen);
        if (action[1] == TRUE){ 
           convert[2 * (notation)](tokens, tokenLen);
           convert[2 * (notation) + 1](tokens, tokenLen);
        }
        _free_tokens(tokens, tokenLen);
        tokenLen = _get_input(tokens);
    }
    return 0;
}