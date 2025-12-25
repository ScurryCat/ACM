#include <bits/stdc++.h>
using namespace std;

const int mod = 1e3;
using ll = long long;

// 1.巴什博弈，只涉及到sg表
void bash2(int n,int m){
  vector<int> sg(n+1),ap(m+1);
  for(int i=1;i<=n;i++){
    fill(ap.begin(),ap.end(),0);
    for(int j=1;j<=m && j<=i;j++){
      ap[sg[i-j]]=1;
    }
    for(int j=0;j<=m;j++){
      if(!ap[j]){
        sg[i]=j;
        break;
      }
    }
  }
  cout<<"测试样例n="<<n<<",m="<<m<<":\n";
  for(int i=0;i<=n;i++) cout<<"sg("<<i<<")="<<sg[i]<<'\n';
}

// 2.nim博弈，利用到了sg定理
string nim2(int n,int a[]){
  int mx=0,xo=0;
  for(int i=0;i<n;i++) mx=max(mx,a[i]);
  vector<int> sg(mx+1),ap(mx+1);
  for(int i=1;i<=mx;i++){
    fill(ap.begin(),ap.end(),0);
    for(int j=1;j<=mx && j<=i;j++){
      ap[sg[i-j]]=1;
    }
    for(int j=0;j<=mx;j++){
      if(!ap[j]){
        sg[i]=j;
        break;
      }
    }
  }
  for(int i=0;i<=n;i++){
    xo ^= sg[a[i]];
  }
  return (xo?"先手":"后手");
}

string nim(int n,int a[]){
  int xo=0;
  for(int i=0;i<n;i++){
    xo ^=a[i];
  }
  return (xo?"先手":"后手");
}

// 3.两堆石子的巴什博弈
void fun(int a,int b,int m){
  int mx=max(a,b);
  vector<int> sg(mx+1),ap(m+1);
  for(int i=1;i<=mx;i++){
    fill(ap.begin(),ap.end(),0);
    for(int j=1;j<=m&&j<=i;j++){
      ap[sg[i-j]]=1;
    }
    for(int j=0;j<=m;j++){
      if(!ap[j]){
        sg[i]=j;
        break;
      }
    }
  }
  // for(int i=0;i<=mx;i++) printf("sg(%d)=%d\n",i,sg[i]);
  cout<<(sg[a]^sg[b]);
}

int main(){

  srand(time(0));
  int a=20,b=30,m=5;
  fun(a,b,m);
  // int n=100, m=10;
  // bash2(n,m);

  // int n=5;
  // int a[]={5,13,27,30,25};
  // nim2(n,a);

  // int testcase = 1;
  // for(int i=1;i<=testcase;i++){
  //   int n=rand()%mod;
  //   int a[n];
  //   for(int i=0;i<n;i++) a[i]=rand()%mod;
  //   if(nim(n,a)!=nim2(n,a)) cout<<"no";
  //   else cout<<"yes";
  // }

  return 0;
}