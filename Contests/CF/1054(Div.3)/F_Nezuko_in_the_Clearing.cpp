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

ll h,d;

bool check(ll x){
	ll hh=h+x-d,dd=d;
	ll rest=d/(x-d);
	// ll ret=0;
	// for(ll i=1;i<=rest;i++){
	// 	for(ll j=1;j<=rest;j++){
	// 		ret+=j;
	// 	}
	// }
	// return ret>hh;
	return hh<=rest*(1+rest)/2;
}

void solve(){
	cin>>h>>d;
	ll l=0,r=d+d+1,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<l<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
} 