#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

node_t* create_node();
void print_linked_list(node_t* head);
node_t* remove_element_with_specific_value(int value, node_t *head);    //deletes first occurence. returns new list head

int main(void) {
    create_node();
    node_t *temp=NULL, *head=NULL, *ogheadref=NULL, *dellisthead=NULL;
    int value;

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

    //delete element with value
    value = 5;
    dellisthead = remove_element_with_specific_value(value, ogheadref);
    if(!dellisthead) {
        printf("element not found\n");
    } else {
        printf("element with value %d removed!\nprinting new list:-\n", value); 
        print_linked_list(dellisthead); 
    }
        

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

node_t* remove_element_with_specific_value(int value, node_t *head) {
    node_t *delNode = NULL, *temp=NULL;
    if(head->value == value)
    {
        temp = head->next;
        free(head);
        return(temp);  
    }

    temp = head;

    while(head->next) {                 //must loop with head->next since accessing head->next without knowing it is NULL may cause segfault
        if(head->next->value == value)  //need to reach the previous element and set its pointer to head's next
        {
            delNode = head->next;
            head->next = head->next->next;
            free(delNode);
            break;
        }
        head = head->next;
    }

    if(!(head->next))           //element not found in the list
        return NULL;
    else                        //some element was found in the middle and hence deleted
        return temp;
}