#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printLinkedList(struct node *p) {
    while (p != NULL) {
        printf("%d", p->data);
        p = p->next;
    }
}

int main() {
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->next = two;
    one->data = 1;
    two->next = three;
    two->data = 2;
    three->next = NULL;
    three->data = 3;

    head = one;
    printLinkedList(head);

    return 0;
}
