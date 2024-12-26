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
    
    int t=0;
    while(1){
        t++;
        int N;
        cin >> N;
        if(N==0) break;
        cout << "Case " << t << ":\n";
        vector<pii> V;
        for(int i=0; i<N; i++){
            int a, b;
            cin >> a >> b;
            V.push_back({a, b});
        }
        int x1, y1, x2, y2, q;
        cin >> x1 >> y1 >> x2 >> y2 >> q;
        vector<int> dist1;
        vector<int> dist2;
        for(auto p : V){
            dist1.push_back((x1-p.first)*(x1-p.first)+(y1-p.second)*(y1-p.second));
            dist2.push_back((x2-p.first)*(x2-p.first)+(y2-p.second)*(y2-p.second));
        }
        sort(all(dist1));
        sort(all(dist2));
        //for(auto i : dist1) cout << i << " ";
        //cout << "\n";
        while(q--){
            int r1, r2;
            cin >> r1 >> r2;
            r1*=r1;
            r2*=r2;
            int a=upper_bound(all(dist1), r1)-dist1.begin();
            int b=upper_bound(all(dist2), r2)-dist2.begin();
            cout << max(0ll, N-(a+b)) << "\n";
        }
    }
    return 0;
}
