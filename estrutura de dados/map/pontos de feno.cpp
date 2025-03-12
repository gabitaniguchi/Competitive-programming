#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,x,p;
  string s,pal,temp;
  map <string,int> dic;

  scanf("%d%d", &n, &x);

  for(int i=1;i<=n;i++)
  {
    cin>>s>>p;

    dic[s] = p;
  }

  cin.ignore();
  int ans=0,v=0;
   
  while(true)
  {
    getline(cin,temp);
    if(temp != ".")
    {
      for(int j=0;j<(int)temp.size();j++)
      {
          if(temp[j]==' ') 
          {
            ans += dic[pal];
            pal = "";
          }
            
          else if(j==(int)temp.size()-1)
          {
            pal += temp[j];
            ans += dic[pal];
            pal = "";
          }
                    
          else  pal += temp[j];
      }
    }

    else
    {
       printf("%d\n",ans);
       ans = 0;
       v++;
    }

    if(v==x) break;

  }
  
  return 0;
}