#include <bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int w[N];
struct node{
	int l,r;
	int sum,lazy;
}tr[N<<4];

void pushup(int p){
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int p){
	tr[p].lazy%=2;
	if(tr[p].lazy){
		tr[lc].sum=tr[lc].r-tr[lc].l+1-tr[lc].sum;
		tr[rc].sum=tr[rc].r-tr[rc].l+1-tr[rc].sum;
		tr[lc].lazy^=tr[p].lazy;
		tr[rc].lazy^=tr[p].lazy;
		tr[p].lazy=0;
	}
}

void build(int p,int l,int r){
	tr[p].l=l; tr[p].r=r; tr[p].sum=w[l];
	if(l==r) return;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}

void update(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].sum=tr[p].r-tr[p].l+1-tr[p].sum;
		tr[p].lazy++;
		return;
	}
	int m=tr[p].r+tr[p].l>>1;
	pushdown(p);
	if(x<=m) update(lc,x,y);
	if(y>m) update(rc,x,y);
	pushup(p);
}

int query(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum;
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	int sum=0;
	if(x<=m) sum+=query(lc,x,y);
	if(y>m) sum+=query(rc,x,y);
	return sum;
}

void qwq_(){
	int n,m; cin>>n>>m;
	// for(int i=1;i<=n;i++) cin>>w[i];
	build(1,1,n);
	while(m--){
		int c,x,y;
		cin>>c>>x>>y;
		if(c){
			cout<<query(1,x,y)<<'\n';
		}
		else{
			update(1,x,y);
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