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
//#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

int DP[500005];
multiset<int> MS[500005];
int par[500005];
int ans[500005];
int sn;

void init(){
    memset(DP, 0, sizeof(DP));
    DP[1]=0;
    sn=1;
}

void up(int a, int b){
    if(a==1) return;
    int p=par[a];
    int prevdp=DP[p];
    int prevans=ans[p];
    if(MS[p].find(DP[a]-b)!=MS[p].end())MS[p].erase(MS[p].find(DP[a]-b));
    MS[p].insert(DP[a]);
    if(MS[p].size()==1) DP[p]=*prev(MS[p].end());
    else{
        //cout << *prev(MS[p].end()) << " " << *prev(prev(MS[p].end()))+1 << "\n";
        DP[p]=max(*prev(MS[p].end()), *prev(prev(MS[p].end()))+1);
    }
    ans[p]=max(ans[p], ans[a]);
    if(MS[p].size()==1) ans[p]=max(ans[p], *prev(MS[p].end()));
    else if(MS[p].size()==2) ans[p]=max(ans[p], *prev(MS[p].end())+*prev(prev(MS[p].end()))+1);
    else{
        ans[p]=max({ans[p], *prev(MS[p].end())+*prev(prev(MS[p].end()))+1, *prev(prev(MS[p].end()))+1+*prev(prev(prev(MS[p].end())))+1});
    }
    //cout << p << " " << prevdp << " " << DP[p] << " " << prevans << " " << ans[p] << "\n";
    if(prevdp!=DP[p]||prevans!=ans[p]){
        up(p, DP[p]-prevdp);
    }
}

void observation(int P){
    sn++;
    par[sn]=P;
    MS[P].insert(0);
    int prevdp=DP[P];
    int prevans=ans[P];
    if(MS[P].size()==1) DP[P]=*prev(MS[P].end());
    else{
        DP[P]=max(*prev(MS[P].end()), *prev(prev(MS[P].end()))+1);
    }
    ans[P]=max(ans[P], ans[sn]);
    if(MS[P].size()==1) ans[P]=max(ans[P], *prev(MS[P].end()));
    else if(MS[P].size()==2) ans[P]=max(ans[P], *prev(MS[P].end())+*prev(prev(MS[P].end()))+1);
    else{
        ans[P]=max({ans[P], *prev(MS[P].end())+*prev(prev(MS[P].end()))+1, *prev(prev(MS[P].end()))+1+*prev(prev(prev(MS[P].end())))+1});
    }
    //cout << P << " " << prevdp << " " << DP[P] << " " << prevans << " " << ans[P] << "\n";
    if(prevdp!=DP[P]||prevans!=ans[P]){
        up(P, DP[P]-prevdp);
    }
    return;
}

int analyze(int R){
    return ans[R];
}