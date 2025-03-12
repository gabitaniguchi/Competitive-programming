#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m, t1,t2;
	
	scanf("%d%d", &n, &m);
	
	map<int, int> p;
	map<int, int> ans;
	set<int> chaves;
		
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d", &t1, &t2);
		
		p[t1] = t2;
	}
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d", &t1, &t2);
		
		if(p[t1] < t2)
		{
			ans[t1] = t2;
			p[t1] = t2;
			chaves.insert(t1);
		}
		
	}
	
	set<int>::iterator it;
	
	for(it=chaves.begin();it!=chaves.end();it++)
	{
		printf("%d %d\n", *it, ans[*it]);
	}
	
	return 0;
}