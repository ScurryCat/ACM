#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n;	cin>>n;
	int cnt=0;
	VI a;
	if(n) while(!(n&1)) n>>=1;
	while(n){
		if(n&1) a.push_back(1),cnt++;
		else a.push_back(0);
		n>>=1;
	}
	bool ok=true;
	if(cnt%2) ok=false;
	for(int i=0,j=a.size()-1;i<=j;i++,j--){
		if(a[i]!=a[j]){
			ok=false;
			break;
		}
	}
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}