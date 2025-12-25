#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+9;
const int M = 2e5+9;

int n,m,ans;
int a[N],b[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		// b[i]=n-a[i]+1;
		b[i]=n-a[i];
		if(b[i]==0) b[i]=n;
	}
	if(n==2) swap(b[1],b[2]);
	for(int i=1;i<=n;i++) cout<<b[i]<<' ';
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