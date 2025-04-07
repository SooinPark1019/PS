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

    int TC;
    cin >> TC;
    while(TC--){
        string X, Y, W;
        cin >> X >> Y >> W;

        map<char, int> firstM;
        map<char, int> secondM;

        int firstleft=0, firstright=X.length()-1, secondleft=0, secondright=Y.length()-1;
        int flag=0;
        int firstpointer=0;
        int secondpointer=0;

        vector<int> firststack;
        vector<int> secondstack;

        firststack.push_back(-1);
        secondstack.push_back(-1);
        
        while(firstpointer<W.length()){
            if(X[firstleft]==W[firstpointer]){
                firststack.push_back(firstleft);
                firstpointer++;
            }
            firstleft++;
        }
        while(secondpointer<W.length()){
            if(Y[secondleft]==W[secondpointer]){
                secondstack.push_back(secondleft);
                secondpointer++;
            }
            secondleft++;
        }
        for(int i=firstleft; i<=firstright; i++){
            firstM[X[i]]++;
        }
        for(int i=secondleft; i<=secondright; i++){
            secondM[Y[i]]++;
        }

        //cout << "fl : " << firstleft << " fr : " << firstright << " sl : " << secondleft << " " << " sr : " << secondright << " flag : " << flag << "\n";

        for(int i=0; i<26; i++){
            char c=i+'a';
            if(firstM[c]>0&&secondM[c]>0) flag=1;
        }

        while(firstpointer>0){
            firstpointer--;
            while(firstright>=0){
                firstM[X[firstright]]--;
                if(X[firstright]==W[firstpointer]){
                    firstright--;
                    break;
                }
                firstright--;
            }
            while(secondright>=0){
                secondM[Y[secondright]]--;
                if(Y[secondright]==W[firstpointer]){
                    secondright--;
                    break;
                }
                secondright--;
            }
            firststack.pop_back();
            secondstack.pop_back();
            while(firstleft!=firststack.back()+1){
                firstleft--;
                firstM[X[firstleft]]++;
            }
            while(secondleft!=secondstack.back()+1){
                secondleft--;
                secondM[Y[secondleft]]++;
            }
            for(int i=0; i<26; i++){
                char c=i+'a';
                if(firstM[c]>0&&secondM[c]>0) flag=1;
            }
            //cout << "fl : " << firstleft << " fr : " << firstright << " sl : " << secondleft << " " << " sr : " << secondright << " flag : " << flag << "\n";
        }
        cout << flag << "\n";
    }

    return 0;
}
