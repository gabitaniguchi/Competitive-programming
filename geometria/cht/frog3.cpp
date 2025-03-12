#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n,c;

struct line { // reta
	ll a, b;
    line(ll a_=0, ll b_=0) : a(a_), b(b_) {}
};

deque<line> retas;

ll val(line r, ll x){
    return  r.a*x + r.b;
}

void update(line curr)
{
	ll tam = retas.size();
	while (tam>1 && ((retas[tam-2].b-retas[tam-1].b)*(curr.a-retas[tam-2].a)) >= ((retas[tam-2].b-curr.b)*(retas[tam-1].a-retas[tam-2].a)))
		retas.pop_back(), tam--;
 
	retas.push_back(curr);
}
 
ll query(ll x)
{
	while (retas.size()>1 && val(retas[0],x) >= val(retas[1], x))
		retas.pop_front();
 
	return val(retas.front(), x);
}

int main(){

    cin>>n>>c;
    ll dp[n+5], h[n+5];

    for(ll i=1; i<=n; i++) cin>>h[i];
    dp[1] = 0;

    for(ll i=1; i<=n; i++){
        if(i>1) dp[i] = h[i]*h[i] + query(h[i]);
        line current = {-2*h[i], c + h[i]*h[i] + dp[i]};
        update(current);
    }

    cout<<dp[n]<<endl;

    return 0;
}