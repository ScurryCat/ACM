#include <bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,m,q;

struct node{
	int l,r,sum,add,mul;
}tr[4*N];
int a[N];

void pushup(int p){
	tr[p].sum=((ll)tr[lc].sum+tr[rc].sum)%m;
}

void pushdown(int p){
	if(tr[p].mul!=1){
		tr[lc].sum=((ll)tr[lc].sum*tr[p].mul)%m;
		tr[rc].sum=((ll)tr[rc].sum*tr[p].mul)%m;
		tr[lc].mul=(ll)tr[lc].mul*tr[p].mul%m;
		tr[rc].mul=(ll)tr[rc].mul*tr[p].mul%m;
		tr[lc].add=(ll)tr[lc].add*tr[p].mul%m;
		tr[rc].add=(ll)tr[rc].add*tr[p].mul%m;
		tr[p].mul=1;
	}
	if(tr[p].add){
		tr[lc].sum=((ll)tr[lc].sum+(ll)tr[p].add*(tr[lc].r-tr[lc].l+1))%m;
		tr[rc].sum=((ll)tr[rc].sum+(ll)tr[p].add*(tr[rc].r-tr[rc].l+1))%m;
		tr[lc].add=((ll)tr[lc].add+(ll)tr[p].add)%m;
		tr[rc].add=((ll)tr[rc].add+(ll)tr[p].add)%m;
		tr[p].add=0;
	}
}

void build(int p,int x,int y){
	tr[p]={x,y,a[x]%m,0,1};
	if(x==y) return;
	int mid=x+y>>1;
	build(lc,x,mid);
	build(rc,mid+1,y);
	pushup(p);
}

void updateadd(int p,int x,int y,int k){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].sum=((ll)tr[p].sum+(ll)k*(tr[p].r-tr[p].l+1))%m;
		tr[p].add=((ll)tr[p].add+k)%m;
		return;
	}
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=mid) updateadd(lc,x,y,k);
	if(y>mid) updateadd(rc,x,y,k);
	pushup(p);
}

void updatemul(int p,int x,int y,int k){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].sum=(ll)tr[p].sum*k%m;
		tr[p].mul=(ll)tr[p].mul*k%m;
		tr[p].add=(ll)tr[p].add*k%m;
		return;
	}
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=mid) updatemul(lc,x,y,k);
	if(y>mid) updatemul(rc,x,y,k);
	pushup(p);
}

int query(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum%m;
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p);
	ll sum=0;
	if(x<=mid) sum=(sum+query(lc,x,y))%m;
	if(y>mid) sum=(sum+query(rc,x,y))%m;
	return sum%m;
}

void qwq_(){
	cin>>n>>q>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=n;i++) cout<<query(1,i,i)<<' ';cout<<'\n';
	while(q--){
		int c,x,y; cin>>c>>x>>y;
		if(c==1){
			int k; cin>>k;
			updatemul(1,x,y,k);
		}
		else if(c==2){
			int k; cin>>k;
			updateadd(1,x,y,k);
		}
		else{
			cout<<query(1,x,y)<<'\n';
		}
		for(int i=1;i<=n;i++) cout<<query(1,i,i)<<' ';cout<<'\n';
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