#include "basic.h"
#include "myCalc.h"
#include "myConv.h"
#include "myIO.h"

// compare two operator's precedence
int precedCmp(char *oper1, char *oper2){
    if (isAddOrMinus(oper1)){   // if operator is "+" or "-"
                                // hint '?' operator
        if (isAddOrMinus(oper2)) return SAME;
        else return LOWER;
    }
    else{
        if (isAddOrMinus(oper2)) return HIGHER;
        else return SAME;
    }
}

int infixCalc(char **tokens, int tokenLens){
    int numIdx = 0;
    int operIdx = 0;
    int numHead = 0;
    int tmpNum[MAXBUF]; // queue for numbers
    char *tmpOper[MAXBUF];  // queue for operators
    char *tmpToken;

    for (int i = 0; i < tokenLens; i++){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) tmpNum[numIdx++] = str2Num(tmpToken);
        else if(tmpToken[0] == '*'){    // if '*', act directly
            i++;
            tmpToken = tokens[i];
            tmpNum[numIdx - 1] *= str2Num(tmpToken);
        }
        else if(tmpToken[0] == '/'){ // if '/', act directly
            i++;
            tmpToken = tokens[i];
            tmpNum[numIdx - 1] /= str2Num(tmpToken);
        }
        else{
            tmpOper[operIdx++] = tmpToken;
        }
    }
    for (int i = 0; i < operIdx; i++){  // for the remain operators, perform in appearance
        if (tmpOper[i][0] == '+'){
            tmpNum[numHead + 1] += tmpNum[numHead];
        }
        else if (tmpOper[i][0] == '-'){
            tmpNum[numHead + 1] = tmpNum[numHead] - tmpNum[numHead + 1];
        }
        numHead++;
    }

    _calcResult_print(tmpNum[numHead]);
    return 0;
}

int prefixCalc(char **tokens, int tokenLens){
    int operIdx = 0;
    int tmpNum;
    int tmpOper[MAXBUF];    // stack
    char *tmpToken;
    
    for (int i = tokenLens - 1; i >= 0; i--){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) tmpOper[operIdx++] = str2Num(tmpToken);   // if digit, just print
        else{   // act according to the operator
            if (strcmp(tmpToken, "+") == 0)
                tmpOper[operIdx - 2] += tmpOper[operIdx - 1];
            else if (strcmp(tmpToken, "-") == 0)
                tmpOper[operIdx - 2] = tmpOper[operIdx - 1] - tmpOper[operIdx - 2];
            else if (strcmp(tmpToken, "*") == 0)
                tmpOper[operIdx - 2] *= tmpOper[operIdx - 1];
            else if (strcmp(tmpToken, "/") == 0)
                tmpOper[operIdx - 2] = tmpOper[operIdx - 1] / tmpOper[operIdx - 2];
            operIdx--;
        }
    }

    _calcResult_print(tmpOper[0]);
    return 0;
}

int postfixCalc(char **tokens, int tokenLens){
    int operIdx = 0;
    int tmpNum;
    int tmpOper[MAXBUF];    //stack
    char *tmpToken;
    
    for (int i = 0; i < tokenLens; i++){
        tmpToken = tokens[i];
        if (isdigit(tmpToken[0])) tmpOper[operIdx++] = str2Num(tmpToken);   // if digit, just push
        else{   // according to operator, act
            if (strcmp(tmpToken, "+") == 0)
                tmpOper[operIdx - 2] += tmpOper[operIdx - 1];
            else if (strcmp(tmpToken, "-") == 0)
                tmpOper[operIdx - 2] -= tmpOper[operIdx - 1];
            else if (strcmp(tmpToken, "*") == 0)
                tmpOper[operIdx - 2] *= tmpOper[operIdx - 1];
            else if (strcmp(tmpToken, "/") == 0)
                tmpOper[operIdx - 2] /= tmpOper[operIdx - 1];
            operIdx--;
        }
    }

    _calcResult_print(tmpOper[0]);
    return 0;
}