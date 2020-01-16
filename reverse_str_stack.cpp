#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

//program for reversing a string using stack from C++ STL
void reverse(char* A, int n)
{
	stack<char> S;
	
	for(int i = 0; i < n; i++)
	{
		S.push(A[i]);
	}
	
	for(int i = 0; i < n; i++)
	{
		A[i] = S.top();
		S.pop();
	}
}

int main()
{
	char A[10] = "MASTAN";
	reverse(A, strlen(A));
	printf("%s", A);
	return 0;
}
