#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<vector<int>> f(n+1,vector<int>(2)); // L[i]表示第i层以左端点为终点的最短路线长度
	int pl=1,pr=1;
	for(int i=1;i<=n;i++){
		int l,r; cin>>l>>r;
		f[i][0] = (r-l+1) + min(f[i-1][0]+(abs(pl-r)), f[i-1][1]+(abs(pr-r)));
		f[i][1] = (r-l+1) + min(f[i-1][0]+(abs(pl-l)), f[i-1][1]+(abs(pr-l)));
		pl=l, pr=r;
	}
	cout<<min(f[n][0]+n-pl,f[n][1]+n-pr)-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}