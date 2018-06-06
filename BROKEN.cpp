#include <bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL)
#define REP(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define rep(i,n) REP(i,0,n-1)
#define FORD(i,b,a) for(int i=b,_a=a;i>=_a;i--)
#define ford(i,n) FORD(i,n-1,0)
#define sqr(x) ((x)*(x))
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define add push_back
#define len(arr) arr.size()
#define print(x) cout<<(x)<<endl
using namespace std;

int a[257];

int main() {
	SPEED;
	while(1){
		int m;
		cin >> m;
		cin.ignore();
		if(m == 0) break;
		string s;
		getline(cin, s);
		
		memset(a, 0, sizeof(a));
		int n = len(s);
		int res = 0, j = 0, i = 0, d = 0;
 
        while(i < n)
        {
            if(a[s[i]] == 0)
            {
                if(d < m)  d += a[s[i++]] = 1;
                else if(d == m)
                {
                    res = max(res, i - j);
                    while(d == m)
                    {
                        a[s[j]]--;
                        if(a[s[j]] == 0) d--;
                        j++;
                    }
                }
            }
            else a[s[i++]]++;
        }
 
        print(max(res, i - j));
		
		fflush(stdin);
	}
	return 0;
}

