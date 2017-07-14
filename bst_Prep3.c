//abdul
//null root (special)  
//base case: root -> left == NULL and root -> right == NULL ???
//4 cases?
//SUUCCCCCESSSSSSSSSSSS~~~~

//Find the minimum depth of a bst (shortest distance from root node to leaf node)
int find_min_depth(Node* root) { 
   if(root->left == NULL && root->right == NULL) 
     return 1;
   if(root == NULL)
      return 0;
  
  int left = find_mind_depth(root->left) + 1 
  int right = find_mind_depth(root->right) + 1
  
  if(root->left != NULL && root->right == NULL)
  	return left
  
  if (root->right != NULL && root->left == NULL)
    return right 
     
  if (root->left && root->right)
  	return min(left, right) + 1
	
}
                                   
