/*
    Implementation of basic operations in a binary min-heap using an array.
*/

#include <bits/stdc++.h>
#define MAX (int)(pow(10, 9)+1)
using namespace std;

static int s = 0;

void printMin(int* arr)
{
    cout << arr[0] << endl;
}

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void heapify(int* arr, int n)
{
    if(n < 1)
        return;

    while(n > 0)
    {
        if(*(arr+((n-1)/2)) > *(arr+n))
        {
            swap(arr+((n-1)/2), arr+n);
        }
        n--;
    }
}

void insertNode(int* arr, int k)
{
    arr[s] = k;
    s++;
    int n = s-1;
    while(n > 0) 
    {
        if(*(arr+((n-1)/2)) > *(arr+n))
        {
            swap(arr+((n-1)/2), arr+n);
        }
        n = (n-1)/2; //no need to heapify all the nodes.
    }   
}

void deleteNode(int* arr, int k)
{
    for(int i = 0; i != s; i++)
    {
        if(arr[i] == k)
        {
            arr[i] = arr[s-1]; //replace the node to be deleted with the last element.
            break;
        }
    }
    s--; //removing the last element
    heapify(arr, s-1);
}

int main()
{
    int q; //no. of queries
    cin >> q;
    int* arr = new int[q];

    while(q--) //queries
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            int k;
            cin >> k;
            insertNode(arr, k);            
        }

        else if(n == 2)
        {
            int k;
            cin >> k;
            deleteNode(arr, k);
        }

        else
        {
            printMin(arr);
        }        
    }

    return 0;
}