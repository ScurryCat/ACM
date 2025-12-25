// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<vector<double>> p(1<<n,vector<double>(1<<n)), f(n+1,vector<double>(1<<n));
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<(1<<n);j++){
			cin>>p[i][j];
		}
	}
	for(int i=0;i<(1<<n);i++) f[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<n);j++){
			for(int k=0;k<(1<<n);k++){
				if(((j>>(i-1))^1)==(k>>(i-1))) f[i][j]+=f[i-1][j]*f[i-1][k]*p[j][k];
			}
		}
	}
	int ans=1;
	double mx=0;
	for(int i=0;i<(1<<n);i++){
		if(mx<f[n][i]){
			ans=i+1;
			mx=f[n][i];
		}
	}
	// cout<<mx<<'\n';
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}