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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);
const int FLAG_DEBUG = 0;

/*
*/
class UnionFind{
    public:
        vector<int> p, rank, setSize;
        UnionFind(int N){
            p.resize(N);
            for(int i=0; i<N; i++){
                p[i]=i;
            }
            rank.resize(N, 0);
            setSize.resize(N, 1);
        }
        int findset(int i){
            return (p[i]==i) ? i : (p[i]=findset(p[i]));
        }
        int sz(int i){
            return setSize[findset(i)];
        }
        void unionset(int a, int b){
            if(findset(a)==findset(b)) return;
            int x=findset(a);
            int y=findset(b);
            if(rank[x]>rank[y]) swap(x, y);
            p[x]=y;
            if(rank[x]==rank[y]) rank[y]++;
            setSize[y]+=setSize[x];
        }
};
int dis[100005];
vector<pii> graph[100005];
bool compare(array<int, 3> A, array<int, 3> B){
    return min(dis[A[1]], dis[A[2]])>min(dis[B[1]], dis[B[2]]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    vector<array<int, 3>> edges;

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(int i=1; i<=N; i++){
        dis[i]=1e18;
    }

    priority_queue<pii, vector<pii>, greater<pii>> PQ;

    for(int i=0; i<K; i++){
        int a;
        cin >> a;
        dis[a]=0;
        PQ.push({0, a});
    }

    while(!PQ.empty()){
        int cur_dis=PQ.top().first;
        int cur_node=PQ.top().second;
        //cout << "cur_node : " << cur_node << " cur_dis : " << cur_dis << "\n";
        PQ.pop();
        if(dis[cur_node]!=cur_dis) continue;
        for(auto p : graph[cur_node]){
            int nxt_dis=p.second;
            int nxt_node=p.first;
            //cout << "nxt_node : " << nxt_node << " nxt_dis : " << nxt_dis << "\n";
            if(dis[nxt_node]>cur_dis+nxt_dis){
                dis[nxt_node]=cur_dis+nxt_dis;
                PQ.push({dis[nxt_node], nxt_node});
            }
        }
    }

    //for(int i=1; i<=N; i++) cout << dis[i] << " ";
    //cout << "\n";

    sort(all(edges), compare);

    //for(auto a : edges) cout << a[1] << " " << a[2] << "\n";

    vector<pii> queries;

    for(int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

    vector<int> left(Q, 0);
    vector<int> right(Q, M-1);
    vector<int> ans(Q, 1e18);

    while(1){
        int flag=0;
        UnionFind UF(N+1);
        vector<vector<int>> G(M);
        for(int i=0; i<Q; i++){
            if(left[i]<=right[i]){
                flag=1;
                int mid=(left[i]+right[i])>>1;
                G[mid].push_back(i);
            }
        }
        if(!flag) break;

        for(int i=0; i<M; i++){
            //cout << "i : " << i << "\n";
            int u=edges[i][1];
            int v=edges[i][2];
            UF.unionset(u, v);
            for(auto j : G[i]){
                if(UF.findset(queries[j].first)==UF.findset(queries[j].second)){
                    //cout << "j : " << j << "\n";
                    ans[j]=min(ans[j], i);
                    right[j]=i-1;
                }
                else{
                    left[j]=i+1;
                }
            }
        }
    }

    for(int i=0; i<Q; i++){
        //cout << edges[ans[i]][1] << " " << edges[ans[i]][2] << "\n";
        cout << min(dis[edges[ans[i]][1]], dis[edges[ans[i]][2]]) << "\n";
    }

    return 0;
}