#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int val) {
    if (top < SIZE - 1)
        stack[++top] = val;
    else
        printf("Stack Overflow\n");
}

int pop() {
    if (top >= 0)
        return stack[top--];
    else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Popped: %d\n", pop());
    push(40);
    push(50);
    push(60);
    while (top >= 0)
        printf("Popped: %d\n", pop());
    return 0;
}
