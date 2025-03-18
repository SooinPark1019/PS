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
bfs로 각 정점의 거리를 계산
각 간선(A, B)에 대해서 dis[a]+1=dis[b]면 a->b인 간선을 추가
위상 정렬 느낌으로 ㄱㄱ
*/

vector<int> graph[100005];
vector<int> graph2[100005];
int indegree[100005];
int dis[100005];
pii edge[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    memset(dis, -1, sizeof(dis));

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edge[i+1]={a, b};
    }

    dis[1]=0;
    queue<int> Q;
    Q.push(1);

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto i : graph[x]){
            if(dis[i]!=-1) continue;
            dis[i]=dis[x]+1;
            Q.push(i);
        }
    }

    for(int i=1; i<=N; i++){
        for(auto j : graph[i]){
            if(dis[j]==dis[i]+1){
                graph2[i].push_back(j);
                indegree[j]++;
            }
        }
    }
    int ans=0;
    for(int i=0; i<K; i++){
        int a;
        cin >> a;
        int s=edge[a].first, e=edge[a].second;
        if(dis[s]==dis[e]+1) swap(s, e);
        if(dis[s]+1!=dis[e]){
            cout << ans << "\n";
            continue;
        }
        indegree[e]--;
        if(indegree[e]==0){
            Q.push(e);
            while(!Q.empty()){
                int x=Q.front();
                Q.pop();
                ans++;
                for(auto j : graph2[x]){
                    indegree[j]--;
                    if(indegree[j]==0){
                        Q.push(j);
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
