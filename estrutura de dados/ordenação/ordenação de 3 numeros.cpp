#include <bits/stdc++.h>

using namespace std;

int main()
{
  int v[3];

  for(int i=0;i<3;i++) scanf("%d",&v[i]);

  sort(v,v+3);

  for(int i=0;i<3;i++) printf("%d\n", v[i]);

  return 0;
}