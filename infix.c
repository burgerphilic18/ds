#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isdigit(c)) postfix[j++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (peek() != '(') postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && prec(peek()) >= prec(c)) postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1) postfix[j++] = pop();
    postfix[j] = '\0';
}

int evalPostfix(char* postfix) {
    int valStack[SIZE], t = -1;
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isdigit(c)) valStack[++t] = c - '0';
        else {
            int b = valStack[t--], a = valStack[t--];
            switch (c) {
                case '+': valStack[++t] = a + b; break;
                case '-': valStack[++t] = a - b; break;
                case '*': valStack[++t] = a * b; break;
                case '/': valStack[++t] = a / b; break;
            }
        }
    }
    return valStack[t];
}

int main() {
    char infix[] = "3+(2*4)-5";
    char postfix[SIZE];
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evalPostfix(postfix));
    return 0;
}