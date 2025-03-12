#include <iostream>

using namespace std;

int soma_vetor(int n, int v[], int s, int i){
	s=0;
	for(i=0;i<n;i++)
	{
	    s+=v[i];
	}
	return s;
}

int main(){
	
	int n,i,s, v[100100];
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> v[i];

	cout << soma_vetor(n,v,i,s) << "\n";
}