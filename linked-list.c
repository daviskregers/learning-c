#include <stdio.h>
#include <stdlib.h>

/**
 * Yoinked from: 
 * https://www.programiz.com/dsa/linked-list
 * https://www.learn-c.org/en/Linked_lists
 */

struct node {
    int data;
    struct node *next;
};

void printLinkedList(struct node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void push_end(struct node *head, int val) {
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (struct node *) malloc(sizeof(struct node));
    current->next->data = val;
    current->next->next = NULL;
}

void push_beginning(struct node **head, int val) {
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(struct node **head) {
    int retval = -1;
    struct node * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->data;

    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(struct node *head) {
    int retval = -1;
    if (head->next == NULL) {
        retval = head->data;
        free(head);
        return retval;
    }

    struct node * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    retval = current->next->data;
    free(current->next);
    current->next = NULL;
    return retval;
}

int remove_by_index(struct node **head, int idx) {
    int i = 0;
    int retval = -1;
    struct node *current = *head;
    struct node *temp_node = NULL;

    if (idx == 0) {
        return pop(head);
    }

    for (i = 0; i < idx - 1; i++) {
        if (current->next == NULL) {
            return retval;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return retval;
    }

    temp_node = current->next;
    retval = temp_node->data;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
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
    push_end(head, 4);
    printLinkedList(head);
    push_beginning(&head, 0);
    printLinkedList(head);
    pop(&head);
    printLinkedList(head);
    remove_last(head);
    printLinkedList(head);
    remove_by_index(&head, 1);
    printLinkedList(head);

    return 0;
}
