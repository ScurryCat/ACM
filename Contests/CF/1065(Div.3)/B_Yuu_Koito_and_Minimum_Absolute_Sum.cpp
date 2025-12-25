#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<int> a(n+1,0);
	int x=0,flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=a[n]-a[1];
	if(a[1]==-1){
		a[1]=a[n];
		x=0;
	}
	if(a[n]==-1){
		a[n]=a[1];
		x=0;
	}
	cout<<abs(x)<<'\n';
	for(int i=1;i<=n;i++){
		if(a[i]==-1) cout<<"0 ";
		else cout<<a[i]<<' ';
	}
	
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}