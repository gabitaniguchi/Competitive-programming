#include <bits/stdc++.h>

using namespace std;

int q;
string s;
stack <char> pilha;

int main(){

    cin>>q;

    while(q--){
        cin>>s;

        string ans = "S";

        for(int i=0; i<(int)s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                pilha.push(s[i]);
            }

            else{
                if(pilha.empty()){
                    ans = "N";
                    break;
                }

                if(s[i]==')' && pilha.top()!='('){
                    ans = "N";
                    break;
                }

                if(s[i]==']' && pilha.top()!='['){
                    ans = "N";
                    break;
                }

                if(s[i]=='}' && pilha.top()!='{'){
                    ans = "N";
                    break;
                }

                pilha.pop();

            }

        }

        if(!pilha.empty()) ans = "N";

        cout<<ans<<endl;
        
        while(!pilha.empty()) pilha.pop();

    }

    return 0;
}