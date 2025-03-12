#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main(){

    stack<ll> pilha;
    string s;

    int o;
    cin>>o;

    while(o--){
        cin>>s;

        if(s=="PUSH"){
            ll x;
            cin>>x;

            if(pilha.empty()) pilha.push(x);
            else if(x<pilha.top()) pilha.push(x);
            else pilha.push(pilha.top());
        }

        else if(s=="POP"){
            if(pilha.empty()) cout<<"EMPTY"<<endl;
            else pilha.pop();
        }

        else if(s=="MIN"){
            if(pilha.empty()) cout<<"EMPTY"<<endl;
            else cout<<pilha.top()<<endl; 
        }

    }

    return 0;
}