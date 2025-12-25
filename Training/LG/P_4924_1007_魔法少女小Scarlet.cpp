#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 509, mod = 998244353;

int n,m,x,y,r,z;
int a[N][N], t[N][N];

void spin(){
  // for(int i=x-r;i<=x+r;i++)
  //     for(int j=y-r;j<=y+r;j++)
  //       t[j][i] = a[i][j];
  //   for(int i=x-r;i<=x+r;i++)
  //     for(int j=y-r;j<=y+r;j++)
  //       a[i][j] = t[i][j];
  // if(z){
  //   for(int j=y-r;j<=y+r;j++)
  //     for(int i=1;i<=r;i++)
  //       swap(a[x-i][j],a[x+i][j]);
  // }
  // else{
  //   for(int i=x-r;i<=x+r;i++)
  //     for(int j=1;j<=r;j++)
  //       swap(a[i][y-j],a[i][y+j]);
  // }
  if(z){
    for(int i=x-r;i<=x+r;i++)
      for(int j=y-r;j<=y+r;j++)
        t[x+y-j][y-x+i] = a[i][j];  // 逆时针旋转，将第i行j列投射到 倒数第j行第i列
    for(int i=x-r;i<=x+r;i++)
      for(int j=y-r;j<=y+r;j++)
        a[i][j] = t[i][j];
  }
  else{
    for(int i=x-r;i<=x+r;i++)
      for(int j=y-r;j<=y+r;j++)
        t[x-y+j][x+y-i] = a[i][j];  // 顺时针旋转，将第i行j列投射到 第j行倒数第i列
    for(int i=x-r;i<=x+r;i++)
      for(int j=y-r;j<=y+r;j++)
        a[i][j] = t[i][j];
  }
}

void qwq_(){
	cin>>n>>m;
  for(int i=1,x=0;i<=n;i++)
    for(int j=1;j<=n;j++)
      a[i][j] = ++x;
  
  for(int i=1;i<=m;i++){
    cin>>x>>y>>r>>z;
    spin();
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) cout<<a[i][j]<<' ';
    cout<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}