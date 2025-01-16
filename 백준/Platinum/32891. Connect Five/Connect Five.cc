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
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

bool compare(pii A, pii B){
    return A.second<B.second;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pii> V;

    for(int i=0; i<5; i++){
        int x, y;
        cin >> x >> y;
        V.push_back({x, y});
    }

    int ans=0;

    for(int i=0; i<10; i++){
        sort(all(V));

        while(V.size()>1&&V[0]==V[1]) V.erase(V.begin());
        while(V.size()>1&&V.back()==V[V.size()-2]) V.pop_back();

        while(V.size()>1&&V[0].first!=V[1].first){
            ans+=abs(V[0].first-V[1].first);
            if(V[0].second==V[1].second) V.erase(V.begin());
            else{
                V[0].first=V[1].first;
            }
        }

        while(V.size()>1&&V.back().first!=V[V.size()-2].first){
            ans+=abs(V.back().first-V[V.size()-2].first);
            if(V.back().second==V[V.size()-2].second) V.pop_back();
            else{
                V.back().first=V[V.size()-2].first;
            }
        }

        sort(all(V), compare);

        while(V.size()>1&&V[0]==V[1]) V.erase(V.begin());
        while(V.size()>1&&V.back()==V[V.size()-2]) V.pop_back();

        while(V.size()>1&&V[0].second!=V[1].second){
            ans+=abs(V[0].second-V[1].second);
            if(V[0].first==V[1].first) V.erase(V.begin());
            else{
                V[0].second=V[1].second;
            }
        }

        while(V.size()>1&&V.back().second!=V[V.size()-2].second){
            ans+=abs(V.back().second-V[V.size()-2].second);
            if(V.back().first==V[V.size()-2].first) V.pop_back();
            else{
                V.back().second=V[V.size()-2].second;
            }
        }
    }

    //for(auto p : V) cout << p.first << " " << p.second << "\n";

    sort(all(V));

    if(V.size()<4) ans+=abs(V[0].first-V.back().first);
    else ans+=abs(V[0].first-V.back().first)*2;

    sort(all(V), compare);

    if(V.size()<4) ans+=abs(V[0].second-V.back().second)*2;
    else ans+=abs(V[0].second-V.back().second)*2;

    //cout << ans << "\n";

    if(V.size()==5){
        int maxx=0, minx=1e18, maxy=0, miny=1e18;
        for(auto p : V){
            maxx=max(maxx, p.first);
            minx=min(minx, p.first);
            maxy=max(maxy, p.second);
            miny=min(miny, p.second);
        }
        //cout << maxx << " " << minx << " " << maxy << " " << miny << "\n";
        if(V[2].first!=maxx&&V[2].first!=minx&&V[2].second!=maxy&&V[2].second!=miny){
            ans+=min(abs(maxx-minx), abs(miny-maxy));
        }
    }

    cout << ans;
    
    return 0;
}
