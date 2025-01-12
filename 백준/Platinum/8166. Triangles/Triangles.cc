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

struct point{
    long long x,y;
};
long long ccw(point A, point B, point C){
    long long temp=A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
    return temp;
}

vector<point> V;

bool compare1(point A, point B){
    if(A.y==B.y) return A.x<B.x;
    return A.y<B.y;
}


bool compare2(point A, point B){
    int a=ccw(V[0], A, B);
    /*if(a==0){
        return (A.x-V[0].x)*(A.x-V[0].x)+(A.y-V[0].y)*(A.y-V[0].y)<(B.x-V[0].x)*(B.x-V[0].x)+(B.y-V[0].y)*(B.y-V[0].y);
    }*/
    return a>0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<point> A;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        A.push_back({x, y});
    }
    sort(all(A), compare1);
    int ans=0;
    for(int i=0; i<N; i++){
        V.clear();
        for(int j=i; j<N; j++){
            V.push_back(A[j]);
        }
        sort(V.begin()+1, V.end(), compare2);
        point temp={0, 0};
        for(int j=1; j<V.size(); j++){
            point A={V[j].x-V[0].x, V[j].y-V[0].y};
            ans+=ccw({0, 0}, temp, A);
            temp.x+=A.x;
            temp.y+=A.y;
        }
    }
    /*cout << fixed;
    cout.precision(1);
    cout << (double)ans/2;*/

    cout << ans/2 << ".";
    if(ans%2) cout << 5;
    else cout << 0;
    
    return 0;
}
