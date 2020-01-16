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

bool search(BSTNode* root, int data)
{
	if(root == NULL) return false;
	else if(data == root -> data) return true;
	else if(data <= root -> data) return search(root ->right, data);
	else return search(root->right, data);		
}

int main() {
	BSTNode* root = NULL;
	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 5);
	insert(&root, 6);
	if(search(root, 9))
		cout << "yes" << endl;
	
	

  return 0;
}
