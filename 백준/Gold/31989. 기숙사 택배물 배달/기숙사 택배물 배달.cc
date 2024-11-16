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
const ll mod = 20070713;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> V(2*N+2);
    for(int i=1; i<=2*N+1; i++){
        cin >> V[i];
    }

    vector<pii> T;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        T.push_back({a, b});
    }

    sort(all(T));

    int curpos=V[N+1];
    int ans=0;

    vector<pii> curbur;
    int curtotal=0;
    for(int i=0; i<T.size(); i++){
        if(T[i].first>N+1) break;
        curbur.push_back(T[i]);
        curtotal+=T[i].second;
    }

    reverse(all(curbur));

    for(int i=0; i<curbur.size(); i++){
        ans+=(curtotal+1)*(curpos-V[curbur[i].first]);
        curtotal-=curbur[i].second;
        curpos=V[curbur[i].first];
    }
    ans+=V[N+1]-curpos;

    curbur.clear();
    curtotal=0;
    curpos=V[N+1];

    for(int i=0; i<T.size(); i++){
        if(T[i].first<=N+1) continue;
        curbur.push_back(T[i]);
        curtotal+=T[i].second;
    }

    for(int i=0; i<curbur.size(); i++){
        ans+=(curtotal+1)*(V[curbur[i].first]-curpos);
        curtotal-=curbur[i].second;
        curpos=V[curbur[i].first];
    }

    ans+=curpos-V[N+1];

    cout << ans;
    
    return 0;
}