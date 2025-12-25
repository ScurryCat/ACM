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

void solve(){
	cin>>n;
	vector<char> s(n+1);
	vector<int> p(n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1'){
			cnt++;
			p[i]=i;
		}
		else{
			p[i]=(i+1)%n+1;
		}
	}
	if(cnt==0){
		cout<<"YES\n";
		for(int i=1;i<=n;i++) cout<<p[i]<<' ';
		cout<<'\n';
	}
	else{
		if(cnt&1){
			cout<<"YES\n";
			for(int i=1;i<=n;i++) cout<<p[i]<<' ';
			cout<<'\n';
		}
		else cout<<"NO\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}