#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
int cnt[N];

void solve(){
	cin>>n>>m;
	memset(cnt,0,sizeof cnt);
	VVI s(n+1);
	for(int i=1;i<=n;i++){
		int l;	cin>>l;
		for(int j=1;j<=l;j++){
			int x;	cin>>x;
			cnt[x]++;
			s[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		if(!cnt[i]){
			cout<<"NO\n";
			return;
		}
	}
	int ct=0;
	for(int i=1;i<=n;i++){
		bool ok=true;
		for(int j=0;j<s[i].size();j++){
			if(cnt[s[i][j]]<2){
				ok=false;
				break;
			}
		}
		if(ok) ct++;
		if(ct>=2){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}

// void solve(){
// 	cin>>n>>m;
// 	memset(cnt,0,sizeof cnt);
// 	vector<set<int>> s;
// 	for(int i=1;i<=n;i++){
// 		int l;	cin>>l;
// 		for(int j=1;j<=l;j++){
// 			int x;	cin>>x;
// 			cnt[x]++;
// 			s[i].insert(x);
// 		}
// 	}
// 	if(n<3){
// 		cout<<"NO\n";
// 		return;
// 	}
// 	for(int i=1;i<=m;i++){
// 		if(!cnt[i]){
// 			cout<<"NO\n";
// 			return;
// 		}
// 	}
// 	int ct=0;
// 	for(int i=1;i<=n;i++){
// 		bool ok=true;
// 		while(s[i].size()){
// 			int x=*s[i].begin();
// 			s[i].erase(x);
// 			if(cnt[x]==1){
// 				ok=false;
// 				break;
// 			}
// 		}
// 		if(ok) ct++;
// 		if(ct>=2){
// 			cout<<"YES\n";
// 			return;
// 		}
// 	}
// 	cout<<"NO\n";
// }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}