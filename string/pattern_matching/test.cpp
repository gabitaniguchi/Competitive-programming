#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

vector<int> prefix_function(string p){
    vector<int> pi(p.size());
    for(int i=1, j=0; i<(int)p.size(); i++){
        while(j>0 && p[j]!=p[i]) j = pi[j-1];
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// s1 esta contida em s2
bool substring (string& s1, string& s2){
    string t = s1+"*"+s2;
    vector<int> pi = prefix_function(t);
    
    for(int i=s1.size()+1; i<t.size(); i++) if(pi[i]==s1.size()) return true;
    return false;
}

string menor_entre_dois(string s1, string s2){
    vector<int> pi1 = prefix_function(s1+"*"+s2);
    vector<int> pi2 = prefix_function(s2+"*"+s1);

    int op1 = pi1[pi1.size()-1];
    int op2 = pi2[pi2.size()-1];

    if(op1>op2 && op1>0){
        string t = "";
        for(int i=0; s2.size()-i-1>=op1; i++) t+=s2[i];
        t+=s1;
        return t;
    }  

    if(op2>op1 && op2>0){
        string t = "";
        for(int i=0; s1.size()-i-1>=op2; i++){
            t+=s1[i];
        } 
        t+=s2;
        return t;
    }

    return s1+s2;
}

int menor_total(string&s1, string &s2, string& s3){
    bool sub_s2 = substring(s2,s1);
    bool sub_s3 = substring(s3, s1);

    if(sub_s2 && sub_s3) return s1.size();

    if(sub_s2) return menor_entre_dois(s1, s3).size();

    if(sub_s3) return menor_entre_dois(s1,s2).size();

    int op1 = menor_entre_dois(menor_entre_dois(s1,s2), s3).size();
    int op2 = menor_entre_dois(menor_entre_dois(s1,s3), s2).size();
    return min(op1, op2);
}   

int32_t main()
{_
    string s1, s2, s3; 
    cin>>s1>>s2>>s3;
    int ans = s1.size() + s2.size() + s3.size();

    //s1, s2, s3 ou s1, s3, s2
    ans = min(ans, menor_total(s1,s2,s3));
    // //s2, s1, s3 ou s2, s3, s1
    ans = min(ans, menor_total(s2,s1,s3));
    // //s3, s1, s2 ou s3, s2, s1
    ans = min(ans, menor_total(s3,s1,s2));

    cout<<ans<<endl;
}