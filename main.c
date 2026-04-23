#include <stdio.h>
#include "declarations.h"

int main(void){

    ListNode* first = NULL;
    TreeNode* root = NULL;

    loadFromFile(&first, &root);

    printf("Sequential display:\n");
    displayByList(first);

    printf("Sorted display:\n");
    displayBySortedTree(root);

    searchById(root, 23);
    searchById(root, 4);
    
    info data1 = {5, "ali", "gl", 14.5};
    add(&root, &first, &data1);
    
    info data2 = {5, "mohammed", "gl", 14.5};
    add(&root, &first, &data2);

    saveToFile(first);

    freeMemory(root, first);

    return 0;
}