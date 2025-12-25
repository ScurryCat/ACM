#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int h1,m1,h2,m2,n;
	char ch;
	cin>>h1>>ch>>m1;
	cin>>h2>>ch>>m2;
	cin>>n;
	m1+=h1*60;
	m2+=h2*60;
	int m=(m2-m1);
	vector<int> f(m+1);
	for(int i=1;i<=n;i++){
		int v,w,s;
		cin>>v>>w>>s;
		if(s){
			int k=1;
			while(s>k){
				for(int j=m;j>=v*k;j--){
					f[j]=max(f[j],f[j-v*k]+w*k);
				}
				s-=k;
				k<<=1;
			}
			if(s){
				for(int j=m;j>=v*s;j--){
					f[j]=max(f[j],f[j-v*s]+w*s);
				}
			}
		}
		else{
			for(int j=v;j<=m;j++){
				f[j]=max(f[j],f[j-v]+w);
			}
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