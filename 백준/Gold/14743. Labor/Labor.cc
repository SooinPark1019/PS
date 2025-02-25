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
int N, M, Y1, Y2;
vector<int> uprope, downrope;
int sol(vector<int>& uprope, vector<int>& downrope){
    vector<int> rc;
    for(int i=0; i<uprope.size(); i++){
        rc.push_back(downrope.end()-upper_bound(all(downrope), uprope[i]));
    }
    vector<int> suffixsum(uprope.size());
    int cur=0;
    //for(auto i : rc) cout << i << " ";
    //cout << "\n";
    for(int i=uprope.size()-1; i>=0; i--){
        suffixsum[i]=cur;
        cur+=rc[i];
        cur%=mod;
    }
    //for(auto i : suffixsum) cout << i << " ";
    //cout << "\n";
    vector<int> suffixsum2(uprope.size());
    cur=0;
    for(int i=uprope.size()-1; i>=0; i--){
        cur+=suffixsum[i];
        cur%=mod;
        suffixsum2[i]=cur;
    }
    //for(auto i : suffixsum2) cout << i << " ";
    //cout << "\n";
    int ret=0;
    for(int i=0; i<downrope.size(); i++){
        int index=upper_bound(all(uprope), downrope[i])-uprope.begin();
        if(index>=uprope.size()) continue;
        //cout << "index : " << index << "\n";
        ret+=suffixsum2[index];
        ret%=mod;
    }
    return ret;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N >> M >> Y1 >> Y2;

    
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        uprope.push_back(a);
    }

    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        downrope.push_back(a);
    }

    sort(all(uprope));
    sort(all(downrope));

    cout << (sol(uprope, downrope)+sol(downrope, uprope))%mod << "\n";

    return 0;
}
