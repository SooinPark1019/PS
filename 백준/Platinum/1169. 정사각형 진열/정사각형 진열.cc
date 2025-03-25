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
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define debug1(x,y) cout << x << " :: " << y << " "
#define coutn cout << "\n"
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

vector<pair<int, int>> cnt(1000005, {0, 0});

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    stack<pair<int, int>> S;
    vector<pair<int, int >> V;
    for(int i=0; i<N; i++){
        //cout << i << endl;
        int a;
        cin >> a;
        int cur_pos=a;
        while(!S.empty()){
            if(S.top().first*2<a){
                cur_pos=max(cur_pos, S.top().second+S.top().first*2);
                S.pop();
            }
            else{
                if(a>=S.top().first) cur_pos=max(cur_pos, S.top().second+2*S.top().first);
                else cur_pos=max(cur_pos, S.top().second+2*a);
                break;
            }
        }
        while(!S.empty()&&cur_pos>=S.top().second+S.top().first) S.pop();
        S.push({a, cur_pos});
        V.push_back({a, cur_pos});
    }
    //for(auto p : V) cout << p.first << " " << p.second << endl;
    //cout << "!" << endl;
    for(int i=0; i<N; i++){
        int start=V[i].second;
        for(int j=-V[i].first; j<V[i].first; j++){
            //cout << j+start<< "\n";
            int k=max(0, j+start);
            if(cnt[k].first<=V[i].first){
                cnt[k].first=V[i].first;
                cnt[k].second=i+1;  
            }
        }
    }
    set<int> ans;
    for(int i=0; i<=1000000; i++){
        if(cnt[i].second!=0){
            //cout << i << " " << cnt[i].first << " " << cnt[i].second << "\n";
            ans.insert(cnt[i].second);
        }
    }
    for(auto i : ans) cout << i << " ";
    return 0;
}