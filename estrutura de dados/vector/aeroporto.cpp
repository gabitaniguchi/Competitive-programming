#include <bits/stdc++.h>

using namespace std;

int main()
{
  int p,v;
  cin>>p>>v;
  int teste=1;
  
  while(p!=0 && v!=0)
  {
    vector<int> grau(p+1);
    int ans=0;

    for(int i=1;i<=v;i++)
    {
      int a,b;
      cin>>a>>b;

      grau[a]++;
      grau[b]++;
      ans = max({ans,grau[a],grau[b]});
    }
    cout<<"Teste "<<teste<<endl;
    for(int i=1;i<=p;i++)
    {
      if(grau[i]==ans) cout<<i<<' ';
    }
    cout<<endl<<endl;

    cin>>p>>v;
    teste++;
  }

  return 0;
}