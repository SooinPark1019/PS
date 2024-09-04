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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

ll DP[1000005];

vector<pll> V;
ll ans[200005];

struct q{
    ll first, second, index;
};

bool compare(pll A, pll B){
    return A.second<B.second;
};

bool compare2(q A, q B){
    return A.second<B.second;
}

vector<q> query;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for(int i=0; i<N; i++){
        ll a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    for(int i=0; i<Q; i++){
        ll a, b;
        cin >> a >> b;
        query.push_back({a, b, i});
    }

    sort(all(V), compare);
    sort(all(query), compare2);

    //for(auto i : query) cout << i.second << "\n";
    memset(DP, -1, sizeof(DP));

    int curpointer=0;
    DP[0]=0;

    for(int i=0; i<Q; i++){
        while(curpointer<N&&query[i].second>=V[curpointer].second){
            for(int j=1000000-V[curpointer].first; j>=0; j--){
                if(DP[j]==-1) continue;
                DP[j+V[curpointer].first]=max(DP[j+V[curpointer].first], DP[j]+V[curpointer].second);
            }
            curpointer++;
        }
        //cout << curpointer << " " << query[i].first << " " << query[i].second << " " << DP[query[i].first] << "\n";
        if(DP[query[i].first]>=query[i].second) ans[query[i].index]=1;
    }

    for(int i=0; i<Q; i++){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}