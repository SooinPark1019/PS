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
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define int long long
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
스투라

작은 거 큰 거
개수와 누적합
*/
vector<int> graph[300005];

int ans=0;

vector<int> sol(int node, int par){
    vector<int> temp;
    for(auto i : graph[node]){
        if(i==par) continue;
        vector<int> a=sol(i, node);
        if(a.size()>0) a.push_back(a.back()+1);
        else a.push_back(1);
        if(a.size()>temp.size()) swap(a, temp);
        //cout << "a.size : " << a.size() << " temp.size : " << temp.size() << endl;
        for(int j=0; j<a.size(); j++){
            //cout << "j : " << j << " a[j] : " << a[j] << " temp[j] : " << temp[j] << "\n";
            ans+=2*a[a.size()-1-j]*temp[temp.size()-j-1];
            if(j==0) ans-=a[a.size()-1-j]*temp[temp.size()-j-1];
            temp[temp.size()-j-1]+=a[a.size()-1-j];
        }
    }
    //cout << "node : " << node << " ans : " << ans << "\n";
    //for(auto i : temp) cout << i << " ";
    //cout << "\n";
    return temp;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        for(int i=0; i<=N; i++){
            graph[i].clear();
        }
        ans=0;
        for(int i=0; i<N-1; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        sol(1, -1);
        cout << ans << "\n";
    }

    return 0;
}
