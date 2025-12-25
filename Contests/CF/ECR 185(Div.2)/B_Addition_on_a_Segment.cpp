#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	ll mx=0, cnt=0;
	int n; cin>>n;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		if(x){
			cnt++;
			mx+=x-1;
		}
	}
	if(mx>=n) cout<<cnt<<'\n';
	else cout<<cnt-(n-mx)+1<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}