#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

node_t* create_node();

void print_linked_list(node_t* head);

int main(void) {
    create_node();
    node_t *temp=NULL, *head=NULL, *ogheadref=NULL;

    //create list head
    if(!(head = create_node())) return (-1);
    ogheadref = head;   /*problem after creating the list is that the original head is lost;
                        **need to store a reference*/

    //create a linked list of 10 elements; head is already created hence loop count -1
    for (int i=0; i<9; )
    {
        if(temp = create_node()) {
            head->next = temp;
            temp->value = ++i;
        } else return(-1);

        head = temp;
    }
    //head is the newest element; its next will be null. Can't use it to print the list

    print_linked_list(ogheadref); 

    return 0;
}

node_t* create_node() {
    node_t *new = NULL;
    if(new = (node_t*) malloc(sizeof(node_t)))
    {
        new->value = 0;
        new->next = NULL;
    }
    return new;
}

void print_linked_list(node_t* head) {
    int i = 0;
    if(!head) {
        printf("list empty\n");
    } else {
        while(head) {
            printf("no. %d -> val: %d\n", ++i, head->value);
            head = head->next;
        }
    }
}


