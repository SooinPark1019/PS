#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2005];
int flow[2005][2005]={};
int cap[2005][2005];
int visited[2005];
int s=2002;
int e=2001;
int ans=0;
int T[2005];

bool DFS(int node){
    visited[node]=1;
    for(auto goal : graph[node]){
        if(T[goal]==-1||visited[T[goal]]==-1&&DFS(T[goal])){
            T[goal]=node;
            flow[node][goal]=1;
            flow[goal][e]=1;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    graph[s].push_back(0);
    cap[s][0]=K;
    for(int i=1; i<=N; i++){
        graph[0].push_back(i);
        cap[0][i]=K;
    }
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            int b;
            cin >> b;
            graph[i].push_back(b+1000);
            cap[i][b+1000]=1;
        }
    }
    for(int i=1; i<=M; i++){
        graph[i+1000].push_back(e);
        cap[i+1000][e]=1;
    }
    memset(T, -1, sizeof(T));
    int ans=0;
    for(int i=1; i<=N; i++){
        memset(visited, -1, sizeof(visited));
        if(DFS(i)) ans++;
    }
    while(1){
        memset(visited, -1, sizeof(visited));
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            for(auto i : graph[x]){
                if(visited[i]!=-1||cap[x][i]<=flow[x][i]) continue;
                visited[i]=x;
                Q.push(i);
                if(i==e) break;
            }
        }
        if(visited[e]==-1) break;
        int f=987654321;
        for(int i=e; i!=s; i=visited[i]){
            f=min(f, cap[visited[i]][i]-flow[visited[i]][i]);
        }
        for(int i=e; i!=s; i=visited[i]){
            flow[visited[i]][i]+=f;
            flow[i][visited[i]]-=f;
        }
        ans+=f;
    }
    cout << ans;
    return 0;
}
