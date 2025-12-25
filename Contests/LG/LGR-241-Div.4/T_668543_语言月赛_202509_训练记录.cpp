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
	int d;
	cin>>d;
	int ans=0,cnt=1;;
	for(int i=1;i<=d;i++){
		int a;
		cin>>a;
		if(!a) ans+=100;
		else{
			if(a&1){
				if(cnt&1) ans+=50;
				else ans-=30;
				cnt++;
			}
		}
		cout<<ans<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}