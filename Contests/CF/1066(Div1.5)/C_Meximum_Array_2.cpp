#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353, inf=0x3f3f3f3f;

// void qwq_(){
// 	int n,k,q;
// 	cin>>n>>k>>q;
// 	vector<int> a(n);
// 	vector<vector<int>> mi(n+1,vector<int>(n+1)), me(n+1,vector<int>(n+1));
// 	vector<int> dmi(n+1), dme(n+1);
// 	while(q--){
// 		int c,l,r;
// 		cin>>c>>l>>r;
// 		if(c==1) mi[l][r]=k;
// 		else me[l][r]=k;
// 	}
// 	for(int i=1;i<=n;i++){
// 		for(int j=i+1;j<=n;j++){
// 			if(me[i][j]) dme[j]=k^dme[i-1];
// 		}
// 	}
// 	for(int i=1;i<=n;i++) cout<<dme[i]<<' ';cout<<'\n';
// 	for(int i=1;i<=n;i++){
// 		for(int j=i+1;j<=n;j++){
// 			if(me[i][j]) cout<<(dme[j]^dme[i-1])<<'\n';
// 		}
// 	}
// }

void qwq_(){
	int n,k,q;
	cin>>n>>k>>q;
	vector<int> a(n+1,inf);
	vector<vector<int>> mi(n+1,vector<int>(n+1)), me(n+1,vector<int>(n+1));
	while(q--){
		int c,l,r;
		cin>>c>>l>>r;
		if(c==1) mi[l][r]=k;
		else me[l][r]=k;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mi[i][j]) a[i]=k;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(me[i][j]){
				for(int ii=0;ii<k;ii++){
					a[i+ii]=ii;
				}
				for(int ii=i;ii<=j;ii++){
					if(a[ii]==k) a[ii]=inf;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}