typedef struct _info{
    int id;
    char *name, *department;
    float average;
}info;

typedef struct _ListNode{
    info* data;
    struct _ListNode *next;
}ListNode;

typedef struct _TreeNode{
    ListNode* nodeptr;
    struct _TreeNode *left, *right;
}TreeNode;

TreeNode* addToTree(TreeNode* root, ListNode* list_node);

void add(TreeNode** root, ListNode** first, info* data);

void searchById(TreeNode* root, int id);

void displayByList(ListNode* first);

void displayBySortedTree(TreeNode* root);

void freeMemory(TreeNode* root, ListNode* first);

void saveToFile(ListNode* first);

void loadFromFile(ListNode** first, TreeNode** root);

void sequentialSearch(ListNode* first, int id);