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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<20)+5;
const int D = 20;

/*
*/

int dis[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    queue<int> Q;
    vector<int> V;

    memset(dis, -1, sizeof(dis));

    int X=(1<<M)-1;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
        dis[a]=0;
        Q.push(a);
    }
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(int i=0; i<M; i++){
            int a=(1<<i);
            a=x^a;
            if(dis[a]==-1){
                dis[a]=dis[x]+1;
                Q.push(a);
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << M-dis[X^V[i]] << " ";
    }
    
    return 0;
}