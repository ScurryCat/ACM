#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;

int n,m;
int a[N],ans[N],mn;

void solve(){
	cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    for(int j=31;j>=0;j--){
      if(a[i]&(1<<j)){
        ans[j]++;
        break;
      }
    }
  }
  for(int i=1;i<=30;i++){
    if(ans[i]&&ans[i]<2) mn=pow(2,i);
  }
  cout<<mn+1;
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