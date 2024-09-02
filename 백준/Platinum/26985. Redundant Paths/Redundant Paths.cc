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
const ll MAX = 5000;
const int D = 18;

vector<int> graph[5005];

int depth[MAX], sp[D][MAX];

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

void lca_dfs(int x) {  // 모든 정점의 깊이와 부모를 전처리, 루트 노드의 부모가 자기 자신이 되도록 구현하면 편리함
    for (auto& nx : graph[x]) {
        if (depth[nx] > -1) continue;
        depth[nx] = depth[x] + 1;
        sp[0][nx] = x;
        lca_dfs(nx);
    }
}
int LCA(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);
    for (int j = D - 1; j >= 0; --j) {  // 두 정점의 깊이를 동일하게 만드는 과정
        if (depth[a] - depth[b] & (1 << j)) a = sp[j][a];
    }
    if (a == b) return a;  // a 또는 b가 LCA인 경우
    for (int j = D - 1; j >= 0; --j) {  // 공통 조상을 찾는 과정
        if (sp[j][a] != sp[j][b]) {
            a = sp[j][a];
            b = sp[j][b];
        }
    }
    return sp[0][a];
}

vector<pll> edge;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    UnionFind UF1(N+1);
    UnionFind UF2(N+1);

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        if(!UF1.isSameSet(a, b)){
            graph[a].push_back(b);
            graph[b].push_back(a);
            UF1.UnionSet(a, b);
        }
        else{
            edge.push_back({a, b});
        }
    }
    memset(depth, -1, sizeof(depth));
    depth[1]=0;
    lca_dfs(1);
    for (int i = 1; i < D; ++i) {  // 희소 배열 구성
        for (int j = 1; j <= N; ++j) {
            sp[i][j] = sp[i - 1][sp[i - 1][j]];
        }
    }

    for(auto p : edge){
        if(UF2.isSameSet(p.first, p.second)) continue;
        int a=UF2.findset(p.first);
        int b=UF2.findset(p.second);
        int c=LCA(a, b);
        //cout << a << " " << b << " " << c << endl;
        c=UF2.findset(c);
        while(a!=c){
            UF2.UnionSet(a, c);
            for(auto i : graph[a]){
                if(i==sp[0][a]||UF2.isSameSet(i, c)||UF2.isSameSet(i, a)) continue;
                graph[c].push_back(i);
            }
            a=sp[0][a];
            a=UF2.findset(a);
        }
        while(b!=c){
            UF2.UnionSet(b, c);
            for(auto i : graph[b]){
                if(i==sp[0][b]||UF2.isSameSet(i, c)||UF2.isSameSet(i, b)) continue;
                graph[c].push_back(i);
            }
            b=sp[0][b];
            b=UF2.findset(b);
        }
    }
    int ans=0;
    vector<int> check(N+1);
    for(int i=1; i<=N; i++){
        int a=UF2.findset(i);
        if(check[a]!=0) continue;
        check[a]=1;
        int temp=0;
        for(auto j : graph[a]){
            if(!UF2.isSameSet(a, j)) temp++;
        }
        if(temp==1) ans++;
    }
    cout << (ans+1)/2;
}
