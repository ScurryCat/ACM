#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m,t;
	cin>>n>>m>>t;
	vector<vector<int>> f(m+1,vector<int>(t+1));
	for(int i=1;i<=n;i++){
		int mm,tt;
		cin>>mm>>tt;
		for(int j=m;j>=mm;j--){
			for(int k=t;k>=tt;k--){
				f[j][k]=max(f[j][k],f[j-mm][k-tt]+1);
			}
		}
	}
	cout<<f[m][t];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}