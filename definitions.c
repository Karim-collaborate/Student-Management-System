#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "declarations.h"


void add(TreeNode** root, ListNode** first, info* data){

    ListNode* current = *first;
    while(current && current->data->id != data->id){
        current = current->next;
    }
    if(!current){
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->data = data;
        new_node->next = *first;
        *first = new_node;
        *root = addToTree(*root, new_node);
    } 
}

TreeNode* addToTree(TreeNode* root, ListNode* new_list_node){
    if(!root){
        TreeNode* new_node = malloc(sizeof(TreeNode));
        new_node->nodeptr = new_list_node;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }else if(new_list_node->data->id < root->nodeptr->data->id){
        root->left = addToTree(root->left, new_list_node);
    }else if(new_list_node->data->id > root->nodeptr->data->id){
        root->right = addToTree(root->right, new_list_node);
    }
    return root;
}

void searchById(TreeNode* root, int id){
    if(!root){
        printf("Id %d not found.\n", id);
        return;
    }else if(root->nodeptr->data->id == id){
        printf("%d , %s , %s , %.2f .\n", root->nodeptr->data->id, root->nodeptr->data->name, root->nodeptr->data->department, root->nodeptr->data->average);
        return;
    }else if(id < root->nodeptr->data->id){
        searchById(root->left, id);
    }else{
        searchById(root->right, id);
    }
}

// display by insertion order 
void displayByList(ListNode* first){
    if(first){
        displayByList(first->next);
        printf("%d , %s , %s , %.2f .\n", first->data->id, first->data->name, first->data->department, first->data->average);
    }
}

void displayBySortedTree(TreeNode* root){
    if(root){
        displayBySortedTree(root->left);
        printf("%d , %s , %s , %.2f .\n", root->nodeptr->data->id, root->nodeptr->data->name, root->nodeptr->data->department, root->nodeptr->data->average);
        displayBySortedTree(root->right);
    }
}

// Function to free memory
void freeMemory(TreeNode* root, ListNode* first){
    // Free the tree (post-order)
    if(root != NULL){
        freeMemory(root->left, NULL);
        freeMemory(root->right, NULL);
        free(root);
    }
    
    // Free the list and data
    ListNode* current = first;
    while(current != NULL){
        ListNode* next = current->next;
        free(current->data->name);
        free(current->data->department);
        free(current->data);
        free(current);
        current = next;
    }
}

void saveToFile(ListNode* first){
    FILE* f = fopen("Students.txt","w");
    if(!f) { 
        printf("Error creating file.\n");
        return;
    }
    while(first){
        fprintf(f,"%d;%s;%s;%.2f\n", first->data->id, first->data->name, first->data->department, first->data->average);
        first = first->next;
    }
    fclose(f);
    printf("Export successful.\n");
}

void loadFromFile(ListNode** first, TreeNode** root){
    FILE* f = fopen("Students.txt", "r");
    if(!f){
        printf("Error opening Students.txt\n");
        return;
    }
    char line[256];
    char* token;
    while(fgets(line, sizeof(line), f)){
        
        info* data = malloc(sizeof(info));
        token = strtok(line, ";");
        data->id = atoi(token);

        token = strtok(NULL, ";");
        data->name = strdup(token);

        token = strtok(NULL, ";");
        data->department = strdup(token);

        token = strtok(NULL, "\n");
        data->average = atof(token);

        add(root, first, data);
    }
    fclose(f);
    printf("Loading successful.\n");
}

void sequentialSearch(ListNode* first, int id){
    while(first){
        if(first->data->id == id){
            printf("%d , %s , %s , %.2f .\n", first->data->id, first->data->name, first->data->department, first->data->average);
            break; 
        }
        first = first->next;
    }
    if(!first){
        printf("Id %d not found.\n", id);
    }
}