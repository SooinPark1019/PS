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
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
스택으로 뭉치기 하고 DP?
DP[i][j]=i까지 먹었을 때 
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

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
        int N, M;
        cin >> N >> M;
        if(N==0&&M==0) break;
        UnionFind UF(N+1);
        for(int i=0; i<M; i++){
            int a, b;
            cin >> a >> b;
            UF.UnionSet(a, b);
        }
        int cnt=0;
        int cnt2=0;
        vector<int> vis(N+1);
        for(int i=1; i<=N; i++){
            if(vis[UF.findset(i)]!=0) continue;
            vis[UF.findset(i)]=1;
            cnt++;
            if(UF.SizeOfSet(i)>1) cnt2++;
        }
        cout << (fastmul(2, cnt)+(cnt2>0))%mod << "\n";
    }
    return 0;
}