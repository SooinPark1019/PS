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
const int debug = 1;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<pii> PQ;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        PQ.push({a, i});
    }
    vector<pii> ans;
    int flag=0;
    while(!PQ.empty()){
        vector<pii> temp;
        int a=PQ.top().first;
        int b=PQ.top().second;
        PQ.pop();
        while(a>0&&!PQ.empty()){
            temp.push_back({PQ.top().first-1, PQ.top().second});
            ans.push_back({PQ.top().second, b});
            a--;
            PQ.pop();
        }
        if(a>0){
            flag=1;
            break;
        }
        for(auto j : temp){
            //cout << "j : " << j.first << "\n";
            if(j.first>0) PQ.push(j);
        }
    }
    if(flag==1) cout << -1 << "\n";
    else{
        vector<vector<int>> arr(N+1, vector<int>(N+1));
        for(auto p : ans){
            arr[p.first][p.second]=1;
            arr[p.second][p.first]=1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}