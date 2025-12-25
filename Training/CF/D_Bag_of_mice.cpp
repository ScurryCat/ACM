#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int w,b;
	scanf("%d%d",&w,&b);
	vector<vector<double>> f(w+1,vector<double>(b+1));
	for(int i=1;i<=b;i++) f[0][i]=0;
	for(int i=1;i<=w;i++) f[i][0]=1;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=b;j++){
			f[i][j] += (double)i/(i+j);
			if(j>=2) f[i][j] += (double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*f[i-1][j-2];
			if(j>=3) f[i][j] += (double)j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*f[i][j-3];
		}
	}
	printf("%.9lf",f[w][b]);
}

int main(){
	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}