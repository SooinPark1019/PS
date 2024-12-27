#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

*/
vector<int> failure(string& s){
    vector<int> f(s.length());
    int j=0;
    for(int i=1; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}//실패함수 반환
int ans=0;
vector<int> f;
string P;
vector<pair<int, char>> graph[500005];

void sol(int cur_node, int par, int cur_index){
    for(auto p : graph[cur_node]){
        if(p.first==par) continue;
        int a=cur_index;
        while(a>0&&p.second!=P[a]) a=f[a-1];
        if(P[a]==p.second) a++;
        if(a==P.length()){
            ans++;
            a=f[a-1];
        }
        sol(p.first, cur_node, a);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> P;
    f=failure(P);
    /*for(auto i : f){
        cout << i << endl;
    }*/
    sol(1, -1, 0);
    cout << ans;
    return 0;
}
