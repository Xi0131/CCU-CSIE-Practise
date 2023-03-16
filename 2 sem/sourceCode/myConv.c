/* This file handles all conversion */

#include "basic.h"
#include "myConv.h"
#include "myCalc.h"
#include "myIO.h"

int str2Num(char *s){   // convert string into numbers
    int num = 0;
    while(*s) num = num * 10 + ((*s++) - '0');
    return num;
}

void infixToPrefix(char **tokens, int tokenLens){
    int expIdx = 0;
    int operIdx = 0;
    int flag = 0;   // reason for loop stopping
    char *expression[MAXBUF];
    char *tmpOper[MAXBUF];  // stack actually
    char *tmpToken;

    for (int i = tokenLens - 1; i >= 0; i--){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) expression[expIdx++] = tmpToken;  // number just print
        else if (operIdx == 0) tmpOper[operIdx++] = tmpToken;   // if stack empty, push into stack
        else if (precedCmp(tmpToken, tmpOper[operIdx - 1]) == LOWER){
            flag = 0;
            for (int j = operIdx - 1; j >= 0; j--){ // for all lower precedence, print
                if (precedCmp(tmpToken, tmpOper[j]) == LOWER) expression[expIdx++] = tmpOper[j];
                else {
                    tmpOper[j + 1] = tmpToken;
                    operIdx = j + 2;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){ // in case empty stack, the token didn't push into stack
                tmpOper[0] = tmpToken;
                operIdx = 1;
            }
        }
        else tmpOper[operIdx++] = tmpToken;
    }
    for (int i = operIdx - 1; i >= 0; i--){ // reverse the expression
        expression[expIdx++] = tmpOper[i];
    }

    _exp_print(expression, expIdx, Rev);
}

void infixToPostfix(char **tokens, int tokenLens){
    int expIdx = 0;
    int operIdx = 0;    // handle stack
    int flag = 0;   // reason for loop stopping
    char *expression[MAXBUF];
    char *tmpOper[MAXBUF];  // stack actually
    char *tmpToken;

    for (int i = 0; i < tokenLens; i++){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) expression[expIdx++] = tmpToken;  // number just print
        else if (operIdx == 0) tmpOper[operIdx++] = tmpToken;
        else if (precedCmp(tmpToken, tmpOper[operIdx - 1]) == HIGHER) tmpOper[operIdx++] = tmpToken;
        else{   // for all not higher precedence, print
            flag = 0;
            for (int j = operIdx - 1; j >= 0; j--){
                if (precedCmp(tmpToken, tmpOper[j]) != HIGHER) expression[expIdx++] = tmpOper[j];
                else {
                    tmpOper[j + 1] = tmpToken;
                    operIdx = j + 2;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){ // empty stack, so the tmpToken not push into stack
                tmpOper[0] = tmpToken;
                operIdx = 1;
            }
        }
    }
    for (int i = operIdx - 1; i >= 0; i--){ // pop all operators
        expression[expIdx++] = tmpOper[i];
    }

    _exp_print(expression, expIdx, Nor);
}

void postfixToInfix(char **tokens, int tokenLens){
    int operIdx = 0;
    char expression[MAXBUF];
    char tmpExp[MAXBUF];
    char *tmpOper[MAXBUF];  // stack actually
    char *tmpToken;
    
    for (int i = 0; i < tokenLens; i++){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) tmpOper[operIdx++] = strdup(tmpToken);    // if numbers, just print
        else{
            sprintf(tmpExp, "%s %s %s", tmpOper[operIdx - 2], tmpToken, tmpOper[operIdx - 1]);  // concatenate
            free(tmpOper[operIdx - 2]);
            free(tmpOper[operIdx - 1]);
            tmpOper[operIdx - 2] = strdup(tmpExp);  // and push back
            operIdx = operIdx - 1;
        }
    }

    _exp_print(tmpOper, 1, Nor);
    free(tmpOper[0]);
}

void postfixToPrefix(char **tokens, int tokenLens){
    int operIdx = 0;
    char expression[MAXBUF];
    char tmpExp[MAXBUF];
    char *tmpOper[MAXBUF];  // stack actually
    char *tmpToken;
    
    for (int i = 0; i < tokenLens; i++){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) tmpOper[operIdx++] = strdup(tmpToken);    // if number, just print
        else{
            sprintf(tmpExp, "%s %s %s", tmpToken, tmpOper[operIdx - 2], tmpOper[operIdx - 1]);  // concatenate
            free(tmpOper[operIdx - 2]);
            free(tmpOper[operIdx - 1]);
            tmpOper[operIdx - 2] = strdup(tmpExp);  // push back to satck
            operIdx = operIdx - 1;
        }
    }

    _exp_print(tmpOper, 1, Nor);
    free(tmpOper[0]);
}

void prefixToInfix(char **tokens, int tokenLens){
    int operIdx = 0;
    char expression[MAXBUF];
    char tmpExp[MAXBUF];
    char *tmpOper[MAXBUF];  // stack acutually
    char *tmpToken;
    
    for (int i = tokenLens - 1; i >= 0; i--){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) tmpOper[operIdx++] = strdup(tmpToken);    // if number, just push
        else{
            sprintf(tmpExp, "%s %s %s", tmpOper[operIdx - 1], tmpToken, tmpOper[operIdx - 2]); // concatenate
            free(tmpOper[operIdx - 2]);
            free(tmpOper[operIdx - 1]);
            tmpOper[operIdx - 2] = strdup(tmpExp);  // push back to stack
            operIdx = operIdx - 1;
        }
    }

    _exp_print(tmpOper, 1, Nor);
    free(tmpOper[0]);
}

void prefixToPostfix(char **tokens, int tokenLens){
    int operIdx = 0;
    char expression[MAXBUF];
    char tmpExp[MAXBUF];
    char *tmpOper[MAXBUF];  // stack actually
    char *tmpToken;
    
    for (int i = tokenLens - 1; i >= 0; i--){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) tmpOper[operIdx++] = strdup(tmpToken);    // if number, just print
        else{
            sprintf(tmpExp, "%s %s %s", tmpOper[operIdx - 1], tmpOper[operIdx - 2], tmpToken);  // concatenate
            free(tmpOper[operIdx - 2]);
            free(tmpOper[operIdx - 1]);
            tmpOper[operIdx - 2] = strdup(tmpExp);  // push back to stack
            operIdx = operIdx - 1;
        }
    }

    _exp_print(tmpOper, 1, Nor);
    free(tmpOper[0]);
}