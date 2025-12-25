#include <bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1

typedef long long ll;
typedef pair<int,int> PII;

const int N = 5e5+9, mod = 998244353;

int n,m;
ll a[N];
struct node{
	int l,r;
	ll max,lmax,rmax,sum;
}tr[N<<2];

inline void pushup(int p){
	tr[p].sum=tr[lc].sum+tr[rc].sum;
	tr[p].max=
}

inline void pushdown(int p){

}

inline void build(int p,int x,int y){
	tr[p]={x,y,a[x],a[x],a[x],a[x]};
	if(x==y) return;
	int m=x+y>>1;
	build(lc,x,m);
	build(rc,m+1,y);
	pushup(p);
}

inline void update(int p,int x,int k){
	if(tr[p].l==tr[p].r){
		tr[p].max=k;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,k);
	else update(rc,x,k);
	pushup(p);
}

inline ll query(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].max;
	int m=tr[p].l+tr[p].r>>1;
	ll r=-2e18;
	if(x<=m) r=max(r,query(lc,x,y));
	if(y>m) r=max(r,query(rc,x,y));
	return r;
}

void qwq_(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--){
		int c,a,b; cin>>c>>a>>b;
		if(c==1){
			if(a>b) swap(a,b);
			cout<<query(1,a,b)<<'\n';
		}
		else{
			update(1,a,b);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}