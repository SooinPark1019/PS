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
*/

const int MAX = 5000;
int N, M, A[MAX], B[MAX], matches;
bool visited[MAX];
vector<int> graph[MAX];

bool bp_dfs(int x){
    visited[x]=1;
    for(auto i : graph[x]){
        if(B[i]==-1||!visited[B[i]]&&bp_dfs(B[i])){
            A[x]=i;
            B[i]=x;
            return 1;
        }
    }
    return 0;
}

char arr[55][55];
pii num[55][55];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> arr[i][j];
    }

    int row_num=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]=='*'&&(j==0||arr[i][j-1]=='.')) row_num++;
            if(arr[i][j]=='*') num[i][j].first=row_num;
        }
    }

    int col_num=1;

    for(int j=0; j<M; j++){
        for(int i=0; i<N; i++){
            if(arr[i][j]=='*'&&(i==0||arr[i-1][j]=='.')) col_num++;
            if(arr[i][j]=='*') num[i][j].second=col_num;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]=='*'){
                graph[num[i][j].first].push_back(num[i][j].second+2500);
                //graph[num[i][j].second+2500].push_back(num[i][j].first);
                //cout << num[i][j].first << " " << num[i][j].second+2500 << "\n";
            }
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    for(int i=0; i<=row_num; i++){
        memset(visited, 0, sizeof(visited));
        if(bp_dfs(i)) matches++;
    }

    cout << matches;

    return 0;
}
