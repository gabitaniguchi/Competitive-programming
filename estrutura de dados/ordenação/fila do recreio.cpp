#include <bits/stdc++.h>

using namespace std;

int func (int a, int b)
{
    return a>b;
}

int main()
{
    int casos, n_alunos, ans;
    
    scanf("%d", &casos);
    
    for(int i=1;i<=casos;i++)
    {
       
        scanf("%d", &n_alunos);
        int fila[n_alunos];
        ans = 0;
        
        for(int j=0;j<n_alunos;j++)  
        {
          
            scanf("%d", &fila[j]);
        
        }
        
        int ordem_certa[n_alunos];
        
        for(int j=0;j<n_alunos;j++)  
        {
            
            ordem_certa[j] = fila[j];
        }
        
        sort(ordem_certa,ordem_certa+n_alunos, func);
        
        for(int j=0;j<n_alunos;j++)  
        {
            
            if(fila[j] == ordem_certa[j]) 
            {
                ans ++;
            }

        }
          
        printf("%d\n", ans);
    
    }
    
    return 0;
}