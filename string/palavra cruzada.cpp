#include <bits/stdc++.h>

using namespace std;

int main()
{
    string palavra1, palavra2;
    int cruzamento1=0, cruzamento2=0, tam1, tam2;
    int quebra = 0;
    
    cin>>palavra1>>palavra2;
    
    tam1 = (int)palavra1.size() - 1;
    tam2 = (int)palavra2.size() - 1;
    
    for(int i=tam1;i>=0;i--)
    {
        for(int j=tam2;j>=0;j--)
        {
            if (palavra1[i] == palavra2[j] ) 
            {
                cruzamento1 = i+1;
                cruzamento2 = j+1;
                quebra = 1;
                break;
            }
           
        }
      if (quebra == 1) break;
    }
    
    if(quebra == 0 ) printf("-1 -1\n");
    
    else printf("%d %d\n", cruzamento1, cruzamento2);
    
    return 0;
    
}