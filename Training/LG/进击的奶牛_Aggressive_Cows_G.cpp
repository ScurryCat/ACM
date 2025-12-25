#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,m;
int a[N];

bool check(int x){
	int cnt=1;
	for(int i=1,j=1;j<=n;j++){
		if(a[j]-a[i]>=x){
			cnt++;
			i=j;
		}
	}
	return cnt>=m;
}

int find(){
	int l=a[1]-1,r=a[n]+1,mid;
	while(l+1<r){
		mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}

void qwq_(){
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<find();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}