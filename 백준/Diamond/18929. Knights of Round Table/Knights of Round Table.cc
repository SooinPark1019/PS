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
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*

*/
vector<int> graph[1000005];
int vis[1000005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        graph[2*i-1].push_back(2*i);
        graph[2*i].push_back(2*i-1);
    }
    int flag=0;
    for(int i=1; i<=2*N; i++){
        if(vis[i]!=0) continue;
        vis[i]=1;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int x=Q.front();
            //cout << x << " " << vis[x] << "\n";
            Q.pop();
            for(auto j : graph[x]){
                if(vis[j]){
                    if(vis[x]==vis[j]){
                        flag=1;
                    }
                    continue;
                }
                vis[j]=3-vis[x];        
                Q.push(j);
            }
        }
    }
    //assert(flag==0);
    for(int i=1; i<=2*N; i++){
        if(vis[i]==1) cout << "X";
        else cout << "Y";
    }
    return 0;
}
