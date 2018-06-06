#include <bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL)
#define REP(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define rep(i,n) REP(i,0,n-1)
#define FORD(i,b,a) for(int i=b,_a=a;i>=_a;i--)
#define ford(i,n) FORD(i,n-1,0)
#define sqr(x) ((x)*(x))
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define vll vector<ll>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define add push_back
#define len(arr) arr.size()
#define print(x) cout<<(x)<<endl
using namespace std;

#define MAX 1006

int n, fen[MAX];
pi a[MAX], res[MAX];

void update(int idx, int val = -1){
	for(int i = idx; i <= n ;i += i & -i) fen[i] += val;
}

int SUM(int idx){
	int sum = 0;
	for(int i = idx; i; i -= i & -i) sum += fen[i];
	return sum;
}

int bs(int x, int l, int r){
	if(l == r) return l;
	if(l + 1 == r) return SUM(l) >= x ? l : r;
	int mid = (l + r) / 2;
	int tmp = SUM(mid);
	if(tmp >= x) return bs(x, l, mid);
	else return bs(x, mid + 1, r);
}

bool cmp(pi x, pi y){
	return x.fi == y.fi ? x.se > y.se : x.fi < y.fi;
}

int main() {
	SPEED;
	int t;
	cin>>t;
	while(t--) {
		cin >> n;
		rep(i, n) cin >> a[i].fi;
		rep(i, n) cin >> a[i].se;
		REP(i, 1, n) fen[i] = i & -i;
		sort(a, a + n, cmp);
		rep(i, n){
			int idx = bs(a[i].se + 1, 1, n + 1);
			res[idx - 1] = a[i];
			update(idx);
		}
		rep(i, n) cout << res[i].fi <<" ";
		print("");
	}
	return 0;
}

