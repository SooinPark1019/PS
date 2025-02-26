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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> edges;

    for(int i=0; i<M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(all(edges));

    int Q;
    cin >> Q;

    vector<pii> queries;

    for(int i=0; i<Q; i++){
        int x, y;
        cin >> x >> y;
        queries.push_back({x, y});
    }

    vector<int> left(Q, 0);
    vector<int> right(Q, M-1);
    vector<pii> ans(Q, {1e18, 1e18});

    while(1){
        int flag=0;
        vector<vector<int>> G(M);
        UnionFind UF(N+1);
        for(int i=0; i<Q; i++){
            if(left[i]<=right[i]){
                flag=1;
                int mid=(left[i]+right[i])>>1;
                G[mid].push_back(i);
            }
        }
        if(flag==0) break;

        for(int i=0; i<M; i++){
            int w=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            UF.unionset(u, v);
            for(auto j : G[i]){
                int a=queries[j].first;
                int b=queries[j].second;
                if(UF.findset(a)==UF.findset(b)){
                    right[j]=i-1;
                    if(ans[j].first>i){
                        ans[j].first=w;
                        ans[j].second=UF.sz(a);
                    }
                }
                else{
                    left[j]=i+1;
                }
            }
        }
    }

    for(int i=0; i<Q; i++){
        if(ans[i].first==1e18) cout << -1 << "\n";
        else cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
