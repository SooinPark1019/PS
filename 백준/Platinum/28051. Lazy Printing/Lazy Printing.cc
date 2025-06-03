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

    string S;
    cin >> S;
    int K;
    cin >> K;

    int ans=0;
    while(1){
        //cout << "S : " << S << endl;
        int cur=1;
        vector<int> f;
        f.push_back(0);
        int j=0;
        int lastindex=S.length();
        int flag1=0;
        for(int i=1; i<S.length(); i++){
            while(j>0&&S[i]!=S[j]){
                j=f[j-1];
            }
            if(S[i]==S[j]) f.push_back(++j);
            else f.push_back(0);
            if(S[i%cur]==S[i]) continue;
            while(1){
                cur++;
                if(cur>K) break;
                int flag=0;
                for(int k=cur-1; k<i; k+=cur){
                    if(k+cur>i){
                        for(int a=k+1; a<=i; a++){
                            //cout << S[a] << " " << S[a-(k+1)] << "\n";
                            if(S[a]!=S[a-(k+1)]){
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1) break;
                    }
                    else{
                        if(f[k+cur]!=k+1){
                            flag=1;
                            break;
                        }
                    }
                }
                if(!flag) break;
            }
            if(cur>K){
                lastindex=i;
                break;
            }
        }
        ans++;
        //cout << "lastindex : " << lastindex << "\n";
        if(lastindex==S.length()) break;
        assert(lastindex>0);
        S=S.substr(lastindex);
    }
    
    cout << ans;

    return 0;
}
