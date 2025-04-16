#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = 0, rear = -1, count = 0;

void insert(int val) {
    if (count < SIZE) {
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
        count++;
    } else
        printf("Queue Overflow\n");
}

int delete() {
    if (count > 0) {
        int val = queue[front];
        front = (front + 1) % SIZE;
        count--;
        return val;
    } else {
        printf("Queue Underflow\n");
        return -1;
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    printf("Deleted: %d\n", delete());
    insert(40);
    insert(50);
    insert(60);
    while (count > 0)
        printf("Deleted: %d\n", delete());
    return 0;
}
