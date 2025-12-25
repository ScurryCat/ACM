#include <bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

ll w[N];
struct node{
	int l,r;
	ll sum,add;
}tr[N<<2];

void pushup(int p){
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int p){
	if(tr[p].add){
		tr[lc].sum+=tr[p].add*(tr[lc].r-tr[lc].l+1);
		tr[rc].sum+=tr[p].add*(tr[rc].r-tr[rc].l+1);
		tr[lc].add+=tr[p].add;
		tr[rc].add+=tr[p].add;
		tr[p].add=0;
	}
}

void build(int p,int l,int r){
	tr[p]={l,r,w[l],0};
	if(l==r) return;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}

ll query(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum;
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	ll sum=0;
	if(x<=m) sum+=query(lc,x,y);
	if(y>m) sum+=query(rc,x,y);
	return sum;
}

void update(int p,int x,int y,ll k){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].sum+=k*(tr[p].r-tr[p].l+1);
		tr[p].add+=k;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=m) update(lc,x,y,k);
	if(y>m) update(rc,x,y,k);
	pushup(p);
}

void qwq_(){
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	build(1,1,n);
	while(m--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
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