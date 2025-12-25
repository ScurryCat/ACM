#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+9;

int n,ans;
int h[N],to[N<<1],ne[N<<1],tot=1;
int dep[N];

inline void add(int u,int v){
    to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    ans=max(ans,dep[u]);
    for(int i=h[u];i;i=ne[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        if(u) add(i,u), add(u,i);
        if(v) add(i,v), add(v,i);
    }
    dfs(1,0);
    cout<<ans;
}