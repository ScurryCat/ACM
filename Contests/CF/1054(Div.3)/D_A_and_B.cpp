#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;

void solve(){
	cin>>n;
	string s;
	// s.resize(n);
	// for(int i=0;i<n;i++){
	// 	cin>>s[i];
	// }
	cin>>s;
	if(n==1||n==2){
		cout<<"0\n";
		return;
	}
	else{
		bool ok=true;
		for(int i=0,cnt=0;i+1<n;i++){
			if(s[i]!=s[i+1]) cnt++;
			if(cnt>2){
				ok=false;
				break;
			}
		}
		if(ok) cout<<"0\n";
		else{
			string ss=s;
			int cnt1=0,cnt2=0;
			int i=0,j=n-1;
			while(s[i]==s[i+1]&&i<j) i++;
			while(s[j]==s[j-1]&&i<j) j--;
			
			cout<<min(cnt1,cnt2)<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}