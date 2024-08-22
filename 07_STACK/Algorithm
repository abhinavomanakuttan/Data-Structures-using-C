#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for(i = 0; i < strlen(infix); i++) {
        if(infix[i] == ' ')
            continue;
        if(isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if(infix[i] == '(')
            push(infix[i]);
        else if(infix[i] == ')') {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop(); // Remove the '('
        } else {
            while(top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while(top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int i, x1, x2;
    for(i = 0; i < strlen(postfix); i++) {
        if(isalnum(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            x2 = pop();
            x1 = pop();
            switch(postfix[i]) {
                case '+':
                    push(x1 + x2);
                    break;
                case '-':
                    push(x1 - x2);
                    break;
                case '*':
                    push(x1 * x2);
                    break;
                case '/':
                    push(x1 / x2);
                    break;
            }
        }
    }
    return pop();
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}
