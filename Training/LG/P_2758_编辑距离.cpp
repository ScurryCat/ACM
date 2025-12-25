#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	string a,b; cin>>a>>b;
	int n=a.size(), m=b.size();
	vector<int> f(m+1);
	int t1,t2;
	for(int i=1;i<=m;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		t1=f[0]++;
		for(int j=1;j<=m;j++){
			t2=f[j];
			if(a[i-1]==b[j-1]) f[j]=t1;
			else f[j]=min(t1,min(f[j-1],f[j]))+1;
			t1=t2;
		}
	}
	cout<<f[m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}