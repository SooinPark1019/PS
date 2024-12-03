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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
간선 거꾸로 놓는 거까지는 맞을 거 같다
*/
vector<int> graph[100005];
int DP[100005][2];
map<int, int> V[100005][2];
int indegree[100005];
int indegree2[100005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        indegree[a]++;
        indegree2[a]++;
    }

    queue<int> Q;
    Q.push(N);
    DP[N][0]=0;
    DP[N][1]=LNF;

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto i : graph[x]){
            indegree[i]--;
            V[i][0][DP[x][1]]++;
            V[i][1][DP[x][0]]++;
            if(indegree[i]==0){
                int a=indegree2[i];
                int temp=LNF;
                for(auto p : V[i][0]){
                    a-=p.second;
                    temp=min(temp, p.first+a);
                }
                DP[i][0]=temp;
                a=indegree2[i];
                temp=LNF;
                for(auto p : V[i][1]){
                    a-=p.second;
                    temp=min(temp, p.first+a);
                }
                DP[i][1]=temp;
                Q.push(i);
            }
        }
    }

    int ans=LNF;
    for(int i=1; i<=N; i++){
        if(graph[i].size()==0){
            ans=min(ans, DP[i][0]);
        }
    }
    if(ans==LNF) cout << -1;
    else cout << ans;

    return 0;
}
