#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct pt{
    ll x,y;
    pt(ll x_=0, ll y_=0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }

    bool operator == (const  pt p) const{
        return x == p.x and y == p.y;
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

pt p[8];

ll cross (pt p, pt q, pt r){
    return (q-p)^(r-q);
}

ll norma(pt a, pt b ){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); 
}

bool ponto_medio (pt a, pt b, pt c, pt d){
    pt m1, m2;
    m1.x = (a.x + b.x)/2;
    m2.x = (c.x + d.x)/2;
    if(m1.x!=m2.x) return false;
    m1.y = (a.y + b.y)/2;
    m2.y = (c.y + d.y)/2;
    if(m1.y!=m2.y) return false;
    return true;
}

ll orientation(pt p, pt q, pt r){
    int valor = cross(p,q,r);

    //colinear
    if(valor==0) return 0;

    // clock wise
    if(valor>0) return 1;

    //counterclock wise
    return 2;
}

bool segmento_contido(pt p, pt q, pt r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
}


bool intersecta(pt p1, pt q1, pt p2, pt q2){

    // orientações
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);

    if(o1!=o2 && o3!=o4) return true;

    // caso colinear
    if(o1==0 && segmento_contido(p1, p2, q1)) return true;
    if(o2==0 && segmento_contido(p1, q2, q1)) return true;
    if(o3==0 && segmento_contido(p2, p1, q2)) return true;
    if(o4==0 && segmento_contido(p2, q1, q2)) return true;

    return false;
}
bool check(){

    if((p[2]-p[1])*(p[3]-p[1])<=0) return false;
    if(norma(p[1], p[2])!=norma(p[1],p[3])) return false;
    if(!(cross(p[2],p[3],p[4])==0 && cross(p[3],p[4], p[5])==0)) return false;
    if(!ponto_medio(p[2],p[3],p[4],p[5])) return false;
    if(norma(p[3], p[2])<=norma(p[4],p[5])) return false;
    if(((p[6]-p[4])*(p[3]-p[2])!=0) || ((p[7]-p[5])*(p[3]-p[2])!=0)) return false;
    if(norma(p[1], p[2])!=norma(p[1],p[3])) return false;
    if(norma(p[4], p[6])!=norma(p[5],p[7])) return false;
    if(!intersecta(p[1],p[6],p[2], p[3])) return false;
    
    return true;

}

int main(){


    for(int i=1; i<=7; i++) cin>>p[i].x>>p[i].y;

    if(check()) printf("S\n");
    else printf("N\n");

    return 0;
}