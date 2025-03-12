#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, temp, ans = 0;
	scanf("%d", &n);
	set<int>tacos;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &temp);
		
		if(tacos.find(temp)==tacos.end()) 
		{
			ans += 2;
			tacos.insert(temp);
		}
		else tacos.erase(temp);	
	}
	
	printf("%d\n", ans);
	
	return 0;
}