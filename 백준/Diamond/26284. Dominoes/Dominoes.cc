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
*/
char arr[1005][1005];
int A[2005], B[2005];
int evennum=0, oddnum=1000;
int num[1005][1005];
vector<int> graph[2005];
bool visited[2005];
bool bp_dfs(int x){
    visited[x]=1;
    for(auto& nx : graph[x]){
        if(B[nx]==-1||!visited[B[nx]]&&bp_dfs(B[nx])){
            A[x]=nx;
            B[nx]=x;
            return 1;
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int cnt=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j]=='.') cnt++;
        }
    }

    if(cnt>2000){
        cout << 1000000;
    }
    else{
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]=='#') continue;
                if((i+j)%2==0){
                    evennum++;
                    num[i][j]=evennum;
                }
                else{
                    oddnum++;
                    num[i][j]=oddnum;
                }
            }
        }
        int dx[4]={0, 0, -1, 1};
        int dy[4]={-1, 1, 0, 0};
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]=='#'||(i+j)%2) continue;
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0||nx>=N||ny<0||ny>=M||arr[nx][ny]=='#') continue;
                    graph[num[i][j]].push_back(num[nx][ny]);
                    graph[num[nx][ny]].push_back(num[i][j]);
                }
            }
        }
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        for(int i=1; i<=evennum; i++){
            memset(visited, 0, sizeof(visited));
            bp_dfs(i);
        }
        int ans=evennum*(evennum-1);
        for(int i=1001; i<=oddnum; i++){
            vector<int> vis(2005, 0);
            vis[i]=1;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int x=Q.front();
                Q.pop();
                if(x<=1000){
                    for(auto nx : graph[x]){
                        if(vis[nx]) continue;
                        vis[nx]=1;
                        Q.push(nx);
                    }
                }
                else{
                    if(vis[B[x]]) continue;;
                    vis[B[x]]=1;
                    Q.push(B[x]);
                }
            }
            for(int i=1; i<=evennum; i++){
                if(vis[i]==0) ans++;
            }
        }
        cout << min(1000000ll, ans);
    }

    return 0;
}
