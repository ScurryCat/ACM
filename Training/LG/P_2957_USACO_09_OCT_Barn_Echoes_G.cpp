#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	string a,b; cin>>a>>b;
	int n=a.size(), m=b.size();
	vector<int> c(m+1), p(m+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		swap(c,p);
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]) c[j]=p[j-1]+1,ans=max(ans,c[j]);
			else c[j]=0;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}