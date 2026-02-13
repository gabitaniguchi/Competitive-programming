#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define MAXN (int)(4e4)

int eh_primo[MAXN];
vector<int> primes;
set<int> fatores_primos;
map<int,int> masks, nimber;

// encontra os primos ate raiz(10⁹), pois ao fazer a fatoração
// so precisa ir até raiz de n
void crivo(){
    for(int i=2; i<MAXN; i++) eh_primo[i] = 1;
    for(int i=2; i<MAXN;i++){
        primes.push_back(i);
        for(int j=i*i; j<MAXN; j+=i) eh_primo[j] = 0;
    }
}

void fatoracao(int x){

    for(auto p: primes){
        // se x eh primo
        if(p*p > x) break;
        if(x%p==0){
            fatores_primos.insert(p);
            int exp=0;
            while(x%p==0){
                x/=p;
                exp++;
            }
            masks[p] |= (1<<(exp-1));
        }
    }
    //x eh primo
    if(x>1){
        masks[x] |= (1<<0);
        fatores_primos.insert(x);
    } 
}

int get_grundy(int mask){
    if(nimber[mask] || mask==0) { 
        return nimber[mask];
    }

    set<int> estado;
    int max_k = 32 - __builtin_clz(mask);
    
    for(int k=1; k<=max_k;k++){
        int menor_mask = mask&((1<<(k-1))-1);
        int maior_mask = mask>>k;
        int new_mask = menor_mask|maior_mask;

        estado.insert(get_grundy(new_mask));
    }

    int mex = 0;
    while(estado.find(mex)!=estado.end()) mex++;
    return nimber[mask] = mex;
}

int32_t main()
{_
    int n, ans=0;
    cin>>n;
   
    crivo();

    for(int i=1; i<=n; i++){
        int x; cin>>x;
        fatoracao(x);
    }

    nimber[1] = 1;

    for(auto p: fatores_primos){
        ans^=get_grundy(masks[p]);
    }

    if(ans) cout<<"Mojtaba"<<endl;
    else cout<<"Arpa"<<endl;
}