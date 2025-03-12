#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++)
	{
		string cifra;
		int x;
		cin>>cifra>>x;
		
		for(int j=0;j<(int)cifra.size();j++)
		{
			cifra[j] -= x;
			if(cifra[j]<65) cifra[j] += 26;
		}
		
		cout<<cifra<<"\n";
	}
	
	return 0;
}