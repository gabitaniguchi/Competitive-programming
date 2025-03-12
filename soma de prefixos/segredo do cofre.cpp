#include <bits/stdc++.h>

using namespace std;

long long int dist[10];
int pref[100010], sub_sum[1000010];

void atualiza(int l,int r,int d){

    sub_sum[l] += d;
    sub_sum[r+1] += -d;
}

int main(){

    int n, q, last;
    cin>>n>>q;
    int senha[n+5];
    pref[0] = 0;

    for(int i=1;i<=n;i++) cin>>senha[i];

    cin>>last;
    atualiza(1,1,1);

    for(int i=1;i<q;i++){
        int next;
        cin>>next;

        int l = min(next,last), r = max(next,last);

        atualiza(l,r,1);

        atualiza(last,last,-1);

        last = next;
    }

    for(int i=1;i<=n;i++){

        pref[i] = pref[i-1] + sub_sum[i];
        dist[senha[i]] += pref[i];
    }

    for(int i=0;i<=9;i++){

        cout<<dist[i];

        if(i<9) cout<<" ";
        else cout<<endl;
    }

    return 0;
}