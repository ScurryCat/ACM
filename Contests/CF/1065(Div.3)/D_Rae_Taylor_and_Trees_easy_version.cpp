#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+9, mod = 998244353;

int p[N],r[N];

int find(int x){
	if(p[x]!=x){
		p[x]=find(p[x]);
	}
	return p[x];
}

void unionSets(int x,int y){
	int rx=find(x),ry=find(y);
	if(rx!=ry){
		if(r[rx]>r[ry]) p[ry]=rx;
		else if(r[rx]<r[ry]) p[rx]=ry;
		else{
			p[ry]=rx;
			r[rx]++;
		}
	}
}

void qwq_(){
	int n; cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
		r[i]=0;
  }
	int cnt=0;
  for (int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]){
				if (find(i)!=find(j)){
					unionSets(i,j);
					cnt++;
				}
			}
			// if(a[j]>a[i]){
			// 	if(r[j]){
			// 		if(r[i]==0) 
			// 			r[i]=j,cnt++;
			// 	}
			// 	else r[j]=i,cnt++;
			// }
		}
  }
	if(cnt>=n-1) cout<<"Yes\n";
	else cout<<"No\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}