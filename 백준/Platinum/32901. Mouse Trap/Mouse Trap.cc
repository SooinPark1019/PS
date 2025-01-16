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
#define i128 __int128

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
    i128 x,y;
};

i128 ccw(point A, point B, point C){
    i128 temp=A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
    return temp;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<point> V;

    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        V.push_back({x, y});
    }
    i128 total=0;

    for(int i=0; i<N; i++){
        total+=V[i].x*V[(i+1)%N].y-V[i].y*V[(i+1)%N].x;
    }

    i128 ans=0;
    point temp={0, 0};
    for(int i=0; i<N; i++){
        ans+=(i128)(temp.x*V[i].y-temp.y*V[i].x)*(N-1-i);
        //cout << ans << "\n";
        temp.x+=V[i].x;
        temp.y+=V[i].y;
    }
    //cout << ans << "\n";
    temp={0, 0};
    reverse(all(V));
    for(int i=0; i<N; i++){
        ans-=(i128)ccw({0, 0}, temp, V[i])*(N-1-i);
        temp.x+=V[i].x;
        temp.y+=V[i].y;
    }

    point A={0, 0};
    point B={0, 0};

    for(int i=0; i<N; i++){
        A.x+=i*V[i].x;
        A.y+=i*V[i].y;
        if(i>0) B.x+=V[i].x;
        if(i>0) B.y+=V[i].y;
    }
    for(int i=0; i<N; i++){
        if(i>0){
            B.x-=V[i].x;
            B.y-=V[i].y;
        }
        A.x-=B.x;
        A.y-=B.y;
        ans-=ccw({0, 0}, A, V[i]);
    }
    cout << fixed;
    cout.precision(12);
    cout << (double)ans/total;

    return 0;
}
