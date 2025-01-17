#include <bits/stdc++.h>
#include <ios>
#define int long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

using namespace std;

vector<pii> graph[100005];
set<pii> childs[100005];
vector<pii> query[100005];

int cnt[100005];
int ans[100005];

pii dfs(int cur_node, int par){
    if(graph[cur_node].size()==1){
        childs[cur_node].insert({0, cur_node});
    }
    for(auto i : graph[cur_node]){
        if(i.first==par) continue;
        pii A=dfs(i.first, cur_node);
        childs[cur_node].insert({A.first+i.second, A.second});
    }
    return *childs[cur_node].begin();
}

void dfs2(int cur_node, int par){
    //cout << "curnode : " << cur_node << "\n";
    for(auto p : query[cur_node]){
        ans[p.second]=cnt[p.first];
    }
    for(auto i : graph[cur_node]){
        if(i.first==par) continue;
        //cout << "i : " << i.first << "\n";
        pii A=*childs[cur_node].begin();
        //cout << "A : " << A.first << " " << A.second << "\n";
        if(A.second==(*childs[i.first].begin()).second){
            //cout << i.first << "\n";
            cnt[A.second]--;
            //cout << cnt[A.second] << "\n";
            childs[cur_node].erase(A);
            cnt[(*childs[cur_node].begin()).second]++;
            //cout << (*childs[cur_node].begin()).second << "\n";
        }
        pii B=*childs[cur_node].begin();
        B.first+=i.second;
        cnt[(*childs[i.first].begin()).second]--;
        childs[i.first].insert(B);
        cnt[(*childs[i.first].begin()).second]++;
        dfs2(i.first, cur_node);
        cnt[(*childs[i.first].begin()).second]--;
        childs[i.first].erase(B);
        cnt[(*childs[i.first].begin()).second]++;
        if(A.second==(*childs[i.first].begin()).second){
            cnt[(*childs[cur_node].begin()).second]--;
            childs[cur_node].insert(A);
            cnt[A.second]++;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        query[b].push_back({a, i});
    }

    dfs(1, -1);
    for(int i=1; i<=N; i++){
        pii A=*childs[i].begin();
        cnt[A.second]++;
    }
    dfs2(1, -1);
    for(int i=0; i<Q; i++) cout << ans[i] << "\n";
}