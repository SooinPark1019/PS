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
const int MAXN = (1<<18)+5;
const int D = 20;

const int MAX=200005;
int N, sub[MAX];
vector<pii> graph[MAX];
bool visited[MAX];

int getSub(int x, int px){
    sub[x]=1;
    for(auto& p : graph[x]){
        if(visited[p.first]||p.first==px) continue;
        sub[x]+=getSub(p.first, x);
    }
    return sub[x];
}

int getCentorid(int x){
    for(auto& p : graph[x]){
        if(sub[x]<2*sub[p.first]&&sub[p.first]<sub[x]){
            sub[x]-=sub[p.first];
            sub[p.first]+=sub[x];
            return getCentorid(p.first);
        }
    }
    return x;
}

void Getpaths(int cur, int par, int maxw, int sumw, vector<pii>& V){
    V.push_back({maxw, sumw});
    for(auto& p : graph[cur]){
        if(visited[p.first]||p.first==par) continue;
        Getpaths(p.first, cur, max(maxw, p.second), (sumw+p.second)%mod, V);
    }
}   

int dnc(int x){
    x=getCentorid(x);
    //cout << "centroid : " << x << "\n";
    visited[x]=1;
    vector<pii> paths;
    int ans=0;
    int minus=0;
    for(auto p : graph[x]){
        if(visited[p.first]) continue;
        //cout << "nxt : " << p.first << "\n";
        vector<pii> temp;
        Getpaths(p.first, x, p.second, p.second, temp);
        sort(all(temp));
        int cur=0;
        int a=0;
        for(auto i : temp){
            //cout << i.first << " " << i.second << "\n";
            minus+=i.first*(cur+i.second*a%mod)%mod;
            minus%=mod;
            cur+=i.second;
            cur%=mod;
            a++;
            paths.push_back(i);
        }
    }
    sort(all(paths));
    for(auto i : paths){
        ans+=i.first*i.second%mod;
        ans%=mod;
    }
    int cur=0;
    int a=0;
    for(auto i : paths){
        ans+=i.first*(cur+i.second*a%mod)%mod;
        ans%=mod;
        cur+=i.second;
        cur%=mod;
        a++;
    }
    //cout << ans << " " << minus << "\n";
    ans-=minus;
    ans+=mod;
    ans%=mod;
    for(auto p : graph[x]){
        if(visited[p.first]) continue;
        ans+=dnc(p.first);
        ans%=mod;
    }
    return ans;
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