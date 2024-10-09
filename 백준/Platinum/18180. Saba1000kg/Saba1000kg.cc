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
const ll mod = 998244353;
const int MAXN = 2e5+5;
const int D = 20;

class UnionFind{
public:
    vector<int> p, rank, setSize;
    UnionFind(int N){
        p.assign(N, 0);
        for(int i=0; i<N; i++) p[i]=i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
    };
    int findset(int i){
        return(p[i]==i) ? i : (p[i]=findset(p[i]));
    }
    bool isSameSet(int i, int j){
    return findset(i) == findset(j);
    }
    int SizeOfSet(int i){
        return setSize[findset(i)];
    }
    void UnionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x=findset(i);
    int y=findset(j);
    if(rank[x]>rank[y]) swap(y,x);
    p[x] = y;
    if(rank[x]==rank[y]) rank[y]++;
    setSize[y]+=setSize[x];
    }
};

vector<int> graph[100005];
set<int> connected[100005];
int check[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E, P;
    cin >> N >> E >> P;

    for(int i=0; i<E; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=N; i++){
        if(graph[i].size()>sqrt(N)){
            for(auto j : graph[i]){
                connected[i].insert(j);
            }
        }
    }
    UnionFind UF(N+1);
    for(int i=0; i<P; i++){
        int M;
        cin >> M;
        int ans=M;
        vector<int> big;
        vector<int> V;
        for(int i=0; i<M; i++){
            int a;
            cin >> a;
            V.push_back(a);
            check[a]=1;
        }
        for(auto i : V){
            if(graph[i].size()>sqrt(N)){
                big.push_back(i);
                continue;
            }
            for(auto j : graph[i]){
                if(check[j]==1){
                    if(!UF.isSameSet(i, j)){
                        UF.UnionSet(i, j);
                        ans--;
                    }
                }
            }
        }
        for(auto i : big){
            for(auto j : big){
                if(connected[i].find(j)!=connected[i].end()&&!UF.isSameSet(i, j)){
                    ans--;
                    UF.UnionSet(i, j);
                }
            }
        }
        cout << ans << "\n";
        for(auto i : V){
            UF.p[i]=i;
            check[i]=0;
        }
    }

    return 0;
}