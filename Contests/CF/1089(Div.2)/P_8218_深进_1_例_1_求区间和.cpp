#include <stdio.h>

const int N = 100004;
int n, q;
int a[N], s[N];

void solve1(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	while(q--){
		int l, r;
		scanf("%d %d",&l, &r);
		int ans=0;
		for(int i=l; i<=r; i++){
			ans+=a[i];
		}
		printf("%d\n",ans);
	}
}

void solve2(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	scanf("%d",&q);
	while(q--){
		int l, r;
		scanf("%d %d",&l, &r);
		printf("%d\n",s[r]-s[l-1]);
	}
}

int main(){
	
	solve2();

	return 0;
}