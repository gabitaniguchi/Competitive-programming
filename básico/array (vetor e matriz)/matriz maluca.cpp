#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int l,c,n;
	int te=0,tl=0;
	
	scanf("%d %d %d",&l,&c,&n);
	
	int m[l+5][c+5];
	
	for(int i=1;i<=l;i++){
		for(int j=1;j<=c;j++){	
			scanf("%d", &m[i][j]);
		}
	}	
	
	int temp,x,y;
	
	for(int i=1;i<=n;i++){
	    
		temp = 0;
		
		scanf("%d %d", &x,&y);
		
		for(int j=1;j<=c;j++) {
	    	temp += m[x][j];
			m[x][j] = 0;	
		}
		
		for(int j=1;j<=l;j++){
	    	temp += m[j][y];
			m[j][y] = 0;	
		}
			
		if(i%2==0) tl+= temp;
		else te += temp;
		 
	}
	
	if(te>tl) printf("Enzo\n");
	else if(tl>te) printf("Lobo\n");
	else printf("Empate\n");
	
	return 0;
}