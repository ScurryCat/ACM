#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	string a,b;
	cin>>a>>b;
	int cnt[2]={0};
	for(int i=0;i<n;i++){
		if(b[i]=='0') cnt[i%2]++;
	}
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			if(cnt[(i+1)%2]) a[i]=0,cnt[(i+1)%2]--;
			// for(int j=(i+1)%2;j<n;j+=2){
			// 	if(b[j]=='0') swap(a[i],b[j]);
			// }
		}
	}
	bool ok=true;
	for(int i=0;i<n;i++){
		if(a[i]=='1') ok=false;
	}
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}