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
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/

vector<long long> Fenwick;
int N;

void update(int index, long long value){
    while(index<=N){
        Fenwick[index]+=value;
        index+=index&(-index);
    }
    return;
}
long long sum(int index){
    long long ret=0;
    while(index>0){
        ret+=Fenwick[index];
        index-=index&(-index);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        cin >> N;
        Fenwick.clear();
        Fenwick.resize(N+1);
        int ans=0;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            ans+=i-sum(a);
            update(a, 1);
        }
        cout << ans << "\n";
    }
    
    return 0;
}
