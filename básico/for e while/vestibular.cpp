#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    string gab, alun;
    int i,c=0;
    
    cin>>q>>gab>>alun;
    
    for(i=0;i<q;i++)
    {
        if(gab[i] == alun[i])
        {
            c++;
        }
    }
    
    cout<<c<<"\n";
    
    return 0;
}