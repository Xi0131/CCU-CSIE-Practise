#define SAME 1
#define HIGHER 2
#define LOWER 3

int precedCmp(char *oper1, char *oper2);

int infixCalc(char **tokens, int tokenLens);
int prefixCalc(char **tokens, int tokenLens);
int postfixCalc(char **tokens, int tokenLens);

#define isAddOrMinus(oper) ((*oper) == '+' || (*oper) == '-' ? 1 : 2)