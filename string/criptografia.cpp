#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	cin.ignore();
	
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		int tam = (int)s.size();
		int end = tam-1;
		
		for(int j=0;j<tam;j++) 
		{
	    	if (s[j]>='A'&&s[j]<='Z') s[j] += 3;
		    if (s[j]>='a'&&s[j]<='z') s[j] += 3;
		}

		for(int j=0;j<=tam/2;j++)
		{
			if(j == tam/2 && tam%2==0) break;
			int temp = s[end];
			s[end] = s[j];
			s[j] = temp;
			end--;
		}

		for(int j=tam/2;j<tam;j++) s[j] -= 1;
		
		cout<<s<<"\n";
	}
	
	return 0;
}