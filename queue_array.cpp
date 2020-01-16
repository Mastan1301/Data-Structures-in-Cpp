#include <iostream>
using namespace std;
#define size 10

//implementation of queue using array
class Queue
{
	public:
		int front, rear;
		int A[size];
		
		bool is_full()
		{
			if(rear == size-1)
				return true;
			return false;
		}
		
		bool is_empty()
		{
			if((front == -1) && (rear == -1))
				return true;
			return false;
		}
		
		void enqueue(int data)
		{
			if(is_full())
			{
				cout << "Queue is full" << endl;
				return;
			}
			if(is_empty())
			{
				front = 0;
				rear = 0;
			}
			else
				rear++;
				
			A[rear] = data;
		}
		
		void dequeue()
		{
			if(is_empty())
			{
				cout << "Queue is empty." << endl;
				return;
			}
			
			else if(front == rear)
			{
				front = -1;
				rear = -1;
				return;
			}
			
			front++;
			return;
		}
		
		void print()
		{
			if(is_empty())
			{
				cout << "Queue is empty." << endl;
				return;
			}
			
			for(int i = front; i <= rear; i++)
				cout << A[i] << " ";
			cout << endl;
		}
		
};

int main()
{
	Queue q;
	q.front = -1;
	q.rear = -1;
	q.is_empty();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.print();
	q.dequeue();
	q.dequeue();
	q.print();
	
	return 0;
}
	
	
