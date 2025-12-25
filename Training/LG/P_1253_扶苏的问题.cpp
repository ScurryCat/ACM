#include <bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e6+9, mod = 998244353;

int n,q;
ll a[N];

struct node{
	int l,r;
	ll max,add,ex;
    int flag;
}tr[N<<2];

inline void pushup(int p){
	tr[p].max=max(tr[lc].max,tr[rc].max);
}

inline void pushdown(int p){
	if(tr[p].flag){
		tr[lc].max=tr[p].ex;
		tr[rc].max=tr[p].ex;
		tr[lc].ex=tr[p].ex;
		tr[rc].ex=tr[p].ex;
		tr[lc].flag=1;
		tr[rc].flag=1;
		tr[lc].add=0;
		tr[rc].add=0;
		tr[p].ex=0;
		tr[p].flag=0;
	}
	if(tr[p].add){
		tr[lc].max+=tr[p].add;
		tr[rc].max+=tr[p].add;
		tr[lc].add+=tr[p].add;
		tr[rc].add+=tr[p].add;
		tr[p].add=0;
	}
}

inline void build(int p,int x,int y){
	tr[p]={x,y,a[x],0,0,0};
	if(x==y) return;
	int m=x+y>>1;
	build(lc,x,m);
	build(rc,m+1,y);
	pushup(p);
}

inline ll query(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].max;
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	ll r=-2e18;
	if(x<=m) r=max(r,query(lc,x,y));
	if(y>m) r=max(r,query(rc,x,y));
	return r; 
}

inline void exchange(int p,int x,int y,ll k){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].max=k;
		tr[p].ex=k;
		tr[p].add=0;
		tr[p].flag=1;
		return;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) exchange(lc,x,y,k);
	if(y>m) exchange(rc,x,y,k);
	pushup(p);
}

inline void update(int p,int x,int y,ll k){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].max+=k;
		tr[p].add+=k;
		return;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y,k);
	if(y>m) update(rc,x,y,k);
	pushup(p);
}

void qwq_(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			ll k; cin>>k;
			exchange(1,x,y,k);
		}
		else if(op==2){
			ll k; cin>>k;
			update(1,x,y,k);
		}
		else{
			cout<<query(1,x,y)<<'\n';
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