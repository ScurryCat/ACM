#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

/*
	1100
	1010

	101
	110
*/

void solve(){
	ll a,b,x;
	cin>>a>>b;
	for(int i=0;i<32;i++) if(a&(1<<i)) x=1<<i;
	x=(x<<1)-1;
	if(x<b) cout<<"-1\n";
	else if(a==b) cout<<"0\n";
	else{
		// cout<<"2\n";
		// cout<<(a^b)<<' '<<((a^b)^b)<<'\n';
		vector<ll> ans;
		for(int i=0;i<32;i++){
			if((a&(1<<i))||(b&(1<<i)))
				if(!((a&(1<<i))&&(b&(1<<i)))) ans.push_back(1<<i);
		}
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
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