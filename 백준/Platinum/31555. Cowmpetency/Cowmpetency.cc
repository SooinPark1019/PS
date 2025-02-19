#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define int long long
#define ll long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
/*void m_erase(ordered_set &OS, ll val){
    ll index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
일단 h[j]는 항상 최댓값이 돼야 함
a[j]보다 크고 h[j]보다 작은 애들은 최댓값이 되어서는 안됨
일단 그러면 최댓값이 되어야 하는 애들을 정하면서 가능한지 검토

최댓값이 되어서는 안되는 애들에 대해서 왼쪽의 가장 가까우면서 최댓값이 되어도 되는 0을 찾음
얘네를 해당 값으로 갱신
나머지 0에는 그냥 1을 박아버리자
*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    int t=0;
    int totalTC=TC;
    while(TC--){
        t++;
        int N, Q, C;
        cin >> N >> Q >> C;
        vector<int> V;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            V.push_back(a);
        }
        vector<int> A(N);
        vector<int> H(N);
        for(int i=0; i<Q; i++){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            A[a]++;
            H[b]++;
        }
        int possiblezero=-1;
        int curmax=1;
        int cur=0;
        int flag=0;
        for(int i=0; i<N; i++){
            //cout << "i : " << i << "\n";
            if(cur==0&&V[i]==0) possiblezero=i;
            if(H[i]){
                cur-=H[i];
                if(cur==0&&V[i]==0) possiblezero=i;
                if(cur>0){
                    flag=1;
                    break;
                }
                //cout << "V[i] : " << V[i] << " curmax : " << curmax << "\n";
                if(V[i]==0){
                    V[i]=max(V[i], curmax+1);
                }
                else if(V[i]<=curmax){
                    flag=1;
                    break;
                }
            }
            if(cur>0&&V[i]>curmax){
                if(possiblezero==-1){
                    flag=1;
                    break;
                }
                //cout << "possiblezero : " << possiblezero << "\n";
                V[possiblezero]=max(V[possiblezero], V[i]);
            }
            curmax=max(curmax, V[i]);
            //cout << "curmax : " << curmax << " C : " << C << "\n";
            if(curmax>C){
                flag=1;
                break;
            }
            if(A[i]) cur+=A[i];
        } 
        curmax=1;
        cur=0;
        for(int i=0; i<N; i++){
            if(H[i]&&V[i]<=curmax){
                flag=1;
                break;
            }
            curmax=max(curmax, V[i]);
        }
        if(flag){
            cout << -1;
        }
        else{
            for(int i=0; i<N; i++){
                cout << max(1ll, V[i]);
                if(i!=N-1) cout << " ";
            }
        }
        if(t!=totalTC)cout << "\n";
    }

    return 0;
}
