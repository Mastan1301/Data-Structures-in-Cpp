#include <iostream>
#include <queue>
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

void level_t(BSTNode* root) //level-order traversal
{
	if(root == NULL) return;
	queue <BSTNode*> Q;
	Q.push(root);
	
	while(!Q.empty())
	{
		BSTNode* current = Q.front();
		cout << current ->data << endl;
		
		if(current -> left != NULL) Q.push(current -> left);
		if(current -> right != NULL) Q.push(current -> right);
		Q.pop();
	}
}

void pre_t(BSTNode* root) //pre-order traversal
{
	if(root == NULL) return;
	cout << root->data << " ";
	
	pre_t(root->left);
	pre_t(root -> right);
}

void in_t(BSTNode* root) //in-order traversal
{
	if(root == NULL) return;
	in_t(root->left);
	cout << root -> data << " ";
	in_t(root -> right);
	
}

void post_t(BSTNode* root) //post-order traversal
{
	if(root == NULL) return;
	
	post_t(root->left);
	post_t(root -> right);
	cout << root->data << " ";
}

int main() {
	BSTNode* root = NULL;
	insert(&root, 4);
	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 5);
	insert(&root, 6);
	level_t(root);
	/*pre_t(root);
	in_t(root);
	post_t(root);*/

  return 0;
}

