#include <bits/stdc++.h>

using namespace std;

int main()
{
	char k[55];
	string risada;
	
	scanf("%s", k);
	
	for(int i=0;i<strlen(k);i++)
	{
    	if(k[i]=='a'||k[i]=='e'||k[i]=='i'||k[i]=='o'||k[i]=='u') risada += k[i];
	}

	int b = 0, e = (int)risada.size()-1, ans=0;
	
	for(int i=0;i<(int)risada.size();i++)
	{
		if(risada[b]!=risada[e]) ans = -1;
		
		b++;
		e--;
	}
	
	if(ans==0) printf("S\n");
	else printf("N\n");
	
	return 0;
}