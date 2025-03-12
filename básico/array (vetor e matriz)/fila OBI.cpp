#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tam, temp;
    scanf("%d", &tam);
    vector <int> fila;
    
    for(int i=0; i<tam;i++)
    {
        scanf("%d", &temp);
        
        fila.push_back(temp);
    }
    
    int n, saiu, p;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &saiu);
        for(int j = 0; j<tam; j++)
        {
            if(fila[j] == saiu) 
            {
                p = j;
                break;
            }
            
        }
        
        fila.erase(fila.begin()+p);
    }
   
    for(int i=0;i<(int)fila.size();i++)
    {
        printf("%d ", fila[i]);
    }
   
    printf("\n");
  
    return 0;
}