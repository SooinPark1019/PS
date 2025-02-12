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

vector<pii> graph[300005];
int Acnt[300005];
int Bcnt[300005];
int vis[300005];
vector<pii> Aans;
vector<pii> Bans;

int dfs(int node, int par){
    //cout << "node : " << node << endl;
    vis[node]=1;
    for(auto i : graph[node]){
        if(i.first==par||vis[i.first]) continue;
        if(dfs(i.first, node)==1){
            if(i.second==0) Aans.push_back({node, i.first});
            else Aans.push_back({i.first, node});
            Acnt[node]^=1;
            Acnt[i.first]^=1;
            Bcnt[node]^=1;
            Bcnt[i.first]^=1;
        }
    }
    return Acnt[node];
}

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
        Acnt[a]^=1;
        Bcnt[b]^=1;
        if(!UF.isSameSet(a, b)){
            graph[a].push_back({b, 0});
            graph[b].push_back({a, 1});
        }
    }

    for(int i=1; i<=N; i++){
        if(vis[i]==1) continue;
        if(dfs(i, -1)==1){
            cout << -1;
            return 0;
        }
    }

    for(int i=1; i<=N; i++){
        Bcnt[i]^=1;
        Bcnt[1]^=1;
        Bans.push_back({1, i});
    }

    vector<int> temp;
    for(int i=1; i<=N; i++){
        if(Bcnt[i]) temp.push_back(i);
    }

    if(temp.size()%2){
        cout << -1;
        return 0;
    }

    for(int i=0; i<temp.size(); i+=2){
        Bans.push_back({temp[i], temp[i+1]});
    }

    cout << Aans.size()+Bans.size() << "\n";

    for(auto i : Aans){
        cout << 1 << " " << i.first << " " << i.second << "\n";
    }

    for(auto i : Bans){
        cout << 2 << " " << i.first << " " << i.second << "\n";
    }

    return 0;
}
