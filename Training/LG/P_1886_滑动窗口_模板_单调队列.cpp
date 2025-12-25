#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e6+9, mod = 998244353;

int q[N],hh=1,tt=0;

void qwq_(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	hh=1,tt=0;
	for(int i=1;i<=n;i++){
		while(hh<=tt && a[q[tt]]>=a[i]) tt--;
		q[++tt]=i;
		if(q[hh]<i-k+1) hh++;
		if(i>=k) cout<<a[q[hh]]<<' ';
	}
	cout<<'\n';
	hh=1,tt=0;
	for(int i=1;i<=n;i++){
		while(hh<=tt && a[q[tt]]<=a[i]) tt--;
		q[++tt]=i;
		if(q[hh]<i-k+1) hh++;
		if(i>=k) cout<<a[q[hh]]<<' ';
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