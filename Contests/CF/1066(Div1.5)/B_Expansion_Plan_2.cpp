#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,x,y;
	cin>>n>>x>>y;
	x=abs(x), y=abs(y);
	if(x<y) swap(x,y);
	string s; cin>>s;
	if(x>n) cout<<"NO\n";
	else{
		int p=count(s.begin(),s.end(),'4');
		int q=count(s.begin(),s.end(),'8');
		if(y<=q+n-x) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}