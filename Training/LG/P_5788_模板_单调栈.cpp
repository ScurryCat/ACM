#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> stk(n+1), ans(n+1);
	int tt=0;
	for(int i=1;i<=n;i++){
		while(tt && a[i]>a[stk[tt]]) ans[stk[tt--]]=i;
		stk[++tt]=i;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}