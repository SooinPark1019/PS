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
const int D = 20;

const int MAX=200005;
int N, sub[MAX];
vector<pii> graph[MAX];
bool visited[MAX];
int getSub(int x, int px){
    sub[x]=1;
    for(auto& nx : graph[x]){
        if(visited[nx.first]||nx.first==px) continue;
        sub[x]+=getSub(nx.first, x);
    }
    return sub[x];
}
int getCentroid(int x){
    for(auto& nx : graph[x]){
        if(sub[x]<2*sub[nx.first]&&sub[nx.first]<sub[x]){
            sub[x]-=sub[nx.first];
            sub[nx.first]+=sub[x];
            return getCentroid(nx.first);
        }
    }
    return x;
}
void findinc(int x, int par, int idx, int prevw, vector<int>& inc){
    inc.push_back(idx);
    for(auto i : graph[x]){
        if(i.first==par||i.second<=prevw||visited[i.first]) continue;
        findinc(i.first, x, idx, i.second, inc);
    }
    return;
}
void finddec(int x, int par, int idx, int prevw, vector<int>& dec){
    dec.push_back(idx);
    for(auto i : graph[x]){
        if(i.first==par||i.second>=prevw||visited[i.first]) continue;
        finddec(i.first, x, idx, i.second, dec);
    }
}
int dnc(int x){
    x=getCentroid(x);
    //cout << x << "\n";
    visited[x]=1;
    vector<int> inc;
    vector<int> dec;
    for(auto& nx : graph[x]){
        if(visited[nx.first]) continue;
        findinc(nx.first, x, nx.second, nx.second, inc);
        finddec(nx.first, x, nx.second, nx.second, dec);
    }
    int ret=0;
    ret+=inc.size();
    ret+=dec.size();
    sort(all(inc));
    sort(all(dec));
    /*cout << "inc : ";
    for(auto i : inc){
        cout << i << " ";
    }
    cout << "\n" << "dec : ";
    for(auto i : dec){
        cout << i << " ";
    }
    cout << "\n";*/
    int pointer=0;
    for(int i=0; i<inc.size(); i++){
        while(pointer<dec.size()&&dec[pointer]<inc[i]){
            pointer++;
        }
        //cout << pointer << "\n";
        ret+=pointer;
    }
    //cout << ret << "\n";
    for(auto &nx : graph[x]){
        if(visited[nx.first]) continue;
        ret+=dnc(nx.first);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    getSub(1, -1);
    cout << dnc(1);
    
    return 0;
}