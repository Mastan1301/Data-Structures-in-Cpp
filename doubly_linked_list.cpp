#include <iostream>
using namespace std;

class Node
{
	public:
	Node *prev;
	int data;
	Node *next;
};

void push(Node** head_ref, int new_data) //adding element from the first
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node -> prev = NULL;
	new_node->next = (*head_ref);
	(*head_ref)->prev = new_node;
}

void insert_after(Node* prev_node, int new_data) //adding element after a node
{
	if(prev_node == NULL)
	{
		cout << "The previous node cannot be null." << endl;
		return;
	}
	Node* new_node = new Node();
	new_node -> data = new_data;
	new_node -> next = prev_node -> next;
	new_node->prev = prev_node;
	(prev_node->next)->prev = new_node;
	prev_node -> next = new_node;
}

void append(Node** head_ref, int new_data) //appending element to the last node
{
	Node* new_node = new Node();
	new_node -> data = new_data;
	new_node -> next = NULL;
	if(*head_ref == NULL)
	{
		new_node -> prev = NULL;
		*head_ref = new_node;
		return;
	}
	
	Node* last = *head_ref;
	
	while(last->next != NULL)
	{
		last = last -> next;
	}
	new_node -> prev = last;
	last->next = new_node;
	return;
}

void delete_node(Node* node)
{
	if(node == NULL)
	{
		cout << "No nodes present to delete.";
		return;
	}
	
	(node->prev)->next = node->next;
	(node->next)->prev = node->prev;
}	
	
		
void printlist(Node* node) //printing the list
{
	while(node != NULL)
	{
		cout << node -> data << " ";
		node = node -> next;
	}
	return;
}

void invert(Node** head_ref)
{
	Node* curr = *head_ref;
	Node* prev = NULL;
	Node* next1 = NULL;
	
	while(curr != NULL)
	{
		next1 = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next1;
	}
	*head_ref = prev;
	return;
}
	
int main()
{
	Node* head = NULL;
	
	append(&head, 1);
	//push(&head, 2);
	//push(&head, 3);
	//push(&head, 4);
	//append(&head, 5);
	insert_after(head, 3);
	printlist(head);
	cout << endl;
	delete_node(head->next);
	printlist(head);

	return 0;
}

