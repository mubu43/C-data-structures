#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *left;  //left subtree
    struct node *right; //right subtree
} node_t;   //represents a node in the tree

node_t* create_node(int value);

bool insert_node(node_t *root, int value);

void print_tree(node_t *root);

int main(void) {
    node_t *root = create_node(5);
    if(root) {
        insert_node(root, 3);
        insert_node(root, 8);
        insert_node(root, 2);
        insert_node(root, 7);
        insert_node(root, 9);

        print_tree(root);

    } else {
        printf("root could not be created\n");
        return (-1);
    }
}

node_t* create_node(int value) {
    node_t *new = (node_t *)malloc(sizeof(node_t));
    if(new) {
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else
        return NULL;
}

//insert a node in the tree with the provided value, return ???
bool insert_node(node_t *root, int value) {
    
    if (!root) {
        //the tree is empty
        //create a new node
        //the new node created will become the root of the tree
        node_t *new = create_node(value);
        if(!new)
            return false;
        root = new;
        return true;
    } else if (value < root->value) {     
        //insert the node somewhere in the left subtree of the root
        return (insert_node(root->left, value));
    } else {
        //insert the node somewhere in the right subtree of the root
        return (insert_node(root->right, value));
    }
}

//print the tree
void print_tree(node_t *root) {
    if(!root) {
        printf("tree is empty!\n");
        return;
    } else {
        printf("%d\n", root->value);
        print_tree(root->left);
        print_tree(root->right);
    }
}