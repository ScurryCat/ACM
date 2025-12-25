#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+9;
const int M = 2e5+9;

int n,m,ans;
int a[N];

bool cmp(int a,int b){
  if(a&1&&b&1) return a<b;
  else if(!(a&1)&&!(b&1)) return a<b;
  return a&1?false:true;
}

void solve(){
	cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=n;i++){
    cout<<a[i]<<' ';
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