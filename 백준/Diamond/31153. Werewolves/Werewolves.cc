#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

const int mod = 998244353;

//const int INF=1e18;

using namespace std;

int color[3005];
int totalcolor[3005];
vector<int> graph[3005];
int sz[3005];

int ans=0;

vector<int> sol(int node, int par, int C){
    vector<int> ret(3, 0);
    if(color[node]==C) ret[2]=1;
    else ret[0]=1;
    for(auto i : graph[node]){
        if(i==par) continue;
        vector<int> temp=sol(i, node, C);
        int a=ret.size()/2;
        int b=temp.size()/2;
        int c=min(totalcolor[C], a+b);
        temp[b]++;
        vector<int> temp2(2*c+1);
        for(int i=0; i<ret.size(); i++){
            for(int j=0; j<temp.size(); j++){
                int index=i-a+j-b;
                if(abs(i-a+j-b)>c) continue;
                temp2[index+c]+=ret[i]*temp[j]%mod;
                temp2[index+c]%=mod;
            }
        }
        swap(ret, temp2);
    }
    /*if(color[node]==C){
        ret.pop_back();
        reverse(all(ret));
        ret.push_back(0);
        reverse(all(ret));
    }
    else{
        reverse(all(ret));
        ret.pop_back();
        reverse(all(ret));
        ret.push_back(0);
    }*/
    //cout << "node : " << node << " color : " << C << "\n";
    //for(auto i : ret) cout << i << " ";
    //cout << "\n";
    for(int i=ret.size()/2+1; i<ret.size(); i++){
        ans+=ret[i];
        ans%=mod;
    }
    return ret;
}

int cal_cz(int node, int par){
    sz[node]=1;
    for(auto i : graph[node]){
        if(i==par) continue;
        sz[node]+=cal_cz(i, node);
    }
    return sz[node];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> color[i];
        totalcolor[color[i]]++;
    }
    for(int i=1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cal_cz(1, -1);
    for(int i=1; i<=N; i++){
        if(totalcolor[i]==0) continue;
        sol(1, -1, i);
    }
    cout << ans;
}
