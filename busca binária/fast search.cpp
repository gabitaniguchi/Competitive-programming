#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
int n,k;
int v[MAX];

int left(int x){
    int inicio = 0;
    int fim = n-1;
    int ans = fim;

    while(fim>=inicio){
        int meio = (inicio+fim)/2;

        if(v[meio]>=x){
            ans = min(ans, meio);
            fim = meio - 1;
        }

        else{
            inicio = meio + 1;
        }
    }

    return ans;
}


int rigth(int x){
    int inicio = 0;
    int fim = n-1;
    int ans = 0;

    while(fim>=inicio){
        int meio = (inicio+fim)/2;

        if(v[meio]<=x){
            ans = max(ans, meio);
            inicio = meio + 1;
        }

        else{
            fim = meio - 1;
        }
    }

    return ans;
}

int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &v[i]);

    sort(v,v+n);

    scanf("%d", &k);

    for(int i=1;i<=k;i++){
        int l,r;
        scanf("%d %d", &l, &r);

        int index_l = left(l);
        int index_r = rigth(r);

        int res;
        if(index_r < index_l || v[index_l]<l || v[index_r]>r) res = 0;
        else if (index_r == index_l) res = 1;
        else res = index_r - index_l + 1;

        printf("%d", res);
        
        if(i<k) printf(" ");
        else printf("\n");
    }

    return 0;
}