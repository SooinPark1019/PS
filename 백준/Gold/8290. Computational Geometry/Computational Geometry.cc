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
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
각 서브그리드마다 최대 하나의 constraint만 포함 가능

왼쪽위의 서브그리드부터 생각한다고 하자
*/
int Xcnt[100005];
int Ycnt[100005];
struct query{
    int r1, r2, i;
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    if(N<=3||N%2) cout << "NIE";
    else{
        vector<pii> V;
        cout << 0 << " " << 0 << "\n";
        cout << 0 << " " << 1 << "\n";
        V.push_back({4, 1});
        V.push_back({4, 0});
        N-=4;
        N/=2;
        for(int i=0; i<N; i++){
            if(i%2){
                cout << V[0].first << " " << V[0].second << "\n";
                cout << V[0].first << " " << V[0].second-1 << "\n"; 
                V[0].first+=2;
                V[0].second--;
                V[1].first+=2;
            }
            else{
                cout << V[0].first << " " << V[0].second << "\n";
                cout << V[0].first << " " << V[0].second+1 << "\n";
                V[0].first++;
                V[0].second++;
                V[1].first++;
            }
        }
        for(auto i : V) cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
