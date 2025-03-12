#include <bits/stdc++.h>

using namespace std;
#define p pair<int,int>
#define x first 
#define y second

int dot (p a, p b){
    return  a.x*b.x + a.y*b.y;
}

int cross (p a, p b){
    return a.x*b.y - a.y*b.x;
}

p sub(p a, p b){
    return {a.x-b.x, a.y-b.y};
}

int norma(p a, p b ){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); 
}

bool colinear(p a, p b, p c){
    if (cross(sub(b,a), sub(c, b))==0){
        return true;
    }

    return false;
}

int main(){

    pair<int, int> P[8];

    for(int i=1; i<=7; i++){
        int xi, yi;
        scanf("%d %d", &xi, &yi);

        P[i] = {xi,yi};
    }

    if(dot(sub(P[1], P[2]), sub(P[1], P[3])) <= 0){
        printf("N\n");
        return 0;
    }

    if(norma(P[1], P[2])!=norma(P[1], P[3])){
        printf("N\n");
        return 0;
    }

    if(!colinear(P[2], P[4], P[5]) || !colinear(P[4], P[5], P[3])){
        printf("N\n");
        return 0;
    }

    if(P[2].x+P[3].x != P[4].x+P[5].x || P[2].y+P[3].y!=P[4].y+P[5].y){
        printf("N\n");
        return 0;
    }

    if(norma(P[3], P[2]) < norma(P[5], P[4])){
        printf("N\n");
        return 0;
    }

    if(dot(sub(P[4], P[6]), sub(P[3], P[2]))!=0 || dot(sub(P[5], P[7]), sub(P[3], P[2]))!=0){
        printf("N\n");
        return 0;
    }

    if(norma(P[4], P[6]) != norma(P[5],P[7])){
        printf("N\n");
        return 0;
    }

    if(cross(sub(P[3],P[2]),sub(P[1], P[2]))*cross(sub(P[3],P[2]), sub(P[6],P[2]))>=0){
        printf("N\n");
        return 0;
    }

    printf("S\n");

    return 0;
}