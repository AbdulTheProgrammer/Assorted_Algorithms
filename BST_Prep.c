//
//  BST_Prep.c
//  
//
//  Created by Abdulhadi Mohamed on 2017-07-10.
//
//

#include <stdio.h>
// algorithm for generating bst out of assending ordered linked list

BSTnode* generateBST(node* root, int size){
    if(size <= 1){
        return BSTnode* node->value = root->value;
    }
    
    //get to middle node
    BSTnode* mid;
    mid = reachNode(root, size/2);
    //mid at middle node
    
    mid->left = generateBST(root, size/2);
    mid->right = generateBST(mid, size/2);
}

node{
    next;
    value;
}

BSTNode* reachNode(node* root, int size){
    
    BSTNode* finalNode = new BSTNode;
    
    //
    // finalNode = (node_t)malloc(sizeof(node_t))
    //or  malloc(sizeof(BSTNode));
    for(int i = 0; i < size; i++){
        root = root->next;
    }
    finalNode->value = root->value;
    return finalNode;
}

create node = [mem; value:]

void inOrder(Node* n) {
    if(n != NULL) {
        inOrder(n->left);
        visit(n); //arbitrary visit function
        inOrder(n->right);
    }
}

void breadthFirst(Node* n) {
    queue<Node*> q;
    if(n == NULL)
        return;
    q.enqueue(n);
    while(!queue.empty()) {
        Node* n = q.dequeue();
        visit(n);
        
        if(n->left != NULL)
            q.enqueue(n->left)
            if(n->right != NULL)
                q.enqueue(n->right)
                }
}


