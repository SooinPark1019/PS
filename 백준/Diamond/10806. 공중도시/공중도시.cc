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
const ll MAX = 100000;

vector<int> graph[MAX+5];
int lvl[MAX+5];
vector<pii> bridge;
vector<int> artpoint;
int DP[MAX+5];
int down[MAX+5];
int cycle[MAX+5];
int up[MAX+5];
int cidx;

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
    p[x] = y;
    }
};

UnionFind UF(MAX+5);
vector<int> tree[MAX+5];

void dfs(int cur_node, int p){
    DP[cur_node]=0;
    cycle[cur_node]=cur_node;
    int f=0;
    int cnt=0, pre=0;
    int temp=0;
    for(int nxt : graph[cur_node]){
        if(nxt==p&&temp==0){
            temp++;
            continue;
        }
        if(lvl[nxt]==0){//spanning edge
            lvl[nxt]=lvl[cur_node]+1;
            dfs(nxt, cur_node);
            DP[cur_node]+=DP[nxt];
            cnt+=DP[cur_node]==pre;
        }
        else if(lvl[nxt]<lvl[cur_node]){
            //cout << nxt << " " << cur_node << "\n";
            DP[cur_node]++;
            DP[nxt]--;
            down[nxt]++;
            up[cur_node]++;
        }
        pre=DP[cur_node];
    }
    if(lvl[cur_node]!=1&&DP[cur_node]==0){//bridge
        //cout << p << " " << cur_node << "\n";
        bridge.push_back({p, cur_node});
    }
    else if(lvl[cur_node]!=1){
        UF.UnionSet(p, cur_node);
    }
    if((!p&&cnt>1)||(p&&cnt)){
        artpoint.push_back(cur_node);
    }
}

vector<int> ans;

void dfs2(int cur_node, int p){
    if(tree[cur_node].size()==1){
        //cout << 
        ans.push_back(cur_node);
        return;
    }
    for(auto i : tree[cur_node]){
        //cout << "cur node : " << cur_node << " i : " << i << "\n";
        if(i==p) continue;
        dfs2(i, cur_node);
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    lvl[1]=1;
    cidx=N+1;
    dfs(1, 0);
    for(int i=1; i<=N; i++){
        for(auto j : graph[i]){
            if(UF.isSameSet(i, j)) continue;
            //cout << UF.findset(i) << " " << UF.findset(j) << "\n";
            tree[UF.findset(i)].push_back(UF.findset(j));
        }
    }
    vector<int> check(N+1);
    int flag=0;
    for(int i=1; i<=N; i++){
        if(tree[UF.findset(i)].size()!=1){
            dfs2(UF.findset(i), 0);
            flag=1;
            break;
        }
    }
    if(flag==0) dfs2(UF.findset(1), 0);
    cout << (ans.size()+1)/2 << "\n";
    if(ans.size()==1){
        cout << ans[0] << " ";
        for(int i=1; i<=N; i++){
            if(!UF.isSameSet(i, ans[0])){
                cout << i << "\n";
                break;
            }
        }
    }
    else{
        for(int i=0; i<ans.size()/2; i++){
            //cout << i << " " << ans.size()/2+i << "\n";
            cout << ans[i] << " " << ans[ans.size()/2+i] << "\n";
        }
        if(ans.size()%2!=0)cout << ans[0] << " " << ans.back();
    }
}
