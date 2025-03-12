#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX (int)(3e5 + 10)

struct pt{
    int x,y;
    pt(int x_=0, int y_=0) : x(x_), y(y_) {}
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

ll cross (pt p, pt q, pt r){
    return (q-p)^(r-q);
}

pt pontos[MAX];

vector<pt> convex_hull(int n){
    vector<pt> upp;

    // percorre os pontos e calcula o upper
    for(int i=n-1; i>=0; i--){
        while(upp.size()>1 && cross(upp.end()[-2], upp.end()[-1], pontos[i])<=0){
            upp.pop_back();
        }

        upp.push_back(pontos[i]);
    }

    return upp;
    
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>pontos[i].x>>pontos[i].y;
    sort(pontos, pontos+n);

    vector<pt> hull = convex_hull( n);
    cout<<hull.size()-1<<endl;

    return 0;
}