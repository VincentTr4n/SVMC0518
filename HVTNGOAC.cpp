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

void out(int ok){
	if(ok == -1) print("KHONG HOP LE");
	else if(ok == 0) print("KHONG DUNG");
	else print("DUNG");
}

int main() {
	SPEED;
	//freopen("in.txt", "r", stdin);
	string a;
	cin >> a;
	int n = len(a);
	stack<char> s;
	
	rep(i, n){
		if(a[i] != '(' && a[i] != ')'){
			out(-1);
			return 0;
		}
		if(a[i] == '(') s.push(a[i]);
		else{
			if(s.empty() || (s.top() != '(')){
				out(0);
				return 0;
			}
			s.pop();
		}
	}
	
	out(1);
	
	return 0;
}

