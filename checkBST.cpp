#include <iostream>
using namespace std;

class BSTNode
{
	public:
	  BSTNode* left;
	  int data;
	  BSTNode* right;
};

BSTNode* getnode(int new_data)
{
  BSTNode* new_node = new BSTNode;
  new_node -> data = new_data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

void insert(BSTNode** root, int new_data)
{
  if(*root == NULL)
  {
    *root = getnode(new_data);
    return;
  }
  
  else if(new_data <= (*root)->data)
  {
	  insert(&((*root)->left), new_data);
	  return;
  }
  
  insert(&((*root)->right), new_data);
  return;  
}

bool is_subtree_greater(BSTNode* root, int value)
{
	if(root == NULL) return true;
	
	if((root->data >= value) && (is_subtree_greater(root->left,value)) && (is_subtree_greater(root->right,value)))
		return true;
	return false;
}

bool is_subtree_lesser(BSTNode* root, int value)
{
	if(root == NULL) return true;
	
	if((root->data <= value) && (is_subtree_lesser(root->left,value)) && (is_subtree_lesser(root->right,value)))
		return true;
	return false;
}
	

bool check_bst(BSTNode* root)
{
	if(root == NULL) return true;
	
	if(is_subtree_lesser(root->left, root->data) && is_subtree_greater(root->right, root->data) && check_bst(root->left) && check_bst(root->right))
		return true;
	return false;
}	


int main() {
	BSTNode* root = NULL;
	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 5);
	insert(&root, 6);
	if(check_bst(root))
		cout << "It is a BST." << endl;
	else
		cout << "It is not a BST." << endl;
	
	

  return 0;
}

