#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int p, q;
    
    cin>>p>>q;
    
    vector<int> ligado[p+5];
    
    for(int i=1;i<=q;i++){
        int check, a,b, ans=0;
        
        cin>>check>>a>>b;
      
        if(check==1){
            ligado[a].push_back(b);
            ligado[b].push_back(a);
        }
        
        else{  
            int tam = ligado[a].size();
            
            for(int i=0;i<tam;i++){
                if(ligado[a][i]==b){
                    ans=1;
                    break;
                }
            }
            printf("%d\n",ans);
        }
        
    }

    return 0;
}