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
	freopen("in.txt", "r", stdin);
	string a;
	int tc = 1;
	while(1){
		cin >> a;
		if(a[0] == '-') break;
		int res = 0, cnt = 0;
		rep(i, len(a)){
			if(a[i] == '{') cnt++;
			else if(!cnt){
				cnt = 1;
				res++;
			}
			else cnt--;
		}
		cout << tc++ << ". " << res + cnt / 2 << endl;
	}
	
	return 0;
}

