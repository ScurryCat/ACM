#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

struct item{int v,w,s;}a[1010];

int m,n;
int f[1010]; // f[i]表示前i组
int cnt[1010];

bool cmp(item x,item y){
	return x.s<y.s;
}

void qwq_(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].v>>a[i].s;
		cnt[a[i].s]++;
	}
	sort(a+1,a+n+1,cmp);
	int idx=1;
	for(int i=1;cnt[i];i++){
		for(int j=m;j>=0;j--){
			for(int k=idx;k<idx+cnt[i];k++){
				if(j>=a[k].w) f[j]=max(f[j],f[j-a[k].w]+a[k].v);
			}
		}
		// for(int ii=1;ii<=m;ii++) cout<<f[ii]<<' ';cout<<'\n';
		idx+=cnt[i];
	}
	// for(int i=1;i<=m;i++) cout<<f[i]<<' ';
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