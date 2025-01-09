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

int DP[1005][15][5];//노드 번호, 합, 색깔
vector<int> graph[1005];
int cost[1005][3];

void sol(int cur_node, int par, int mod, int K){
    int DP2[2][5][15]={};//제약조건, 합
    DP2[0][0][0]=1;
    DP2[0][1][0]=1;
    DP2[0][2][0]=1;
    for(auto i : graph[cur_node]){
        if(i==par) continue;
        sol(i, cur_node, mod, K);
        for(int j=0; j<K; j++){//자식의 합
            for(int k=0; k<3; k++){//자식의 색깔
                if(DP[i][j][k]==0) continue;
                //cout << "i : " << i << " j : " << j << " k : " << k << " DP :" << DP[i][j][k] << "\n";
                for(int a=0; a<K; a++){//현재합
                    int nxt=(a+j)%K;
                    if(k!=2){
                        DP2[1][0][nxt]+=(DP2[0][0][a]*DP[i][j][k])%mod;//파란거 안쓰는 경우
                        DP2[1][0][nxt]%=mod;
                    }
                    if(k!=1){
                        DP2[1][1][nxt]+=(DP2[0][1][a]*DP[i][j][k])%mod;//초록색 안쓰는 경우
                        DP2[1][1][nxt]%=mod;
                    }
                    else{
                        DP2[1][2][nxt]+=(DP2[0][2][a]*DP[i][j][k])%mod;//초록색만 쓰는 경우
                        DP2[1][2][nxt]%=mod;
                    }
                }
            }
        }
        for(int j=0; j<3; j++){
            for(int k=0; k<K; k++){
                DP2[0][j][k]=DP2[1][j][k];
                DP2[1][j][k]=0;
                //cout << "j : " << j << " k : " << k << " DP : " << DP2[0][j][k] << "\n"; 
            }
            //cout << "\n";
        }
        //cout << "\n";
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<K; j++){
            int nxt=(j+cost[cur_node][i])%K;
            if(i==0){
                DP[cur_node][nxt][i]+=DP2[0][0][j];
                DP[cur_node][nxt][i]%=mod;
            }
            else if(i==1){
                DP[cur_node][nxt][i]+=DP2[0][1][j];
                DP[cur_node][nxt][i]%=mod;
            }
            else{
                DP[cur_node][nxt][i]+=DP2[0][2][j];
                DP[cur_node][nxt][i]%=mod;
            }
        }
    }
    /*cout << "cur_node : " << cur_node << "\n"; 
    for(int i=0; i<K; i++){
        for(int j=0; j<3; j++){
            cout << "i : " << i << " j : " << j << " DP : " << DP[cur_node][i][j] << "\n";
        }
        cout << "\n";
    }
    cout << "\n";*/
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, K;
    cin >> N >> Q >> K;

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++){
            cin >> cost[i][j];
        }
    }

    sol(1, -1, Q, K);

    int ans=0;

    for(int i=0; i<3; i++){
        ans+=DP[1][0][i];
        ans%=Q;
    }

    cout << ans;

    return 0;
}
