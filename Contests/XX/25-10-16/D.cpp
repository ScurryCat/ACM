#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> yj;
int ans,cnt;

bool ok1(){

}

bool ok2(){

}

void solve(){
  int n,x,y,r;
  cin>>n>>x>>y>>r;
  yj.resize(n+10);
  for(int i=0;i<n;i++){
    yj[i]={i,i};
  }
  
  for(int i=0;i<x;i++){
    int a,b;
    cin>>a>>b;
    yj[a-1].second=yj[b-1].second;
  }

  for(int i=0;i<y;i++){
    int a,b,c;
    cin>>a>>b>>c;
  }

  int z=0;
  for(int i=0;i<n;i++){
    int c=0;
    for(int j=0;j<n;j++){
      if(yj[j].second==i) c++;
    }
    z=max(z,c);
  }
  
  if(r<z){
    cout<<"-1 0";
    return;
  }


  // if(ans){
  //   cout<<ans<<' '<<cnt;
  // }
  // else cout<<"-1 0";
}

int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

  int qaq=1;
  // cin>>qaq;
  while(qaq--) solve();
  return 0;
}


/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m1,m2,r,can[1<<15],a,b,c,trans[1<<15],cnt=1,dis[1<<15],ans[1<<15];
queue<int>q;
int lowbit(int x){
    return x&-x;
}
int popcount(int x){
    int ret=0;
    while(x){
        ret++;
        x-=lowbit(x);
    }
    return ret;
}//求出一个二进制数里 1 的个数
void bfs(){
    memset(dis,0x3f,sizeof dis);
    q.push(0);
    dis[0]=0;
    ans[0]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=1;i<=cnt;i++){
            int v=(u^trans[i]);
            if(can[v]!=-1){
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    ans[v]=ans[u];
                    q.push(v);
                }
                else if(dis[v]==dis[u]+1){
                    ans[v]+=ans[u];
                }
            }
        }
    }
}//BFS 求最短路及方案，和 P1144 最短路计数类似，其实就是把枚举每一条边换成了枚举转移方案
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m1>>m2>>r;
    for(int i=1;i<=m1;i++){
        cin>>a>>b;
        for(int j=0;j<(1<<n);j++){
            if((((j>>(a-1))&1)^((j>>(b-1))&1))==1){//这里 (j>>(a-1))&1) 是取出第 a 位，然后两位异或判断是否在同一边
                can[j]=-1;
            }
        }
    }
    for(int i=1;i<=m2;i++){
        cin>>a>>b>>c;
        for(int j=0;j<(1<<n);j++){
            if((((j>>(a-1))&1)^((j>>(b-1))&1))==1&&(((j>>(a-1))&1)^((j>>(c-1))&1))==1){//和上面的差不多，分别判断 a 与 b，a 与 c 的关系
                can[j]=-1;
            }
        }
    }
    for(int i=0;i<(1<<n);i++){//预处理转移方案
        if(popcount(i)<=r){
            trans[cnt]=i;
            cnt++;
        }
    }
    cnt--;
    bfs();
    cout<<((dis[(1<<n)-1]!=0x3f3f3f3f3f3f3f3f)?dis[(1<<n)-1]:-1)<<" "<<ans[(1<<n)-1];//记得判断是否有解
    return 0;
}
*/