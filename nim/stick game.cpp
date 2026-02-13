#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e6+10)
int n, k;
int moves[110];
char pos[MAX];

int main(){

    cin>>n>>k;

    for(int i=1;i<=k;i++) cin>>moves[i];

    sort(moves, moves+k+1);

    for(int i=0;i<=n;i++) pos[i] = 'L';

    for(int i=0;i<=n;i++){
        if(i!=0)cout<<pos[i];
        if(pos[i]=='W') continue;

        for(int j=1;j<=k;j++){
            int index = moves[j] + i;
            if(index>n) break;
            pos[index] = 'W';
        }
    }
    cout<<endl;

    return 0;
}