#include <bits/stdc++.h>

using namespace std;

int main()
{
  int f,c;
  scanf("%d%d", &f, &c);
  
  int tenho[c], falta = f;
  
  for(int i=0;i<c;i++)
  {
      scanf("%d", &tenho[i]);
  }
  
  if(c==1) falta = f-1;
  
  sort(tenho, tenho+c);
  
  for(int i=0;i<(c-1);i++)
  {
      if(i==0) falta --;
      if(tenho[i]!=tenho[i+1])
      {
          falta --;
      }
  }
    
    printf("%d\n", falta);
    
  return 0;
}