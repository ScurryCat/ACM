#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 5e4+9, mod = 998244353;

int m,n;
int a[N];

bool check(int x){
	int cnt=0,c=m;
	for(int i=1;i<=n;i++){
		c-=a[i];
		if(c<0) break;
		cnt++;
	}
	return cnt>=x;
}

void qwq_(){
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n+1,mid;
	while(l+1<r){
		mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}