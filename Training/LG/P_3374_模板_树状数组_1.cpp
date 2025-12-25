#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 5e5+9, mod = 998244353;

ll w[N];

template <typename T>
class SegmentTree{
	public:
		SegmentTree(int n){
			tr.resize((n+1)<<2);
		}

		void build(int p,int l,int r){
			tr[p]={l,r,w[l],0};
			if(l==r) return;
			int m=l+r>>1;
			build(lc(p),l,m);
			build(rc(p),m+1,r);
			pushup(p);
		}

		void update(int p,int x,int y,T k){
			if(x<=tr[p].l&&tr[p].r<=y){
				tr[p].sum+=k*(tr[p].r-tr[p].l+1);
				tr[p].add+=k;
				return;
			}
			int m=tr[p].l+tr[p].r>>1;
			pushdown(p);
			if(x<=m) update(lc(p),x,y,k);
			if(y>m) update(rc(p),x,y,k);
			pushup(p);
		}

		T query(int p,int x,int y){
			if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum;
			int m=tr[p].l+tr[p].r>>1;
			T sum=0;
			pushdown(p);
			if(x<=m) sum+=query(lc(p),x,y);
			if(y>m) sum+=query(rc(p),x,y);
			return sum;
		}

	private:
		struct node{
			int l,r;
			T sum,add;
		};
		
		vector<node> tr;

		int lc(int p){
			return p<<1;
		}

		int rc(int p){
			return p<<1|1;
		}

		void pushup(int p){
			tr[p].sum=tr[lc(p)].sum+tr[rc(p)].sum;
		}

		void pushdown(int p){
			if(tr[p].add){
				tr[lc(p)].sum+=tr[p].add*(tr[lc(p)].r-tr[lc(p)].l+1);
				tr[rc(p)].sum+=tr[p].add*(tr[rc(p)].r-tr[rc(p)].l+1);
				tr[lc(p)].add+=tr[p].add;
				tr[rc(p)].add+=tr[p].add;
				tr[p].add=0;
			}
		}
};

void qwq_(){
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	SegmentTree<ll> tr(n+5);
	tr.build(1,1,n);
	while(m--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			tr.update(1,x,x,y);
		}
		else{
			cout<<tr.query(1,x,y)<<'\n';
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