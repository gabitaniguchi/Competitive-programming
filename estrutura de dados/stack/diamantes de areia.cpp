#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int f=1;f<=n;f++)
	{
		string s;
		cin>>s;
		
		stack <char> d;
		int ans = 0;
		
		for(int i=0;i<(int)s.size();i++)
		{
			if(s[i]=='<') d.push(s[i]);
			else if(s[i]=='>')
			{
				if(d.empty()) continue;
				d.pop();
				ans ++;
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}