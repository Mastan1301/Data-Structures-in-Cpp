#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

class Queue
{
	public:
		Node* front, *rear;

		bool is_empty()
		{
			if((front == NULL) && (rear == NULL))
				return true;
			return false;
		}

		void enqueue(int new_data)
		{
			Node* new_node = new Node();
			new_node->data = new_data;
			new_node->next = NULL;
			if(is_empty())
			{
				front = rear = new_node;
				//rear = new_node;
				return;
			}

			rear->next = new_node;
			rear = new_node;
			return;
		}

		void dequeue()
		{
			if(is_empty())
			{
				cout << "Empty queue." << endl;
				return;
			}
			else if(front == rear)
			{
				front = rear = NULL;
				//rear = NULL;
				return;

			}

			front = front->next;
			return;

		}

		void print()
		{
			if(is_empty())
			{
				cout << "Empty queue." << endl;
				return;
			}
			Node* temp = front;
			while(temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};

int main()
{
	Queue q;
	q.front = NULL;
	q.rear = NULL;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.dequeue(); q.dequeue(); q.dequeue();
	q.print();
	return 0;
}
