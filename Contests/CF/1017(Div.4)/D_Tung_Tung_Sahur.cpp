#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;

void solve(){
	string a,b;
	cin>>a;
	cin>>b;
	if(a.size()>b.size()||a.size()*2<b.size()){
		cout<<"NO\n";
		return ;
	}
	bool ok=true;
	int i,j;
	for(i=0,j=0;i<a.size()&&j<b.size();){
		char cur=a[i];
		int cnt1=0,cnt2=0;
		while(a[i+cnt1]==cur&&i+cnt1<a.size()) cnt1++;
		while(b[j+cnt2]==cur&&j+cnt2<b.size()) cnt2++;
		i+=cnt1;
		j+=cnt2;
		// cout<<i<<' '<<j<<' '<<a[i]<<' '<<b[j]<<' ';
		// cout<<cnt1<<' '<<cnt2<<' '<<ok<<'\n';
		if(cnt1>cnt2||cnt2>cnt1*2) ok=false;
	}
	if(i<a.size()||j<b.size()) ok=false;
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
