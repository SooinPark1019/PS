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
int N, M, DP[105][105], A[105], B[105];
bool visited[105];
vector<int> graph[105], T1[105], T2[105];
int T2_par[105];
void find_T2_par(int node, int par){
    for(auto i : T2[node]){
        if(i==par) continue;
        find_T2_par(i, node);
        T2_par[i]=node;
    }
}
bool bp_dfs(int x){
    visited[x]=1;
    for(auto nx : graph[x]){
        if(B[nx]==-1||!visited[B[nx]]&&bp_dfs(B[nx])){
            A[x]=nx;
            B[nx]=x;
            return 1;
        }
    }
    return 0;
}
void dfs(int node, int par){
    vector<int> temp;
    for(auto i : T1[node]){
        if(i==par) continue;
        dfs(i, node);
        temp.push_back(i);
    }
    for(int i=1; i<=M; i++){
        vector<int> temp2;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        for(auto j : T2[i]){
            if(T2_par[i]==j) continue;
            temp2.push_back(j);
        }
        for(auto j : temp){
            for(auto k : temp2){
                if(DP[j][k]){
                    graph[j].push_back(k);
                }
            }
        }
        int matches=0;
        for(auto j : temp){
            memset(visited, 0, sizeof(visited));
            if(bp_dfs(j)) matches++;
        }
        if(matches==temp2.size()){
            DP[node][i]=1;
        }
        for(auto j : temp){
            graph[j].clear();
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        T1[a].push_back(b);
        T1[b].push_back(a);
    }

    cin >> M;
    
    for(int i=0; i<M-1; i++){
        int a, b;
        cin >> a >> b;
        T2[a].push_back(b);
        T2[b].push_back(a);
    }
    find_T2_par(1, -1);
    int flag=0;
    for(int i=1; i<=N; i++){
        memset(DP, 0, sizeof(DP));
        dfs(i, -1);
        for(int j=1; j<=N; j++){
            if(DP[j][1]){
                flag=1;
                break;
            }
        }
        if(flag) break;
    }

    if(flag) cout << "Y";
    else cout << "N";

    return 0;
}
