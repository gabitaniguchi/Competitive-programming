#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct pt { //ponto
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
pt q1[4], q2[4];

ll cross (pt p, pt q, pt r){
    return (q-p)^(r-q);
}

ll orientation(pt p, pt q, pt r){
    ll valor = cross(p,q,r);

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

bool inside(){
    bool inside1 = true;
    for(int i=0; i<4; i++){
        if(q2[i].x<q1[0].x || q2[i].x>q1[3].x || q2[i].y<q1[0].y || q2[i].y>q1[3].y){
            inside1=false;
            break;
        }
    }

    if(inside1) return true;

    bool inside2 = true;
    for(int i=0; i<4; i++){
        if((q1[i].y-q1[i].x)<(q2[2].y-q2[2].x) ||(q1[i].y-q1[i].x)>(q2[0].y-q2[3].x) || (q1[i].y+q1[i].x)<(q2[0].y+q2[0].x) || (q1[i].y+q1[i].x)>(q2[0].y+q2[3].x) ){
            inside2=false;
            break;
        }
    }
    
    if(inside2) return true;
    return false;
}

bool check(){
    if(inside()) return true;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(intersecta(q2[i], q2[i+1], q1[j], q1[j+1])) return true;
        }
    }

    return false;
}
int main(){

    for(int i=0; i<4; i++) cin>>q1[i].x>>q1[i].y;
    for(int i=0; i<4; i++) cin>>q2[i].x>>q2[i].y;

    sort(q1, q1+4);
    sort(q2, q2+4);

    if(check()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}