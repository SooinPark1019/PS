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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

ll arr[1005][1005];
ll ans=0;

struct st{
    int i, j;
    ll value;
};

struct cmp{
    bool operator()(st A, st B){
        return B.value>A.value;
    }
};
int N, M, K;

vector<st> V;
vector<st> cur;

void sol(int i){
    if(i==V.size()||cur.size()==K){
        ll temp=0;
        for(auto s : cur){
            temp+=s.value;
        }
        ans=max(ans, temp);
        return;
    }
    int flag=0;
    for(auto s : cur){
        if(s.i==V[i].i&&abs(s.j-V[i].j)==1){
            flag=1;
            break;
        }
        if(s.j==V[i].j&&abs(s.i-V[i].i)==1){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cur.push_back(V[i]);
        sol(i+1);
        cur.pop_back();
    }
    sol(i+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    priority_queue<st, vector<st>, cmp> PQ;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            PQ.push({i, j, arr[i][j]});
        }
    }

    int cnt=50;

    while(!PQ.empty()&&cnt--){
        V.push_back(PQ.top());
        PQ.pop();
    }

    sol(0);

    cout << ans;

    return 0;
}