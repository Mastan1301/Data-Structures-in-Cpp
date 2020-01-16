#include <iostream>
#include <string>
#include <stack>
using namespace std;

//program for checking the balance of paranthesis using stack from C++ STL
char match(char c)
{
	if(c == '(')
		return ')';
	else if(c == '{')
		return '}';
	else if(c == '[')
		return ']';
	return 'c';
}

bool check_par(string A, int n)
{
	stack<char> s;
	
	for(int i = 0; i < n; i++)
	{
		if((A[i] == '(') || (A[i] == '{') || (A[i] == '['))
			s.push(A[i]);
		else if((s.empty()) || (A[i] != match(s.top())))
			return false;
		else
			s.pop();
	}
	
	return s.empty();
}

int main()
{
	string A;
	getline(cin, A);
	if(check_par(A, A.length()))
		cout << "The parentheses are balanced." << endl;
	else
		cout << "Unbalanced parantheses." << endl;
	return 0;
}

