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
typedef pair<double, int> pdl;
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

int DP[505][505];
vector<int> V[505];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        int flag=0;
        for(int j=1; j<=N; j++){
            int a;
            cin >> a;
            if(flag==0){
                V[i].push_back(a);
            }
            if(a==i) flag=1;
        }
    }

    for(int i=1; i<=N; i++){
        vector<int> vis(N+1);
        vis[i]=1;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            DP[i][x]=1;
            for(auto j : V[x]){
                if(vis[j]!=0) continue;
                vis[j]=1;
                Q.push(j);
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(auto j : V[i]){
            if(DP[j][i]){
                cout << j << "\n";
                break;
            }
        }
    }

    return 0;
}
