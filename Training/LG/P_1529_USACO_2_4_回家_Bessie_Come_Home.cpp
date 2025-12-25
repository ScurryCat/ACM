#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e2+20+9, mod = 998244353;

struct edge{int v,w;};
char id;
int m,ans;
int d[N][N];
vector<edge> e[N];

// void Floyd(){
//   ans=0x3f3f3f3f;
//   memset(d,0x3f,sizeof d);
//   for(int u=1;u<='z'-'A'+1;u++){
//     for(auto ed : e[u]){
//       int v=ed.v, w=ed.w;
//       d[u][v]=w;
//     }
//     d[u][u]=0;
//   }

//   for(int k=1;k<='z'-'A'+1;k++){
//     if(k=='Z'-'A'+1) k='a'-'A'+1;
//     for(int i=1;i<='z'-'A'+1;i++){
//       if(i=='Z'-'A'+1) i='a'-'A'+1;
//       for(int j=1;j<='z'-'A'+1;j++){
//         if(j=='Z'-'A'+1) j='a'-'A'+1;
//         d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//       }
//     }
//   }

//   // for(int i=1;i<='z'-'A'+1;i++){
//   //   if(i=='Z'-'A'+1) i='a'-'A'+1;
//   //   for(int j=1;j<='z'-'A'+1;j++){
//   //     if(j=='Z'-'A'+1) j='a'-'A'+1;
//   //     cout<<d[i][j]<<' ';
//   //   }
//   //   cout<<'\n';
//   // }

//   for(int u=1;u<'Z'-'A'+1;u++){
//     if(ans>d[u]['Z'-'A'+1]){
//       ans=d[u]['Z'-'A'+1];
//       id='A'+u-1;
//     }
//   }
// }

// void solve(){
// 	cin>>m;
//   for(int i=1;i<=m;i++){
//     char u,v,w;
//     cin>>u>>v>>w;
//     e[u-'A'+1].push_back({v-'A'+1,w-'0'});
//   }
//   Floyd();
//   cout<<id<<' '<<ans;
// }

void Floyd(){
  ans=0x3f3f3f3f;
  memset(d,0x3f,sizeof d);
  for(int u='A';u<='z';u++){
    for(auto ed : e[u]){
      int v=ed.v,w=ed.w;
      d[u][v]=min(d[u][v],w);
      // cout<<u<<' '<<v<<' '<<d[u][v]<<'\n';
    }
    d[u][u]=0;
    if(u=='Z') u='a'-1;
  }

  // for(int i='A';i<='z';i++){
  //   for(int j='A';j<='z';j++){
  //     cout<<d[i][j]<<' ';
  //     if(j=='Z') j='a'-1;
  //   }
  //   cout<<'\n';
  //   if(i=='Z') i='a'-1;
  // }

  for(int k='A';k<='z';k++){
    for(int i='A';i<='z';i++){
      for(int j='A';j<='z';j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        if(j=='Z') j='a'-1;
      }
      if(i=='Z') i='a'-1;
    }
    if(k=='Z') k='a'-1;
  }
  for(int u='A';u<'Z';u++){
    if(ans>d[u]['Z']){
      ans=d[u]['Z'];
      id=u;
    }
  }
}

void solve(){
  cin>>m;
  for(int i=1;i<=m;i++){
    char a,b;
    int w;
    cin>>a>>b>>w;
    int u=(int)a,v=(int)b;
    // cout<<u<<' '<<v<<' '<<w<<'\n';
    e[u].push_back({v,w});
    e[v].push_back({u,w});
  }

  Floyd();
  cout<<id<<' '<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}