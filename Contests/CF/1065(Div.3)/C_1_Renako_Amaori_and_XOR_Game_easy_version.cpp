#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	int x=0,y=0;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i],x^=a[i];
	for(int i=1;i<=n;i++) cin>>b[i],y^=b[i];
	// cout<<x<<' '<<y<<'\n';
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]) continue;
		if(i&1){
			if(x==0) swap(a[i],b[i]),x^=1,y^=1;
		}
		else{
			if(y==0) swap(a[i],b[i]),y^=1,x^=1;
		}
		// cout<<i<<' '<<x<<' '<<y<<'\n';
	}
	// for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<'\n';
	// for(int i=1;i<=n;i++) cout<<b[i]<<' ';cout<<'\n';
	if(x>y) cout<<"Ajisai\n";
	else if(x==y) cout<<"Tie\n";
	else cout<<"Mai\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}