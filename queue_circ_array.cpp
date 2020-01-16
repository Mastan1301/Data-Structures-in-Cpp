#include <iostream>
using namespace std;
#define size 10

//implementation of queue using circular array
class Queue
{
	public:
		int front, rear;
		int A[size];
		
		bool is_full()
		{
			if((rear+1) % size == front)
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
				rear = (rear+1)%size;
				
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
			
			front = (front+1)%size;
			return;
		}
		
		int front1()
		{
			return A[front];
		}
		
		void print()
		{
			if(is_empty())
			{
				cout << "Queue is empty." << endl;
				return;
			}
			
			for(int i = 0; i <= size-1; i++)
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
	q.dequeue(); q.dequeue(); q.dequeue();
	for(int i = 7; i < 14; i++)
		q.enqueue(i);
	q.print();
	
	return 0;
}
	
	

