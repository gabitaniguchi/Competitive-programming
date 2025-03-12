#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++)
	{
		string s;
		int ans = 0;
		cin>>s;
		stack <char> pilha;
		
		for(int j=0;j<(int)s.size();j++)
		{	
		    if(s[j]=='(' || s[j]=='[' || s[j]=='{') 
			{
			  pilha.push(s[j]);
			  continue;	
			}
			
			if(pilha.empty()) 
			{
			   	  ans = -1;
			   	  break;
			}
			   
		    else
            {      
			   char x = pilha.top();
		       
			   if(x=='(' && s[j]==')') pilha.pop();
		       else if (x=='[' && s[j]==']') pilha.pop();
		       else if (x=='{' && s[j]=='}') pilha.pop();
		       
		       else 
			   {
			   	  ans = -1;
			   	  break;
			   }
            }
		}
		
		if(!pilha.empty()) ans = -1;
		
		if(ans==-1) printf("N\n");
		else printf("S\n");
	}
	
	return 0;
}