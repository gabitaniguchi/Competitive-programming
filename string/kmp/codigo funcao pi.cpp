vector<int> prefix_function(string s){
    vector<int> pi(s.size());
    for(int i=1, j=0; i<(int)s.size(); i++){
        while(j>0 && s[j]!=s[i]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int automato[26][MAX];

void Automato_KMP (){
    // o primeiro caractere da string s leva a sair do estado 0
    automato[s[0]-'a'][0] = 1;
    for(int c=0; c<26; c++){
        for(int i=1; i<=(int)s.size(); i++){
            automato[c][i] = c == s[i]-'a'? i+1 : automato[c][pi[i-1]];
        }
    }
}
