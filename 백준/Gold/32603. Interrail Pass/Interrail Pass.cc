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
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/
struct pass{
    int period, days, cost;
};
int DP[10005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    vector<pii> V;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    sort(all(V));
    for(int i=0; i<=N; i++){
        DP[i]=1e18;
    }
    vector<pass> P;
    for(int i=0; i<K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        P.push_back({a, b, c});
    }
    DP[0]=0;
    for(int i=0; i<N; i++){
        DP[i+1]=min(DP[i+1], DP[i]+V[i].second);
        for(int j=0; j<K; j++){
            int nxt=i+P[j].days;
            int left=i+1;
            int right=N-1;
            int ans=N;
            while(left<=right){
                int mid=(left+right)/2;
                if(V[mid].first>=V[i].first+P[j].period){
                    ans=min(ans, mid);
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            nxt=min(nxt, ans);
            DP[nxt]=min(DP[nxt], DP[i]+P[j].cost);
        }
    }
    cout << DP[N];
    return 0;
}