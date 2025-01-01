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
어떤 집합을 먹기로 결정했다면
순서는 정해진다(카페인이 적은 것부터)

카페인이 큰거부터 해서
DP[인덱스][현재까지 먹은 개수]=최대
*/

bool compare(pii A, pii B){
    return A.second>B.second;
}
int DP[5005][5005];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pii> V;
    vector<int> A;
    vector<int> B;
    
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }

    for(int i=0; i<N; i++){
        V.push_back({A[i], B[i]});
    }

    sort(all(V), compare);

    memset(DP, -1, sizeof(DP));

    DP[0][0]=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(DP[i][j]==-1) continue;
            DP[i+1][j]=max(DP[i+1][j], DP[i][j]);
            DP[i+1][j+1]=max(DP[i+1][j+1], DP[i][j]+V[i].first-V[i].second*j);
        }
    }
    int ans=0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            ans=max(ans, DP[i][j]);
        }
    }
    cout << ans;

    return 0;
}
