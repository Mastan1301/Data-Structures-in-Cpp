#include <iostream>
using namespace std;
#define MAX 101

class stack1
{
	public:
		void push(int* A, int* top, int data);
		void top(int* A, int top);
		bool is_empty(int top);
		void pop(int* A);
		void print(int* A, int top);
};
	
void stack1::push(int* A, int* top, int data)
{
	(*top)++;
	*(A+(*top)) = data;
}

void stack1::top(int* A, int top)
{
	if(top == -1)
	{
		cout << "The stack is empty." << endl;
		return;
	}
		
	cout << "The top element is " << *(A+top) << endl;
}
	
bool stack1::is_empty(int top)
{
	if(top == -1)
	{	
		cout << "The stack is empty" << endl;
		return true;
	}
	cout << "The stack is non-empty" << endl;
	return false;
}

void stack1::pop(int* top)
{
	(*top)--;
}
	
void stack1::print(int* A, int top)
{
	for(int i = 0; i <= top; i++)
		cout << *(A+i) << " ";
	cout << endl;	
}
	
int main()
{
	stack1 s;
	int A[MAX];
	int top = -1;
	
	s.push(A, &top, 1);
	s.push(A, &top, 2);
	s.push(A, &top, 3);
	s.push(A, &top, 4);
	s.push(A, &top, 5);
	s.is_empty(top);
	s.top(A, top);
	s.print(A, top);
	s.pop(&top);
	s.top(A, top);
	s.print(A, top);
	
	return 0;
}
	
		
		
	
