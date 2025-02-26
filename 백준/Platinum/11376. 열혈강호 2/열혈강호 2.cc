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

vector<int> graph[1005];
int T[1005];
int visitied[1005]={};

bool DFS(int node){
    visitied[node]=1;
    for(auto goal : graph[node]){
        if(T[goal]==-1||(visitied[T[goal]]==-1&&DFS(T[goal]))){
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
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            int b;
            cin >> b;
            graph[i].push_back(b);
        }
    }
    int ans=0;
    memset(T, -1, sizeof(T));
    for(int i=1; i<=N; i++){
        memset(visitied, -1, sizeof(visitied));
        if(DFS(i)) ans++;
        memset(visitied, -1, sizeof(visitied));
        if(DFS(i)) ans++;

    }
    cout << ans;
    return 0;
}
