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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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

int caldis(int ansx, int ansy, vector<pii>& V){
    vector<int> dist;
    int totaldis=0;
    for(int i=0; i<V.size(); i++){
        dist.push_back(abs(V[i].first-ansx)+abs(V[i].second-ansy));
        totaldis+=2*dist.back();
    }
    sort(all(dist));
    totaldis-=dist.back();
    return totaldis;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<int> X, Y;
    vector<pii> V;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
        V.push_back({x, y});
    }

    sort(all(X));
    sort(all(Y));

    if(N%2){
        int ansx=X[(N-1)/2];
        int ansy=Y[(N-1)/2];
        cout << caldis(ansx, ansy, V) << "\n";
        cout << ansx << " " << ansy;
    }

    if(N%2==0){
        int ax=X[(N-1)/2];
        int bx=X[N/2];
        int ay=Y[(N-1)/2];
        int by=Y[N/2];
        int axay=caldis(ax, ay, V);
        int axby=caldis(ax, by, V);
        int bxay=caldis(bx, ay, V);
        int bxby=caldis(bx, by, V);

        if(min({axay, axby, bxay, bxby})==axay){
            cout << axay << "\n";
            cout << ax << " " << ay;
        }
        else if(min({axay, axby, bxay, bxby})==axby){
            cout << axby << "\n";
            cout << ax << " " << by;
        }
        else if(min({axay, axby, bxay, bxby})==bxay){
            cout << bxay << "\n";
            cout << bx << " " << ay;
        }
        else{
            cout << bxby << "\n";
            cout << bx << " " << by;
        }
    }

    return 0;
}
