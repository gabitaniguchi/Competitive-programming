#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e6+10)

int pi[MAX];
vector<int> ans;
string s;

void prefix_function(){

	for(int i=1, j=0; i<(int)s.size();i++){
		while(j>0 && s[i]!=s[j]) j = pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i] = j;
	}
}

void borders(){
	int j = pi[(int)s.size()-1];

	while(j>0){
		ans.push_back(j);
		j = pi[j-1];
	}
}

int main(){

	cin>>s;
	prefix_function();
	borders();

	sort(ans.begin(), ans.end());

	for(auto b: ans) cout<<b<<" ";
	cout<<endl;

	return 0;
}