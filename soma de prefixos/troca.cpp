#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
int qual[MAX], pref[MAX];

int main()
{
   int n,t;
   scanf("%d%d", &n, &t);
   int cima[n+1],baixo[n+1];

  for(int i=1;i<=n;i++) scanf("%d", &cima[i]);
  for(int i=1;i<=n;i++) scanf("%d", &baixo[i]);
  
  for(int i=1;i<=t;i++)
  {
    int l1,l2;
    scanf("%d%d", &l1, &l2);

    qual[l1] ++;
    qual[l2+1] --;
  }

  pref[1] = qual[1];
  
  for(int i=2;i<=n;i++) pref[i] = pref[i-1] + qual[i];

  for(int i=1;i<=n;i++) 
  {
    if(pref[i]%2==0) printf("%d", cima[i]); 
    else printf("%d", baixo[i]);

    if(i!=n) printf(" ");
    else printf("\n");
  }

  return 0;
}