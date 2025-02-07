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
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/

int N, A, B;

vector<int> graph[100005];

vector<int> sol(int node, int par){
    vector<int> ret(2, 0);
    ret[1]=1;
    for(auto i : graph[node]){
        if(i==par) continue;
        vector<int> temp=sol(i, node);
        vector<int> ret2(min(B+1, (int)ret.size()+(int)temp.size()-1), 0);
        assert(ret.size()<=B+1&&temp.size()<=B+1);
        for(int j=0; j<ret.size(); j++){
            if(ret[j]==0) continue;
            //cout << "j : " << j << " ret : " << ret[j] << "\n";
            for(int k=0; k<temp.size(); k++){
                if(temp[k]==0) continue;
                //cout << "k : " << k << " ret : " << temp[k] << "\n";
                if(k==A||k==B){
                    ret2[j]+=ret[j]*temp[k]%mod;
                    if(ret2[j]>=mod) ret2[j]-=mod;
                }
                if(j+k<=B){
                    ret2[j+k]+=ret[j]*temp[k]%mod;
                    if(ret2[j+k]>=mod) ret2[j+k]-=mod;
                }
            }
        }
        swap(ret, ret2);
    }
    if(node==1) cout << (ret[0]+ret[A]+ret[B])%mod;
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A >> B;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    sol(1, -1);
}
