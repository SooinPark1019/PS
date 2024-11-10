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
const int MAXN = (1<<18)+5;
const int D = 20;

/*
어떤 관찰을 해야 할까?

최대한 점수가 높은 상황에서 스킵을 하는 게 이득인데

이분탐색을 한다?

어떤 최대 점수에 대해 해당 점수에 도달할 수 있는지를 어떻게 판단할 수 있을지 생각해보자
뒤에서부터 생각해본다?
앞에서부터 각 위치에 대해서 얻을 수 있는 최대 점수를 구하고 가장 많이 먹을 수 있는데까지 자른다?
그러고 뒤에서 다시 살린다고 생각을 해보면
반례가 있을까?
없을듯

앞에서 최댓값까지 먹는다는 가정이 잘못됐나?
그러게 잘못됐을 수 있겠다
그러면 앞에서부터 쭉 가능 점수를 써놓고
mulitset에 넣은 다음에
뒤에서부터 한칸씩 하는 걸로 가자

어떤 점수를 먹는다고 생각을 해보자
maxscore가 먼저 같은지를 확인을 하고 그렇지 않으면 뒤에서부터 먹는다고 생각
뒤에서 maxscore라고 기준을 깔아놓고

뒤에서부터 보면서 기준보다 작은 수가 나온다면 기준을 +1
기준보다 큰 수가 나온다면 기준을 -1
*/

vector<int> graph[100005];
int depth[100005], sparse[18][100005];

void dfs(int x){
    for(auto i : graph[x]){
        if(depth[i]>-1) continue;
        depth[i]=depth[x]+1;
        sparse[0][i]=x;
        dfs(i);
    }
}

int LCA(int a, int b){
    if(depth[a]<depth[b]) swap(a, b);
    for(int j=17; j>=0; j--){
        if(depth[a]-depth[b]&(1<<j)) a=sparse[j][a];
    }
    if(a==b) return a;
    for(int i=17; i>=0; i--){
        if(sparse[i][a]!=sparse[i][b]){
            a=sparse[i][a];
            b=sparse[i][b];
        }
    }
    a=sparse[0][a];
    return a;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(depth, -1, sizeof(depth));
    depth[1]=0;
    dfs(1);
    for(int i=1; i<18; i++){
        for(int j=1; j<=N; j++){
            sparse[i][j]=sparse[i-1][sparse[i-1][j]];
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int r, u, v;
        cin >> r >> u >> v;
        if(depth[u]>depth[v]) swap(u, v);
        int lcauv=LCA(u, v);
        int lcaru=LCA(u, r);
        int lcavr=LCA(v, r);
        int temp=LCA(lcauv, r);
        //cout << lcauv << " " << lcaru << " " << lcavr << " " << temp << "\n";
        if(temp!=lcauv){
            cout << lcauv << "\n";
        }
        else if(lcauv==u){
            cout << lcavr << "\n";
        }
        else if(lcaru==r||lcavr==r){
            cout << r << "\n";
        }
        else if(lcavr==v){
            cout << v << "\n";
        }
        else if(lcaru==u){
            cout << u << "\n";
        }
        else if(lcauv==lcaru&&lcauv ==lcavr){
            cout << lcauv << "\n";
        }
        else if(lcauv==lcaru){
            cout << lcavr << "\n";
        }
        else if(lcauv==lcavr){
            cout << lcaru << "\n";
        }
        else{
            assert(0);
        }
    }
    return 0;
}