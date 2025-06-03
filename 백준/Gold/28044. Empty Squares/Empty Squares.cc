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

    int N, K, E;
    cin >> N >> K >> E;

    if(E==K&&E==N-(E+K)){
        if(E==1) cout << 2;
        else if(E==2) cout << 3;
        else if(E==3){
            cout << 3;
        }
        else if(E==4){
            cout << 2;
        }
        else cout << 0;
    }
    else if(E==K||E==N-(E+K)||K==N-(E+K)){
        int A, B;
        if(E==K){
            A=E;
            B=N-(E+K);
        }
        else if(E==N-(E+K)){
            A=E;
            B=K;
        }
        else{
            A=K;
            B=E;
        }
        if(B>A||B==0){
            if(A==1) cout << 1;
            else if(A==2) cout << 1;
            else cout << 0;
        }
        else{
            if(A==1) cout << 1;
            else if(A==2) cout << 2;
            else if(A==3){
                if(B==1){
                    cout << 1;
                }
                else cout << 2;
            }
            else if(A==4){
                if(B==1){
                    cout << 1;
                }
                else if(B==2){
                    cout << 0;
                }
                else{
                    cout << 1;
                }
            }
            else{
                cout << 0;
            }
        }
    }
    else cout << 0;

    return 0;
}
