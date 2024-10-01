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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = 5e5+5;
const int D = 20;

/*

*/
int p[200005], hand[200005][2], check[200005][2], ans[200005];
vector<int> monkey[200005];

int get(int a){
    return (p[a]==a) ? a : (p[a]=get(p[a]));
}

void unionset(int a, int b, int c){
    a=get(a);
    b=get(b);
    if(a==b) return;
    //cout << a << " " << b << "\n";
    if(b==1) swap(a, b);
    else if(a!=1&&monkey[a].size()<monkey[b].size()) swap(a, b);
    //cout << a << " " << b << "\n";
    p[b]=a;
    for(auto j : monkey[b]){
        monkey[a].push_back(j);
        if(p[b]==1) ans[j]=c;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    memset(ans, -1, sizeof(ans));
    for(int i=1; i<=N; i++){
        cin >> hand[i][0] >> hand[i][1];
    }
    for(int i=1; i<=N; i++){
        p[i]=i;
        monkey[i].push_back(i);
    }

    vector<pii> Q;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        Q.push_back({a, b});
        check[a][b-1]=1;
    }

    reverse(all(Q));

    for(int i=1; i<=N; i++){
        for(int j=0; j<2; j++){
            if(check[i][j]!=0||hand[i][j]==-1) continue;
            //cout << "i : " << i << " " << hand[i][j] << "\n";
            unionset(i, hand[i][j], -1);
        }
    }

    for(int i=0; i<Q.size(); i++){
        if(hand[Q[i].first][Q[i].second-1]==-1) continue;
        unionset(Q[i].first, hand[Q[i].first][Q[i].second-1], Q.size()-i-1);
    }

    for(int i=1; i<=N; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}