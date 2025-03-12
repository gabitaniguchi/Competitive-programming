#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

int A[MAX];

int main(){

    int N;
    
    scanf("%d", &N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d", &A[i]);
    }
    
    int resposta = 0;
    int melhor_predio = 0;
    
    for(int i=1;i<N;i++)
    {
        if(A[i]+(i- melhor_predio)+ A[melhor_predio])
        {
            resposta = max(resposta, A[i] + (i-melhor_predio)+A[melhor_predio]);
        
            if(A[i]>A[melhor_predio]+(i-melhor_predio))
            {
                melhor_predio = i;
            }
        }
    }
    
    printf("%d\n", resposta);

    return 0;
}