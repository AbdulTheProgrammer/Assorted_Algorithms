//
//  BST_Prep_2.c
//  
//
//  Created by Abdulhadi Mohamed on 2017-07-10.
//
//

#include "BST_Prep_2.h"


/*
 ABDUL'S THE INTERVIEWER...
 
 Easier question:
 
 given a bst, create a LL out of all the nodes at each depth (if you have a tree with depth D, you will have D LLs)
 
 */

/* Xx Sharif's sol'n xX */

void pre_order(node* root, int level, vector v){
    if(root==NULL){
        //level--;
        return;
    }
    v[level] = LL;
    insert_into_LL(LL,level, vector v);
    pre_order(root->left, level+1, v);
    pre_order(root->right, level+1, v);
}

/*
 find the next node (inorder successor) of a given node in a BST. you may assume that each node has a link to its parent
 
 i.e. node->parent
 */
node* Node {
    node* left;
    node* right;
    node* parent;
}

void inorder(node* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    visit(root);
    inorder(root->right);
}
