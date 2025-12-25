#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 5e3+9, mod = 998244353;

void qwq_(){
	string a,b;
	while(cin>>a>>b){
		int n=a.size(), m=b.size();
		vector<int> f(m+1,0), p(m+1,0);
		for(int i=1;i<=n;i++){
			swap(f,p);
			for(int j=1;j<=m;j++){
				f[j] = (a[i-1]==b[j-1] ? p[j-1]+1 : max(f[j-1],p[j]));
			}
		}
		cout<<f[m]<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}