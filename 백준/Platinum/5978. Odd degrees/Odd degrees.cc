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
const int MAXN = 50005;
const int D = 20;

vector<int> cnt(MAXN, 0);
vector<int> check(MAXN, 0);
vector<int> graph[MAXN];
vector<int> vis(MAXN);
vector<pii> edge;
set<pii> erased;

void sol(int curnode, int par){
    //cout << curnode << endl;
    vis[curnode]=1;
    for(auto i : graph[curnode]){
        if(i==par) continue;
        sol(i, curnode);
    }
    if(cnt[curnode]%2==0){
        cnt[curnode]--;
        cnt[par]--;
        erased.insert({curnode, par});
        erased.insert({par, curnode});
    }
}

class UnionFind{
private:
    vector<int> p, rank, setSize;
public:
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    UnionFind UF(N+1);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        if(UF.isSameSet(a, b)){
            edge.push_back({a, b});
            erased.insert({a, b});
            erased.insert({b, a});
            continue;
        }
        //cout << a << " " << b << "\n";
        UF.UnionSet(a, b);
        cnt[a]++;
        cnt[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edge.push_back({a, b});
    }
    int flag=0;
    for(int i=1; i<=N; i++){
        if(check[UF.findset(i)]!=0) continue;
        check[UF.findset(i)]=1;
        if(UF.SizeOfSet(i)%2!=0){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout << -1;
    }
    else{
        for(int i=1; i<=N; i++){
            if(vis[i]!=0) continue;
            sol(i, -1);
        }
        vector<int> ans;
        for(int i=0; i<edge.size(); i++){
            if(erased.find(edge[i])==erased.end()){
                ans.push_back(i);
            }
        }
        cout << ans.size() << "\n";
        for(auto p : ans) cout << p+1 << "\n";
    }
    return 0;
}