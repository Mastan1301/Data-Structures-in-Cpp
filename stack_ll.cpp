#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};

class stack1
{
	public:
		void push_node(Node** head, int new_data, int* top)
		{
			(*top)++;
			Node* new_node = new Node();
			new_node -> data = new_data;
			new_node->next = (*head);
			(*head) = new_node;
		}
		
		bool is_empty(Node** head)
		{
			if(*head == NULL)
			{
				cout << "The stack is empty." << endl;
				return true;
			}
			cout << "The stack is non-empty." << endl;
			return false;
		}
		
		inline void top(Node* head)
		{
			cout << "The top element is " << head->data << endl;
		}
		
		void pop(Node** head, int* top)
		{
			(*head) = (*head)->next;
			(*top)--;
		}
		
		void print(Node* head, int top)
		{
			Node* temp = head;
			int* t1 = new int[top+1];
			int i = 0;
			
			while(temp != NULL)
			{
				t1[i] = temp->data;
				temp = temp->next;
				i++;
			} 
			
			for(int i = top; i >= 0; i--)
				cout << t1[i] << " ";
			
			cout << endl;
			
			return;
		}
};

int main()
{
	Node* head = NULL;
	stack1 s;
	int top = -1;
	
	s.push_node(&head, 1, &top);
	s.push_node(&head, 2, &top);
	s.push_node(&head, 3, &top);
	s.push_node(&head, 4, &top);
	s.push_node(&head, 5, &top);
	s.top(head);
	s.pop(&head, &top);
	s.print(head, top);
	return 0;
}

