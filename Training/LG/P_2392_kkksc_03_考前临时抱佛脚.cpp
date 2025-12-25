#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 20+9, mod = 998244353;

inline int fun(int n,vector<int> &a){
	int sum=0;
	vector<int> f(1201);
	for(int i=1;i<=n;i++) sum+=a[i];
	for(int i=1;i<=n;i++){ // 计算一半的时间最多能完整复习多少题
		for(int j=sum/2;j>=a[i];j--){
			f[j]=max(f[j],f[j-a[i]]+a[i]);
		}
	}
	return sum-f[sum/2];
}

void qwq_(){
	int ans=0, n[5];
	for(int i=1;i<=4;i++) cin>>n[i];
	for(int i=1;i<=4;i++){
		vector<int> a(n[i]+1);
		for(int j=1;j<=n[i];j++) cin>>a[j];
		ans+=fun(n[i],a);
	}
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