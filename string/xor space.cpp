#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin>>s;

  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]>=65 && s[i]<=90) s[i] = tolower(s[i]);
    else s[i] = toupper(s[i]);
  }
  
  cout<<s<<endl;
  
  return 0;
}