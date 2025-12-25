#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

ull n;

void solve(){
	cin>>n;
	if(n%10ULL) cout<<n+1<<'\n';
	else{
		ull ans=0;
		for(ull i=2;i*i<=n;i++){
			ull a=i,b=n/i;
			if(a%10ULL&&b%10ULL&&a*b==n){
				ans=a+b;
				break;
			}
		}
		cout<<ans<<'\n';
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