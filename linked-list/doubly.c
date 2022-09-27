#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node_t;

node_t* create_node();
void print_linked_list_using_tail(node_t* tail);
int remove_node_with_value(int value, node_t *tail);

int main(void) {
    node_t *head, *tail, *temp;
    int value;

    //create list head
    head = create_node();

    //storing original head as after creating the list, it will be pushed to the deepest end of the list and will effectively represent the tail.
    tail = head;

    //create list of n elements
    for (int i=0; i<9; ) {
        if(temp = create_node())
        {
            head->next = temp;
            temp->prev = head;
            temp->value = ++i;
        } else {
            printf("list could not be created\n");
            return (-1);
        }

        head = temp;
    }

    //print created list    
    print_linked_list_using_tail(tail); //no need to store reference ptr here to print the list; although it will be helpful to keep a reference

    //delete first occurence of node with ith value
    value = 9;
    value = remove_node_with_value(value, tail);    //original head was pushed to the deepest end of the list. 
    if (!value) {
        printf("removed element! printing list again:- \n");
        print_linked_list_using_tail(tail);
    } else {
        printf("elemenet not found\n");
    }
    return 0;
}

node_t* create_node() {
    node_t *new = NULL;
    if(new = (node_t*) malloc(sizeof(node_t)))
    {
        new->value = 0;
        new->next = NULL;
        new->prev = NULL;
    }
    return new;
}

void print_linked_list_using_tail(node_t* tail) {
    int i = 0;
    if(!tail) {
        printf("list empty\n");
    } else {
        while(tail) {
            printf("no. %d -> val: %d\n", ++i, tail->value);
            tail = tail->next;
        }
    }
}

int remove_node_with_value(int value, node_t *tail) {
    while(tail) {
        if(tail->value == value) {
            tail->next->prev = tail->prev;
            tail->prev->next = tail->next;
            free(tail);
            return (0);
        }
        tail = tail->next;
    }

    return (-1);
}