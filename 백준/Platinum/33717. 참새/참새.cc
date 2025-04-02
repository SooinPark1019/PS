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
A_1은 0의 개수
A_N은 1의 개수
맨 왼쪽은 반드시 1
맨 오른쪽은 반드시 0

오른쪽을 보는 애들을 끼워넣는다고 생각을 해보자

1들의 나열
2들의 나열
3들의 나열...
이런 느낌?
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    if(N==1){
        cout << -1;
        return 0;
    }
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    int left=0;
    int right=V[0];
    vector<int> ans;
    for(auto i : V){
        //cout << i << " " << left << " " << right << "\n";
        if(i==right){
            ans.push_back(1);
            left++;
        }
        else if(i==left){
            ans.push_back(0);
            right--;
        }
        else{
            break;
        }
    }
    if(ans.size()!=N||ans.back()!=0){
        left=0;
        right=V[0];
        ans.clear();
        for(auto i : V){
            //cout << i << " " << left << " " << right << "\n";
            if(i==left){
                ans.push_back(0);
                right--;
            }
            else if(i==right){
                ans.push_back(1);
                left++;
            }
            else{
                break;
            }
        }
        if(ans.size()!=N||ans.back()!=0) cout << -1;
        else for(auto i : ans) cout << i << " ";
    }
    else for(auto i : ans) cout << i << " ";

    return 0;
}
