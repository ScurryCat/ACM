#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 4e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;

//4
//4 2 1 3 4 2 3 1
//4 2 3 2 4 3 1 1
//5
//5 2 4 3 1 5 4 2 1 3 
//5 3 4 2 3 5 4 2 1 1
//6
//6 4 5 1 2 4 6 5 3 1 2 3
//7
//7 5 6 3 4 2 5 7 6 3 1 2 4 1
void solve(){
	cin>>n;
	m=n;
	VI a(n+n+1,0);
	// vector<bool> ;

	for(int i=n;i>=1;i--){
		for(int j=1;j+i<=n+n;j++){
			if(!a[j]&&!a[j+i]){
				a[j]=a[j+i]=i;
				break;
			}
			if(j==n+n-i)
		}
	}
	for(int i=1;i<=n+n;i++){
		if(a[i]) cout<<a[i]<<' ';
		else cout<<"1 ";
	}	
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}