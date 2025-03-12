#include<bits/stdc++.h>

using namespace std;

struct pais{
    int ouro, prata,bronze,id;
};

int func(pais a, pais b)
{
    if(a.ouro != b.ouro)
    {
       return a.ouro>b.ouro;
    }
    if(a.prata != b.prata)
    {
        return a.prata > b.prata;
    }
    if(a.bronze != b.bronze)
    {
        return a.bronze > b.bronze;
    }
    return a.id < b.id;
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    pais v[105];
    int i, o,p,b;
    
    for(i=0;i<n;i++)
    {
        v[i].ouro = 0;
        v[i].prata = 0;
        v[i].bronze = 0;
        v[i].id = i+1;
    }
    
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d", &o, &p, &b);
        v[o-1].ouro++;
        v[p-1].prata++;
        v[b-1].bronze++;
    }
    sort(v,v+n,func);
    
    for(i=0;i<n;i++)
    {
        printf("%d ", v[i].id);
    }
    printf("\n");
    
    return 0;
}