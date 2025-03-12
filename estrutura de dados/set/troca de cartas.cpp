#include <bits/stdc++.h>
#include <iterator>

using namespace std;

int main()
{
  int A, B,x;
  cin>>A>>B;

  set<int> ana, bia;

  for(int i=1;i<=A;i++)
  {
    cin>>x;
    ana.insert(x);
  }
  for(int i=1;i<=B;i++)
  {
    cin>>x;
    bia.insert(x);
  }
  
  std::vector<int> repetidas;
  set_intersection(ana.begin(),ana.end(),bia.begin(),bia.end(), std::back_inserter(repetidas));
  
  int tamA = ana.size() - repetidas.size();
  int tamB = bia.size() - repetidas.size();

  int ans = min(tamA, tamB);

  cout<<ans;

  return 0;
}