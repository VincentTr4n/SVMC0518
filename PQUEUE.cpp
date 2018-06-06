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

int a[105];

int main() {
	SPEED;
	//freopen("in.txt", "r", stdin);
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		queue< pi > q;
		rep(i, n){
			cin >> a[i];
			q.push(pi(a[i], i));
		}
		
		sort(a, a + n);
		int top = n - 1;
		
		int ans = 0;
		while(!q.empty()){
			int x = q.front().fi;
			int y = q.front().se;
			q.pop();
			if(x != a[top]) q.push(pi(x, y));
			else{
				top--;
				ans++;
				if(y == m) break;
			}
		}
		print(ans);
		
	}
	return 0;
}

