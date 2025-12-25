#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,pos;
int a[N];

void solve(){
	cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==n) pos=i;
  }
  bool ok=true;
  int i=1,j=n;
  // while(a[i+1]>a[i]) i++;
  // while(a[j-1]>a[j]) j--;
  // if(i!=j) ok=false;
  for(int i=1;i<pos;i++) if(a[i]>a[i+1]) ok=false;
  for(int i=pos;i<n;i++) if(a[i]<a[i+1]) ok=false;
  if(ok) cout<<"YES\n";
  else cout<<"NO\n";
}

// void solve(){
//   cin>>n;
//   bool ok=true;
//   for(int i=1;i<=n;i++){
//     cin>>a[i];
//     if(abs(n/2-i)<a[i]) ok=false;
//   }
//   if(ok) cout<<"YES\n";
//   else cout<<"NO\n";
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int T = 1;
    cin>>T;
    while(T--) solve();
    return 0;
}