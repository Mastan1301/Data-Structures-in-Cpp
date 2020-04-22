// Implementation of disjoint set/ union-find using arrays

#include<bits/stdc++.h>
using namespace std;

int find(int a[],int x);
void unionSet(int a[],int x ,int z);

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}

int findPar(int parent[], int x)
{
    if(parent[x] == x) return x;

    parent[x] = findPar(parent, parent[x]);
    return parent[x];
}

void Union(int parent[], int x, int z){
    int parX = findPar(parent, x), parZ = findPar(parent, z);

    if(x != z){
        parent[parZ] = parX;
    }
}