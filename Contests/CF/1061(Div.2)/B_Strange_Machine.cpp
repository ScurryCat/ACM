#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n,q;
	string s;
	cin>>n>>q>>s;
	bool flag=0;
	if(count(s.begin(),s.end(),'B')==0) flag=1;
	while(q--){
		int a; cin>>a;
		if(flag) {cout<<a<<'\n';continue;}
		int cnt=0;
		for(int idx=0;a;idx=(idx+1)%n,cnt++){
			if(s[idx]=='A') a--;
			else a>>=1;
		}
		cout<<cnt<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}