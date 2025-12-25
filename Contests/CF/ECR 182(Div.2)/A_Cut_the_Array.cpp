#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 40+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;
int l1,l2,r1,r2;
int a[N],s[N];

// void solve(){
// 	cin>>n;
//   // for(int i=1;i<=n;i++){
//   //   cin>>a[i];
//   //   s[i]=s[i-1]+a[i];
//   // }
//   // l1=0,l2=0,r1=0,r2=0;
//   // bool find1=true,find2=true;
//   // for(int i=1;i<=n;i++){
//   //   if((s[i]%3==a[n]%3)&&find1) l1=i,find1=false;
//   //   else if(!find1&&s[i]-){
      
//   //   }
//   // }
// }

void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    s[i]=s[i-1]+a[i];
  }
  for(int i=1;i+1<n;i++){
    for(int j=i+1;j<n;j++){
      // cout<<s[i]<<' '<<s[j]-s[i]<<' '<<s[n]-s[j]<<'\n';
      if((s[i]%3==(s[j]-s[i])%3)&&((s[j]-s[i])%3==(s[n]-s[j])%3)){
        cout<<i<<' '<<j<<'\n';
        return;
      }
      if((s[i]%3!=(s[j]-s[i])%3)&&((s[i])%3!=(s[n]-s[j])%3)&&((s[j]-s[i])%3!=(s[n]-s[j])%3)){
        cout<<i<<' '<<j<<'\n';
        return;
      }
    }
  }
  cout<<"0 0\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int T = 1;
    cin>>T;
    while(T--) solve();
    return 0;
}