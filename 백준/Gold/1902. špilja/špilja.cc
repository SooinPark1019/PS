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
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

struct line{
    double a, b;
    long double s;
};

long double cross(line A, line B){
    return (B.b-A.b)/(A.a-B.a);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<double, double>> lines;

    int previousx, previousy;
    cin >> previousx >> previousy;

    for(int i=1; i<N; i++){
        int curx, cury;
        cin >> curx >> cury;
        double a=(double)(cury-previousy)/(curx-previousx);
        double b=cury-a*curx;
        lines.push_back({a, b});
        previousx=curx;
        previousy=cury;
    }

    sort(all(lines));

    vector<line> V;

    for(int i=0; i<lines.size(); i++){
        line temp={lines[i].first, lines[i].second, 0};
        //if(V.size()>0) cout <<cross(temp, V.back()) << "\n";
        while(V.size()>0&&V.back().b<=temp.b) V.pop_back();
        while(V.size()>0&&cross(temp, V.back())<=V.back().s){
            V.pop_back();
        }
        if(V.size()!=0) temp.s=cross(temp, V.back());
        V.push_back(temp);
    }
    //for(auto l : V) cout << l.a << " " << l.b << "\n";
    int curpointer=0;
    double curx=0;
    double ans=1e18;
    while(curx<=previousx){
        while(curpointer<V.size()-1&&V[curpointer].a*curx+V[curpointer].b<V[curpointer+1].a*curx+V[curpointer+1].b) curpointer++;
        ans=min(ans, V[curpointer].a*curx+V[curpointer].b);
        curx+=0.01;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}
