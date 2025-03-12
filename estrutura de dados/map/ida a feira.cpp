#include <bits/stdc++.h>

using namespace std;

int main()
{
  map<string, float> comp; 

  int n;
  scanf("%d", &n);

  for(int i=1;i<=n;i++)
  {
      int p,c,q; // produtos, comprados e quantidade
      string s;
      float v, total=0;
      
      scanf("%d", &p);

      for(int j=0;j<p;j++)
        {
          cin>>s>>v;

          comp[s] = v;
        }

      scanf("%d",&c);

      for(int j=0;j<c;j++)
        {
          cin>>s>>q;

          total += comp[s]*q;
        }

      printf("R$ %.2f\n", total);
  }


  return 0;
}