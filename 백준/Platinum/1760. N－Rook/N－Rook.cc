#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;

vector<int> graph[10005];
int T[10005];
int visited[10005]={};

bool DFS(int node){
    visited[node]=1;
    for(auto goal : graph[node]){
        if(T[goal]==-1||(visited[T[goal]]==-1&&DFS(T[goal]))){
            T[goal]=node;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int rownum[105][105];
    int colnum[105][105];
    memset(rownum, -1, sizeof(rownum));
    memset(colnum, -1, sizeof(colnum));
    int arr[105][105];
    for(int i=0; i<N; i++){
        int cnt=0;
        for(int j=0; j<M; j++){
            int a;
            cin >> a;
            arr[i][j]=a;
            if(a==0){
                rownum[i][j]=i*M+cnt;
            }
            if(a==2){
                cnt++;
            }
        }
    }
    for(int j=0; j<M; j++){
        int cnt=0;
        for(int i=0; i<N; i++){
            if(arr[i][j]==0){
                colnum[i][j]=j*N+cnt;
            }
            if(arr[i][j]==2){
                cnt++;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(rownum[i][j]!=-1&&colnum[i][j]!=-1){
                graph[rownum[i][j]].push_back(colnum[i][j]);
            }
        }
    }
    memset(T, -1, sizeof(T));
    int ans=0;
    for(int i=0; i<10005; i++){
        memset(visited, -1, sizeof(visited));
        if(DFS(i)) ans++;
    }
    cout << ans;
    return 0;
}
