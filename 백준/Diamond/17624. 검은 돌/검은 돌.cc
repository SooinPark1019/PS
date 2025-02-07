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
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/

int N, B;
int color[5005];
vector<int> graph[5005];
pii DP[5005];

vector<pii> sol(int node, int par){
    vector<pii> ret;
    if(color[node]){
        ret.push_back({1e18, -1e18});
        ret.push_back({1, 1});
    }
    else ret.push_back({1, 1});
    for(auto i : graph[node]){
        if(i==par) continue;
        vector<pii> temp=sol(i, node);
        vector<pii> ret2(ret.size()+temp.size()-1, {1e18, -1e18});
        for(int j=0; j<ret.size(); j++){
            if(ret[j].first>ret[j].second) continue;
            //cout << "j : " << j << " ret : " << ret[j].first << " " << ret[j].second << "\n";
            for(int k=0; k<temp.size(); k++){
                if(temp[k].first>temp[k].second) continue;
                //cout << "k : " << k << " temp : " << temp[k].first << " " << temp[k].second << "\n";
                ret2[j+k].first=min(ret2[j+k].first, ret[j].first+temp[k].first);
                ret2[j+k].second=max(ret2[j+k].second, ret[j].second+temp[k].second);
            }
        }
        swap(ret, ret2);
    }
    ret[0].first=min(ret[0].first, 0ll);
    ret[0].second=max(ret[0].second, 0ll);
    //cout << "node : " << node << " ret : " << "\n";
    //for(auto p : ret) cout << p.first << " " << p.second << "\n";
    //cout << "\n";
    for(int i=0; i<ret.size(); i++){
        if(ret[i].first>ret[i].second) continue;
        DP[i].first=min(DP[i].first, ret[i].first);
        DP[i].second=max(DP[i].second, ret[i].second);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;
    for(int i=0; i<B; i++){
        int a;
        cin >> a;
        color[a]=1;
    }
    for(int i=0; i<=B; i++){
        DP[i]={1e18, -1e18};
    }
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    sol(1, -1);
    int Q;
    cin >> Q;
    int ans=0;
    while(Q--){
        int a, b;
        cin >> a >> b;
        if(DP[b].first>DP[b].second) continue;
        if(DP[b].first<=a&&DP[b].second>=a) ans++;
    }
    cout << ans;
}
