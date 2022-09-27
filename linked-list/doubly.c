#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node_t;

node_t* create_node();
void print_linked_list_using_tail(node_t* tail);

int main(void) {
    node_t *head, *tail, *temp;

    //create list head
    head = create_node();

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
    //head will be used as tail here since that is what it effectively represents
    print_linked_list_using_tail(head); //no need to store head reference here; although it will be helpful to keep a reference

    //delete first occurence of node with ith value


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
            tail = tail->prev;
        }
    }
}