void preorder(Node* root) {
    if (root != NULL){
        print(root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

void post_order(Node* root){
    
    if(root != NULL) {
        post_order(root->left);
        post_order(root->right);
        visit(root); //arbitrary visit function
        
    }
}


// bst = has to have only two daughters
//WRRRRROONNNNNNNGGGG
bool check_bst(node_t* root){
    if (root == NULL) return true;
    
    if (root->left != NULL){
        return root->left->val < root->val;
    }
    if (root->right!=NULL){
        return root->right->val > root->val;
    }
    return check_bst(n->left) && checkBST(n->right);
}

//proprr implementation using min/max value
bool check_bst(node_t* root) {
    if(root == NULL)
        return true;
    if(root->left != NULL && maxValue(root->left, root->left->val) > root->val)
        return false;
    if(root->right != NULL && minValue(root->right, root->right->val) < root->val)
        return false;
    
    if (check_bst(root->left) &&  check_bst(root->right))
        return true;
    
    return false
    
}

struct node{
    struct node* right;
    struct node* left;
    int val;
};

void createNode()
base function
5 maxVAl(4,5) max 5
4 (()) max 3000
3000 maxValue (3000, 3000)


//how!!?!?!  somehow...
int maxValue(node_t* root, int max){
    if (root->left!=NULL){
        if (root->left->val > max)
            max = root->left->val; //return this
        return maxValue(root->left, max); // not matter what this is, since its not being capturesd
    }
    if (root->right!=NULL){
        if(root->right->val > max)
            max = root->right->val;
        return maxValue(root->right, max);
    }
    return max;
}

//in actual function
int * max = root->left->value
maxValue(root->left,max)

//just a normal traversal, nothing to see here
void maxValue(node_t* root, int * max) {
    
    *max = max(*max, root->value);
    
    if (root->left!=NULL){
        maxValue(root->left, max);
    }
    if (root->right!=NULL){
        maxValue(root->right, max);
    }
}

/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* right;
    struct node* left;
}node_t;

int maxValue(node_t* root, int max){
    if (root->left!=NULL){
        if (root->left->val > max)
            max = root->left->val; //return this
        max = maxValue(root->left, max); // not matter what this is, since its not being capturesd
    }
    if (root->right!=NULL){
        if(root->right->val > max)
            max = root->right->val;
        max =  maxValue(root->right, max);
    }
    return max;
}

node_t* new_node (int data){
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root->val = data;
    root->right = root->left = NULL;
    return root;
}

int main()
{
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root = new_node(1);
    root->right = new_node(3);
    root->right->right = new_node(56);
    root->right->right->left = new_node(58);
    root->left = new_node(2);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->left->right->right = new_node(1000);
    
    int v = maxValue(root->right, root->right->val);
    printf("VALUEEE: %i", v);
    return 0;
}

/////////////////////////////////////////////////////////////////////////
/*
	1. Convert a binary search tree to a sorted double-linked list.
 We can only change the target of pointers, but cannot create any new nodes.
 
	2. Check if given binary Tree has symmetric structure or not
 */
//////////////////////////
////////////////////////////////////////



brainstorm

5
2     7				1  2  5  6  7  9  10
1      6   9
10




- Do inorder traversal
left
visit
->
right

///////SHARIF
node_t* convert_to_DLL(node_t* root)
{
    //keep going till you get the left most node
    if (root->left!=NULL)
    {
        node_t* left = convert_to_DLL(root->left);
        
        //find the right most of the left most node
        while (left->right!=NULL) left = left->right;
        
        left->right = root;
        root->left = left;
    }
    
    //keep going till you get the right most node
    if (root->right!=NULL)
    {
        
        node_t* right = convert_to_DLL(root->right);
        
        //find the left-most of the right most node
        while (right->left!=NULL) right = right->left;
        
        right->left = root;
        root->right = right;
    }
    return root;
}

////////////////////////////ABDULHADI FROM HERE

convert_to_DLL (node_t* root) { //ABDULHADI
    node_t* tail = convert_to_DLL_helper(root, NULL);
    
    //create the second link maybe? and get head
    
    return head
}

node_t* convert_to_DLL_helper(node_t* root, node_t** prev)
{
    
    if(root->left != NULL)
        convert_to_DLL_helper(root, prev);
    
    if(prev != NULL){
        prev->right = root;
    }
    *prev = root;
    
    if(root->right != NULL)
        convert_to_DLL_helper(root, prev);
    
}


///////////////////////////////
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* right;
    struct node* left;
}node_t;

node_t* convert_to_DLL(node_t* root)
{
    if (root->left!=NULL)
    {
        node_t* left = convert_to_DLL(root->left);
        
        //while (left->right!=NULL) left = left->right;
        
        left->right = root;
        root->left = left;
    }
    
    if (root->right!=NULL)
    {
        node_t* right = convert_to_DLL(root->right);
        
        //while (right->left!=NULL) right = right->left;
        
        right->left = root;
        root->right = right;
    }
    return root;
}


int maxValue(node_t* root, int max){
    if (root->left!=NULL){
        if (root->left->val > max)
            max = root->left->val; //return this
        max = maxValue(root->left, max); // not matter what this is, since its not being capturesd
    }
    if (root->right!=NULL){
        if(root->right->val > max)
            max = root->right->val;
        max =  maxValue(root->right, max);
    }
    return max;
}

node_t* new_node (int data)
{
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root->val = data;
    root->right = root->left = NULL;
    return root;
}

int main()
{
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root = new_node(500);
    root->left = new_node(200);
    root->right = new_node(700);
    root->left->left = new_node(100);
    root->right->left = new_node(600);
    root->right->right = new_node(900);
    root->right->right->right = new_node(1000);
    root->left->left->right = new_node(150);
    root->left->left->right->left = new_node(120);
    root->left->right = new_node(300);
    
    root = convert_to_DLL(root);
    //printf("Value: %i", root->val);
    
    while (root->left!=NULL) root = root->left;
    while (root!=NULL){
        printf("Value: %i\n", root->val);
        root = root->right;
    }
    return 0;
}

///Abdul's implementation


1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7


4
2

TreeNode* convert_LL(Node *root) {
    if(root == NULL)
        return NULL;
    
    TreeNode* root = NULL;
    Node* tail = getTail(root);
    helper(root, tail, root ,&root)
    
    return root;
}

void helper(Node* head, Node* tail, TreeNode *next ,TreeNode** root) {
    
    int size = get_size(head, tail);
    if(size == 1) {
        attachNode(next, head, root);
    }
    else {
        Node* mid = get_mid(head, tail);
        attachNode(next, mid, root);
        helper(head, mid->prev, root); //
        helper(mid->next, tail, root);
    }
}



void attachNode(TreeNode* prev, Node* n, TreeNode** root) {
    if(*root == NULL)
        *root = new TreeNode(n->val)
        else {
            if(prev->val > mid->val)
                prev->left = new TreeNode(mid->val);
            else
                prev->right = new TreeNode(mid->val);
        }
}

void get

///////// Convert Sorted Linked list to balanced BST






/// ABHISHEK'S GOWDLY ANSWER:


BST** convertList(Node* h, Node* t, BST* head){
    //base case:
    int size = getsize(n);
    if(size == 1){
        BST* node = new Node();
        node->data =  h->data;
        return node;
    }
    
    Node mid = h;
    
    //navigate to middle node
    for(int i = 0; i < size/2; i++){
        mid = mid->next;
    }
    head->data = mid->data;
    //call left side and call right side
    
    head->left = convertList(h, mid, head);
    head->right = convertList(mid->next, t, head);
    
    return head;
}






















