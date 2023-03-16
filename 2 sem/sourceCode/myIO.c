/* This file handles all inputs and outputs*/

#include "myIO.h"
#include "basic.h"

void _check_args(int argc, char **argv, int *notation, int *action){
    // Error arguments amount
    if (argc > 4) _error_message(TooMany);
    else if (argc < 2) _error_message(TooLess);
    
    // argument checker
    if (strcmp(argv[1], "infix") == 0) *notation = INFIX;
    else if (strcmp(argv[1], "prefix") == 0) *notation = PREFIX;
    else if (strcmp(argv[1], "postfix") == 0) *notation = POSTFIX;
    else _error_message(Unknown);
    for (int i = 2; i < argc; i++){
        if (strcmp(argv[i], "calc") == 0) action[0] = TRUE;
        else if (strcmp(argv[i], "conv") == 0) action[1] = TRUE;
        else _error_message(Unknown);
    }
}

// get one line and split into tokens
int _get_input(char **tokens){
    int tokenIdx = 0;
    char inputLine[MAXBUF];
    char tmpToken[MAXBUF];
    char *ptr = inputLine;

    char *getLine = fgets(inputLine, MAXBUF, stdin);
    while(getLine && sscanf(ptr, " %s", tmpToken) != EOF){
        tokens[tokenIdx++] = strdup(tmpToken);
        ptr += strlen(tmpToken);
        while(*ptr && isspace(*ptr)) ptr++; // move to next tokens
    }
    return tokenIdx;
}

void _free_tokens(char **tokens, int tokenLens){
    for (int i = 0; i < tokenLens; i++)
        free(tokens[i]);    // strdup = malloc + strcpy
}                           // need free the memory

// print the expression
void _exp_print(char **expression, int expLens, int mode){
    if (mode == Rev)    // print reversely
        for (int i = expLens - 1; i >= 0; i--) printf("%s ", expression[i]);
    else
        for (int i = 0; i < expLens; i++) printf("%s ", expression[i]);
    printf("\n");
}

// print the result
void _calcResult_print(int result){
    printf("%d\n", result);
}

void _error_message(int condition){ // handle all wrong message
    if (condition == TooMany) printf("Too many arguments!\n");
    else if (condition == TooLess) printf("Lack arguments!\n");
    else if (condition == Unknown) printf("Unknown arguments!\n");
    else if (condition == Duplicate) printf("Same arguments!\n");
    printf("Usage: EX3 notation action [action2]\n");
    printf("notations: infix, prefix, postfix\n");
    printf("action: calc, conv\n");
    exit(1);
}