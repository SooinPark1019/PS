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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    map<string, int> M;
    map<string, int> times[305];
    vector<int> total(N+1);
    map<string, int> vis;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        M[s]={1};
        for(int j=1; j<=N; j++){
            times[j][s]=0;
        }
    }

    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        int sz, val;
        cin >> sz >> val;
        total[val]++;
        for(int j=0; j<sz; j++){
            string s;
            cin >> s;
            M[s]=max(M[s], val);
            times[val][s]++;
        }
    }

    for(int i=1; i<=N; i++){
        int flag=0;
        for(auto p : times[i]){
            if(p.second==total[i]&&M[p.first]==i&&vis[p.first]==0){
                flag=1;
                vis[p.first]=1;
                cout << p.first << " ";
                break;
            }
        }
        if(flag==1) continue;
        for(auto p : M){
            if(vis[p.first]||p.second>i) continue;
            cout << p.first << " ";
            vis[p.first]=1;
            break;
        }
    }

    return 0;
}
