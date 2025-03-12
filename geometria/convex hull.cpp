#include <bits/stdc++.h>

using namespace std;
#define ll long long int

struct pt { //ponto
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

vector<pt> convex_hull(vector<pt> v){
    sort(v.begin(), v.end());
    vector<pt> lower, upper;

    for(int i=0; i<(int)v.size(); i++){
        while(lower.size()>1 && cross(lower.end()[-2], lower.end()[-1], v[i])<0){
            lower.pop_back();
        }
        lower.push_back(v[i]);
        
        while(upper.size()>1 && cross(upper.end()[-2], upper.end()[-1], v[i])>0){
            upper.pop_back();
        }
        upper.push_back(v[i]);
    }

	lower.pop_back(); upper.erase(upper.begin());
    for (pt i : upper) lower.push_back(i);
	return lower;
}

int main(){

    int n;
    cin>>n;

    vector<pt> pontos;

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        pontos.push_back({x,y});
    }

    vector<pt> polygon = convex_hull(pontos);

    cout<<polygon.size()<<endl;
    for(auto p: polygon){
        cout<<p.x<<" "<<p.y<<endl;
    }


    return 0;
}