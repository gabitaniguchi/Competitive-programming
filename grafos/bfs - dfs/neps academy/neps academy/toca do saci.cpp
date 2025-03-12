#include <cstdio>
#include <cstring> // memset

#define MAXN 1010

int n, m, tab[MAXN][MAXN], vx[4]={0,1,0,-1}, vy[4]={1,0,-1,0}, x, y, x_f, y_f, dist[MAXN][MAXN];

// DFS que encontrará as distâncias
void dfs(int i, int j){
	
	// para cada possibilidade de deslocamento
	// (cima, baixo, esquerda e direita)
	for(int k=0;k<4;k++){
		
		// vejo a casa para a qual iria
		int i_=i+vx[k], j_=j+vy[k];
		
		// se ela estiver dentro da matriz
		// e não tiver sido alcançada ainda
		if(tab[i_][j_]>0 && dist[i_][j_]<0){
			
			// atualizo sua distância
			dist[i_][j_]=dist[i][j]+1;
			
			// e chamo a DFS nela
			dfs(i_,j_);
		}
	}
}

int main(){
	
	memset(dist,-1,sizeof dist); // defino todas as distâncias como -1
	
	// leio os valores de n e m
	scanf("%d %d", &n, &m);
	
	// leio os valores da matriz
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			
			scanf("%d", &tab[i][j]);
			
			// se encontrei a casa 2, salvo os valores de x e y
			if(tab[i][j]==2){
				
				x=i;
				y=j;
			}
			
			// se encontrei a casa 3, salvo os valores de x_f e y_f
			if(tab[i][j]==3){
				
				x_f=i;
				y_f=j;
			}
		}
	
	// a distância da casa 2 para ela mesma será definida com um
	// pois o problema a conta no tamanho do caminho
	dist[x][y]=1;
	
	// chamo a DFS na casa inicial
	dfs(x,y);
	
	// imprimo a distância que a DFS encontrou até a saída
	printf("%d\n", dist[x_f][y_f]);
	
	return 0;
}