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


int main() {
	SPEED;
	//freopen("in.txt", "r", stdin);
	int n, x;
	while(1){
		cin >> n;
		if(n == 0) break;
		
		stack<int> s;
		vi res;
		rep(i, n){
			cin >> x;
			while(!s.empty() && s.top() < x){
				res.add(s.top());
				s.pop();
			}
			s.push(x);
		}
		
		while(!s.empty()){
			res.add(s.top());
			s.pop();
		}
		
		bool ok = 1;
		rep(i, n){
			if(res[i] != i + 1){
				ok = 0;
				break;
			}
		}
		
		print(ok ? "yes" : "no");
	}
	
	return 0;
}

