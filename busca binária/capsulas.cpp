#include <bits/stdc++.h>

using namespace std;

int c;
long long int moedas;

int v[1000010];
	
long long int acumulado (int x){
	long long int soma = 0;
	for(int i=1;i<=c;i++){
		soma += x/v[i];
	}
	
	return soma;
}

int main(){
	
	cin>>c>>moedas;

		
	for(int i=1;i<=c;i++){
		cin>>v[i];
	}
	
	int inicio = 1;
	long long int fim = 100000010;
	int ans = 0;
	
	while(inicio<=fim){
		int meio = (inicio + fim)/2;
		
		if(acumulado(meio) < moedas) {
			inicio = meio+1;
		}
		
		else{
			ans = meio;
			fim = meio-1;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}