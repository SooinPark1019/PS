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

char arr[105][105];
vector<int> graph[10005];
vector<pii> pos;
int num[105][105];
int N;
char T;

void sol(vector<int> dx, vector<int> dy, int c){
    for(int i=0; i<pos.size(); i++){
        int x=pos[i].first;
        int y=pos[i].second;
        //cout << "x : " << x << " y : " << y << "\n";
        for(int k=0; k<dx.size(); k++){
            for(int j=1; j<=c; j++){
                int nx=x+dx[k]*j;
                int ny=y+dy[k]*j;
                //cout << "nx : " << nx << " ny : " << ny << "\n";
                if(nx<0||nx>=N||ny<0||ny>=N) break;
                if(num[nx][ny]!=-1){
                    //cout << "nx : " << nx << " ny : " << ny << "\n";
                    graph[i].push_back(num[nx][ny]);
                    graph[num[nx][ny]].push_back(i);
                    //cout << i << " " << num[nx][ny] << "\n";
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;
    memset(num, -1, sizeof(num));
    int id=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j]!='.'){
                //cout << i << " " << j << "\n";
                pos.push_back({i, j});
                num[i][j]=id;
                id++;
            }
        }
    }
    
    if(T=='R'){
        vector<int> dx={1, 0};
        vector<int> dy={0, 1};
        sol(dx, dy, N);
    }
    else if(T=='B'){
        vector<int> dx={1, 1};
        vector<int> dy={1, -1};
        sol(dx, dy, N);
    }
    else if(T=='Q'){
        vector<int> dx={1, 0, 1, 1};
        vector<int> dy={0, 1, 1, -1};
        sol(dx, dy, N);
    }
    else if(T=='N'){
        vector<int> dx={1, 1, 2, 2};
        vector<int> dy={-2, 2, -1, 1};
        sol(dx, dy, 1);
    }
    else{
        vector<int> dx={1, 0, 1, 1};
        vector<int> dy={0, 1, 1, -1};
        sol(dx, dy, 1);
    }
    if(id==1){
        cout << "YES";
        return 0;
    }
    vector<int> check(id+1, 0);
    vector<pii> ans;
    queue<int> Q;
    Q.push(id-1);
    check[id-1]=1;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto i : graph[x]){
            if(check[i]!=0) continue;
            check[i]=1;
            ans.push_back({i, x});
            Q.push(i);
        }
    }
    reverse(all(ans));
    if(ans.size()!=id-1) cout << "NO";
    else{
        cout << "YES\n";
        for(auto p : ans){
            cout << pos[p.first].first+1 << " " << pos[p.first].second+1 << " " << pos[p.second].first+1 << " " << pos[p.second].second+1 << "\n";
        }
    }
    return 0;
}