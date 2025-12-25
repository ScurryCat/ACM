#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	ll n,c=0ll,s=0ll;	
	cin>>n;
	VI a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			c+=a[i]*2ll;
			a[i]=a[i-1]=0ll;
			s+=2ll;
			i++;
		}
	}
	for(int i=n-1;~i;i--){
		if(!a[i]) continue;
		for(int j=i-1;~j;j--){
			if(!a[j]) continue;
			if(c+a[j]>a[i]){
				c+=a[i]+a[j];
				a[i]=a[j]=0ll;
				s+=2;
				break;
			}
			else break;
		}
		if(!a[i]) break;
		if(c>a[i]){
			c+=a[i];
			s++;
			break;
		}
	}
	if(s<3ll) cout<<"0\n";
	else cout<<c<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}