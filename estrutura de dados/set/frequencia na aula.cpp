#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  set<int> lista;

  for(int i=1;i<=n;i++)
  {
    int x;
    cin>>x;
    lista.insert(x);
  }

  printf("%d\n", (int)lista.size());
	
  return 0;
}