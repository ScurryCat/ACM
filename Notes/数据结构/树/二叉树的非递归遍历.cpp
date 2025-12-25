#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

int n,m;
int stk[N],tt;

struct Node{
  int n;
  Node *l,*r;
};

struct node{
  int l,r;
}bt[N];

void pre(int n){
  tt=0;
  stk[++tt]=n;
  while(tt){
    n=stk[tt--];
    cout<<n<<' ';
    if(bt[n].r) stk[++tt]=bt[n].r;
    if(bt[n].l) stk[++tt]=bt[n].l;
  }
  cout<<'\n';
}

// void mid(int n){
//   bool vis[N];
//   memset(vis,0,sizeof vis);
//   tt=0;
//   stk[++tt]=n;
//   while(tt){
//     n=stk[tt];
//     if(bt[n].l&&!vis[n]) stk[++tt]=bt[n].l,vis[n]=true;
//     else{
//       cout<<stk[tt--]<<' ';
//       if(bt[n].r){
//         stk[++tt]=bt[n].r;
//       }
//     }
//   }
//   cout<<'\n';
// }

void mid(int h){
  tt=0;
  while(tt||h){
    if(h){
      stk[++tt]=h;
      h=bt[h].l;
    }
    else{
      h=stk[tt--];
      cout<<h<<' ';
      h=bt[h].r;
    }
  }
  cout<<'\n';
}

// void post(int n){
//   bool vis[N];
//   memset(vis,0,sizeof vis);
//   tt=0;
//   stk[++tt]=n;
//   while(tt){
//     n=stk[tt];
//     if(bt[n].l&&!vis[bt[n].l]) vis[bt[n].l]=true,stk[++tt]=bt[n].r;
//     else if(bt[n].r&&!vis[bt[n].r]) vis[bt[n].r]=true,stk[++tt]=bt[n].r;
//     else cout<<stk[tt--]<<' ';
//   }
//   cout<<'\n';
// }

// 双栈法
void post(int h){
  tt=0;
  while(tt||h){
    if(h){
      stk[++tt]=h;
      h=bt[h].l;
    }
    else{
      h=stk[tt--];
      stk[++tt]=bt[h].r;
    }
  }
  cout<<'\n';
}

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>bt[i].l>>bt[i].r;
  }
  pre(1);
  mid(1);
  post(1);
  return 0;
}