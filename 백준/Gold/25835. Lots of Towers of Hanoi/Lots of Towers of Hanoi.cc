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
const ll mod = 1e9+123;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
각 단어마다 짝을 지어준 다음에
DP[i][j]=인덱스 i, 인덱스 j인 경우의 최소 비용
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, s, e;
    cin >> N >> s >> e;
    cout << 2*(N-1)*(N-1)-1 << "\n";
    vector<int> vis(N+1);
    stack<int> T;
    vis[s]=1;
    for(int i=N-1; i>=1; i--){
        stack<int> S;
        cout << s << " " << e << "\n";
        S.push(e);
        vis[e]=1;
        for(int j=1; j<=N; j++){
            if(vis[j]==1) continue;
            S.push(j);
            vis[j]=1;
            cout << s << " " << j << "\n";
        }
        int temp=S.top();
        S.pop();
        while(!S.empty()){
            int a=S.top();
            S.pop();
            vis[a]=0;
            cout << a << " " << temp << "\n";
        }
        T.push(temp);
    }
    //cout << "!" << endl;
    vis[s]=0;
    assert(T.top()==e);
    T.pop();
    while(!T.empty()){
        int a=T.top();
        T.pop();
        stack<int> S;
        for(int j=1; j<=N; j++){
            if(vis[j]==1) continue;
            S.push(j);
            cout << a << " " << j << "\n";
        }
        cout << a << " " << e << "\n";
        vis[a]=0;
        while(!S.empty()){
            int a=S.top();
            S.pop();
            vis[a]=0;
            cout << a << " " << e << "\n";
        }
    }
    return 0;
}
