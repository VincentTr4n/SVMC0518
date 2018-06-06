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

char a[405];

int main() {
	SPEED;
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		int cnt = 0;
		char c;
		cin >> c;
		if(c == '(') cnt++;
		while(cnt){
			cin >> c;
			if(c == '(') cnt++;
			else{
				if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^') || (c == '%')) a[cnt - 1] = c;
				else if(c == ')') cout << a[--cnt];
				else cout << c;
			}
		}
		print("");
	}
	
	return 0;
}

