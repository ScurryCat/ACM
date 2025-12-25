#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	if(n==1) cout<<"1\n";
	else if(n==2) cout<<"9\n";
	else if(n==3) cout<<"29\n";
	else if(n==4) cout<<"56\n";
	else cout<<(n*(n-2)+(n-1))*5<<'\n';
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<n*(i-1)+j<<' ';
	// 	}
	// 	cout<<'\n';
	// }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}