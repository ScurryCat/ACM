#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

ll n,m,k,x,cho,van,ans;

bool cmp(int c,int x){
	int cnt1=0,cnt2=0;
	for(int i=60;i>=0;i--) if(c&(1<<i)) cnt1++;
	for(int i=60;i>=0;i--) if(x&(1<<i)) cnt2++;
	if(cnt1==cnt2) return c<x;
	return cnt1<cnt2;
}

// 1000
// 100 100
// 010 110
// 101 011

// 4 9
// 10000
// 1000 1000
// 0100 1100
// 0010 1110
// 1001 0111

// 5 21
// 100000
// 10000 10000
//  11000
// 10100 01100
// 01010 10110
// 10101 01011
void solve(){
	cin>>k>>x;
	van=cho=1ll<<k;
	vector<int> op;
	while(cho!=x){
		if(cmp(cho,x)){
			op.push_back(2);
			// cho|=(cho+1);
			van>>=1;
			cho+=van;
		}
		else{
			op.push_back(1);
			cho>>=1;
			van+=cho;
			// cho>>=1;
		}
		// cout<<cho<<'\n';
	}
	cout<<op.size()<<'\n';
	for(auto q : op) cout<<q<<' ';
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
