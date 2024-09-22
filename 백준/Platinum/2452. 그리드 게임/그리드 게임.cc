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
const int MAXN = 1e5+5;

int N, M;
int arr[105][105];
int vis[105][105];
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
vector<int> graph[10005];

void dfs(int row, int col, vector<vector<int>>& components, int id){
    components[row][col]=id;
    vis[row][col]=1;
    for(int i=0; i<4; i++){
        int nx=row+dx[i];
        int ny=col+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=M||arr[nx][ny]!=arr[row][col]||vis[nx][ny]!=0) continue;
        dfs(nx, ny, components, id); 
    }
}

void connect(int row, int col, vector<vector<int>>& components){
    //cout << "row : " << row << " col : " << col << " components : " << components[row][col] << "\n";
    for(int i=0; i<4; i++){
        int nx=row+dx[i];
        int ny=col+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=M||arr[nx][ny]==arr[row][col]) continue;
        //cout << "nx : " << nx << " ny : " << ny << " components : " << components[nx][ny] << "\n";
        graph[components[row][col]].push_back(components[nx][ny]);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> idnum(N, vector<int>(M));
    int id=1;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(vis[i][j]) continue;
            dfs(i, j, idnum, id);
            id++;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            connect(i, j, idnum);
            sort(all(graph[idnum[i][j]]));
            graph[idnum[i][j]].erase(unique(all(graph[idnum[i][j]])), graph[idnum[i][j]].end());
        }
    }
    int ans=1e18;
    for(int i=1; i<id; i++){
        vector<int> vis(id+1, -1);
        int maxdis=0;
        vis[i]=0;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            for(auto j : graph[x]){
                if(vis[j]!=-1) continue;
                vis[j]=vis[x]+1;
                maxdis=max(maxdis, vis[j]);
                Q.push(j);
            }
        }
        ans=min(ans, maxdis);
    }
    cout << ans;
    
    return 0;
}