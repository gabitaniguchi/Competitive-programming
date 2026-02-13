#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> suffix;

vector<int> suffix_array(string &s) {
	s += "$";
	int n = s.size(), N = max(n, 260);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

int find_menor(string s, string t){
    int i=0, f=suffix.size()-1;
    int idx=-1;
    while(i<=f){
        int m=(i+f)/2;

        if(s.substr(suffix[m], t.size()) < t)
            i=m+1;

        else if(s.substr(suffix[m], t.size()) > t)
            f=m-1;

        else {
            if(idx==-1) idx=m;
            else idx = min(idx, m);
            f=m-1;
        }
    }

    return idx;
}

int find_maior(string s, string t){
    int i=0, f=suffix.size()-1;
    int idx=-1;
    while(i<=f){
        int m=(i+f)/2;

        if(s.substr(suffix[m], t.size()) < t)
            i=m+1;

        else if(s.substr(suffix[m], t.size()) > t)
            f=m-1;

        else {
            if(idx==-1) idx=m;
            else idx = max(idx, m);
            i=m+1;
        }
    }

    return idx;
}

int main(){_

    string s;
    cin>>s;

    suffix = suffix_array(s);

    int t;
    cin>>t;
    while(t--){
        string temp;
        cin>>temp;

        int menor = find_menor(s, temp);
        if(menor==-1){
            cout<<0<<endl;
            continue;
        }
        int maior = find_maior(s, temp);

        cout<<maior-menor+1<<endl;
    }

    return 0;
}