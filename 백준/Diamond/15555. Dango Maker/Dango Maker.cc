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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);
const int FLAG_DEBUG = 0;

/*
먼저 해당 위치에서 가로 또는 세로가 시작하는지를 나타내는 배열을 하나 만든다
가로가 시작되면 1, 세로가 시작되면 2, 아무것도 아니면 0

각 묶음에 대해서 번호를 1씩 증가시키면서 정점에 할당
*/

int arr[3005][3005];
int rowdir[3005][3005];
int coldir[3005][3005];
int curnode=0;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin >> c;
            if(c=='R') arr[i][j]=0;
            else if(c=='G') arr[i][j]=1;
            else arr[i][j]=2;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M-2; j++){
            if(arr[i][j]==0&&arr[i][j+1]==1&&arr[i][j+2]==2){
                curnode++;
                rowdir[i][j]=curnode;
            }
        }
    }

    for(int i=0; i<N-2; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==0&&arr[i+1][j]==1&&arr[i+2][j]==2){
                curnode++;
                coldir[i][j]=curnode;
            }
        }
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << rowdir[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << coldir[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    vector<vector<int>> graph(curnode+1, vector<int>());

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(rowdir[i][j]){
                if(coldir[i][j]){
                    graph[rowdir[i][j]].push_back(coldir[i][j]);
                    graph[coldir[i][j]].push_back(rowdir[i][j]);
                }
                if(i>0&&coldir[i-1][j+1]){
                    graph[rowdir[i][j]].push_back(coldir[i-1][j+1]);
                    graph[coldir[i-1][j+1]].push_back(rowdir[i][j]);
                }
                if(i>1&&coldir[i-2][j+2]){
                    graph[rowdir[i][j]].push_back(coldir[i-2][j+2]);
                    graph[coldir[i-2][j+2]].push_back(rowdir[i][j]);
                }
            }
        }
    }

    vector<int> vis(curnode+1);
    int ans=0;
    for(int i=1; i<=curnode; i++){
        if(vis[i]) continue;
        int temp=0;
        queue<int> Q;
        Q.push(i);
        vis[i]=1;
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            temp++;
            for(auto j : graph[x]){
                if(vis[j]) continue;
                vis[j]=1;
                Q.push(j);
            }
        }
        ans+=(temp+1)/2;
    }

    cout << ans;

    return 0;
}