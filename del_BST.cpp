#include <iostream>
using namespace std;

//program for deleting a node in BST
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

BSTNode* findmin(BSTNode* root)
{
	BSTNode* temp = root;
	while(temp->left!= NULL)
	{
		temp = temp->left;}

void del(BSTNode* root, int data)
{
	if(node == NULL) return;
	else if(data < root->data) root->left = del(root->left, data);
	else if(data > root->data) root->right = del(root->right, data);
	else
	{
	 //No child
		if((root->right == NULL)&&(root->left == NULL))
		{
			delete root;
			root = NULL;
			return root;
		}
		
		//one left child
		if(root->right == NULL)
		{
			delete root;
			root = root->left;
			return root;
		}
		
		//one right chilc
		if(root->left == NULL)
		{
			delete root;
			root = root->right;
			return root;
		}
		
		
	}
	
	
	}



int main() {
	BSTNode* root = NULL;
	insert(&root, 4);
	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);	
	insert(&root, 5);
	insert(&root, 6);
	

  return 0;
}

