#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	
	while( getline(cin,s))
	{
 	    
		int m = 0;
		
		for(int i=0; i<(int)s.size();i++)
		{
			if(s[i] == ' ') continue;
			
			if(m%2==0) s[i] = toupper(s[i]);
			else if(m%2==1) s[i] = tolower(s[i]);
			
			m++;
		}
		
		cout<<s<<endl;
	}
	
	return 0;
}