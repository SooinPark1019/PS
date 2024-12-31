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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
뒤에서부터 생각한다?

N=4라고 해보자
3 4 2 1
N=짝수일 때는 혹시 그냥 전체의 절반일까?
N=6
5 6 4 3 1 2

N=홀수일 때는?

*/
vector<pii> graph[55];
struct edge {
    int x, y, w;
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int K, N;
    cin >> K >> N;
    int S=K+1;

    vector<edge> graph;

    for(int i=0; i<=K; i++){
        graph.push_back({S, i, 0});
    }

    for(int i=0; i<K; i++){
        graph.push_back({i, i+1, 1});
        graph.push_back({i+1, i, 0});
    }

    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a-1, b, c});
        graph.push_back({b, a-1, -c});
    }

    vector<int> dis(50, INF);
    dis[S]=0;
    int flag=0;
    for(int i=0; i<=S; i++){
        for(auto j: graph){
            int x=j.x;
            int y=j.y;
            int w=j.w;
            if(dis[x]<INF&&w+dis[x]<dis[y]){
                if(i==S){
                    flag=1;
                    break;
                }
                dis[y]=dis[x]+w;
            }
        }
        if(flag==1) break;
    }

    if(flag==1) cout << "NONE";
    else{
        for(int i=1; i<=K; i++){
            if(dis[i]>dis[i-1]) cout << '#';
            else cout << '-';
        }
    }

    return 0;
}
