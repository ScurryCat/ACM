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
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]) continue;
		int z=a[i]^b[i];
		if(i&1){
			if(x<y && (x^z > x || y^z < y)) swap(a[i],b[i]),x^=z,y^=z;
		}
		else{
			if(y<x && (y^z > y || x^z < x)) swap(a[i],b[i]),y^=z,x^=z;
		}
	}
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