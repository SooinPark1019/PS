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

vector<int> smallset;
vector<pii> smalledge;
int flag=0;

int N;
char smaller, bigger;
char arr[30][30];

void sol(int a){
    if(flag||a==N+1) return;
    if(smallset.size()==N/4){
        vector<int> largeset;
        for(int i=1; i<=24; i++){
            int isexist=0;
            for(auto j : smallset){
                if(j==i){
                    isexist=1;
                    break;
                }
            }
            if(isexist==0) largeset.push_back(i);
        }
        int flag2=0;
        for(auto i : smallset){
            for(auto j : largeset){
                if(arr[i][j]==bigger){
                    flag2=1;
                    break;
                }
            }
            if(flag2) break;
        }
        if(flag2==0){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(arr[i][j]=='F'){
                        cout << 'F';
                        continue;
                    }
                    if(arr[i][j]=='S'){
                        cout << 'S';
                        continue;
                    }
                    int iin=0, jin=0;
                    for(auto k : smallset){
                        if(i==k){
                            iin=1;
                            break;
                        }
                    }
                    for(auto k : smallset){
                        if(j==k){
                            jin=1;
                            break;
                        }
                    }
                    if(i==j) cout << ".";
                    else if(iin!=jin) cout << smaller;
                    else cout << bigger;
                }
                cout << "\n";
            }
            flag=1;
            return;
        }
    }
    sol(a+1);
    smallset.push_back(a);
    sol(a+1);
    smallset.pop_back();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int Scnt=0, Fcnt=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
            if(arr[i][j]=='S') Scnt++;
            if(arr[i][j]=='F') Fcnt++;
        }
    }

    if(Scnt>=Fcnt){
        smaller='F';
        bigger='S';
    }
    else{
        smaller='S';
        bigger='F';
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]==smaller){
                smalledge.push_back({i, j});
            }
        }
    }

    sol(1);

    return 0;
}
