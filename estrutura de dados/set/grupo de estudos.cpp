#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a;
	scanf("%d", &n);
    set<int>alunos;
    
    for(int i=1;i<=n;i++)
    {
    	scanf("%d", &a);
    	
    	alunos.insert(a);
	}
	
	printf("%d\n", alunos.size());
	
	return 0;
}