#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+9;
const int M = 2e5+9;
const int mod = 998244353;

ll n,m,ans;
int a[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll cost=0;
	for(int i=1,j=n;i<j;i++,j--){
		if(a[i]>a[j]) while(a[j]<a[i]&&j>i) j--;
		else if(a[i]<a[j]) while(a[i]<a[j]&&i<j) i++;
		else cost+=j-i;
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
