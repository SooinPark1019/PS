#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define int long long
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
각 서브그리드마다 최대 하나의 constraint만 포함 가능

왼쪽위의 서브그리드부터 생각한다고 하자

*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> V(N+1);
    for(int i=1; i<=N; i++){
        cin >> V[i];
    }
    int s, e;
    cin >> s >> e;
    vector<int> vis(N+1, -1);
    queue<int> Q;
    Q.push(s);
    vis[s]=0;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(int i=x; i<=N; i+=V[x]){
            if(vis[i]!=-1) continue;
            vis[i]=vis[x]+1;
            Q.push(i);
        }
        for(int i=x; i>=1; i-=V[x]){
            if(vis[i]!=-1) continue;
            vis[i]=vis[x]+1;
            Q.push(i);
        }
    }
    cout << vis[e];
    return 0;
}
