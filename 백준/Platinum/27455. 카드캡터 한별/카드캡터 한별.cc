#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
ll DP[20][20][1005];
ll DP2[(1<<15)][20];
vector<pii> graph[1005];
vector<int> interesting;
int L[1005];
int check[1005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, V, E;
    cin >> N >> V >> E;
    for(int i=1; i<=V; i++){
        cin >> L[i];
    }

    memset(check, -1, sizeof(check));
    interesting.push_back(1);

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        interesting.push_back(a);
    }

    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<=V; k++) DP[i][j][k]=1e18;
        }
    }

    for(int i=0; i<=(1<<N); i++){
        for(int j=0; j<=N; j++){
            DP2[i][j]=1e18;
        }
    }

    for(int i=0; i<=N; i++){
        int start=interesting[i];
        //cout << "i : " << i << " start : " << start << "\n";
        for(int j=0; j<N; j++){
            //cout << "j : " << j << "\n";
            priority_queue<pii, vector<pii>, greater<pii>> PQ;
            PQ.push({0, start});
            DP[i][j][start]=0;
            while(!PQ.empty()){
                ll cur_dis=PQ.top().first;
                int cur_node=PQ.top().second;
                //cout << "cur_node : " << cur_node << " cur_dis : " << cur_dis << " DP : " << DP[i][j][cur_node] << "\n";
                PQ.pop();
                if(DP[i][j][cur_node]!=cur_dis) continue;
                for(auto p : graph[cur_node]){
                    int nxt_node=p.first;
                    int nxt_dis=p.second;
                    if(L[nxt_node]>j) continue;
                    if(DP[i][j][nxt_node]>cur_dis+nxt_dis){
                        DP[i][j][nxt_node]=cur_dis+nxt_dis;
                        PQ.push({cur_dis+nxt_dis, nxt_node});
                    }
                }
            }
        }
    }

    /*for(int i=0; i<=N; i++){
        for(int j=0; j<N; j++){
            for(int k=1; k<=V; k++){
                cout << DP[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }*/

    DP2[0][0]=0;
    for(int i=0; i<(1<<N); i++){//cur_status
        int a=__builtin_popcount(i);
        for(int j=0; j<=N; j++){//cur_node
            if(DP2[i][j]==1e18) continue;
            //cout << "i : " << i << " j : " << j << " DP : " << DP2[i][j] << "\n";
            for(int k=0; k<=N; k++){//nxt_node
                int nxtnode=interesting[k];
                if(DP[j][a][nxtnode]==1e18) continue;
                //cout << "nxtnode : " << nxtnode << " DP : " << DP[j][a][nxtnode] << "\n";
                int nxt_state=i;
                if(k>0) nxt_state=(nxt_state|(1<<(k-1)));
                DP2[nxt_state][k]=min(DP2[nxt_state][k], DP2[i][j]+DP[j][a][nxtnode]);
            }
        }
    }
    int ans=1e18;
    for(int i=0; i<=N; i++){
        ans=min(ans, DP2[(1<<N)-1][i]);
    }
    if(ans==1e18) cout << -1;
    else cout << ans;
    return 0;
}
