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

/*
*/

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
char arr[105][105];

int H, W;

void fill_vis(int vis[105][105], queue<pii>& Q){
    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;
        //cout << "x : " << x << " y : " << y << "\n";
        Q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            //cout << "nx : " << nx << " ny : " << ny << " " << "\n";
            if(nx<0||nx>=H||ny<0||ny>=W||arr[nx][ny]=='*'){
                continue;
            }
            if(vis[nx][ny]>vis[x][y]+(arr[x][y]=='#')||vis[nx][ny]==-1){
                vis[nx][ny]=vis[x][y]+(arr[x][y]=='#');
                Q.push({nx, ny});
            }
        }
    }
}

void sol(int sx, int sy, int vis[105][105]){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            vis[i][j]=-1;
        }
    }
    vis[sx][sy]=0;
    queue<pii> Q;
    Q.push({sx, sy});
    fill_vis(vis, Q);
}

void push_Q(int vis[105][105], int x, int y, queue<pii>& Q){
    if(arr[x][y]!='*'){
        vis[x][y]=0;
        Q.push({x, y});
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    while(TC--){
        cin >> H >> W;
        vector<pii> prisons;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> arr[i][j];
                if(arr[i][j]=='$') prisons.push_back({i, j});
            }
        }
        int vis1[105][105]={};
        int vis2[105][105]={};

        sol(prisons[0].first, prisons[0].second, vis1);
        sol(prisons[1].first, prisons[1].second, vis2);

        int ans1=1e18;
        int ans2=1e18;

        /*for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cout << vis1[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cout << vis2[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";*/
        int vis[105][105]={};
        memset(vis, -1, sizeof(vis));
        queue<pii> Q;
        for(int i=0; i<H; i++){
            push_Q(vis, i, 0, Q);
            push_Q(vis, i, W-1, Q);
        }

        for(int i=0; i<W; i++){
            push_Q(vis, 0, i, Q);
            push_Q(vis, H-1, i, Q);
        }

        fill_vis(vis, Q);

        /*for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cout << vis[i][j] << " ";
            }
            cout << "\n";
        }*/

        int ans=vis[prisons[0].first][prisons[0].second]+vis[prisons[1].first][prisons[1].second];
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(arr[i][j]!='*'){
                    if(vis[i][j]==-1||vis1[i][j]==-1||vis2[i][j]==-1) continue;
                    ans=min(ans, vis[i][j]+(arr[i][j]=='#')+vis1[i][j]+vis2[i][j]);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}