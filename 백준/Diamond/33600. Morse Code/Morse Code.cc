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
DP[i][j][k]=지금까지 배정한 게 i개, 현재 거리 j개, 다음 거리 k개

역추적은 어떻게 하면 될까

역추적 경로를 생성한 다음에
경로를 다시 정방향으로 가는 느낌으로 하면 될 것 같다.
*/

int DP[205][205][205];
array<int, 3> backtrack[205][205][205];
string ans[205];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<=N; k++){
                DP[i][j][k]=1e18;
            }
        }
    }

    vector<pii> V;

    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        int a=stoi(S.substr(2));
        V.push_back({a, i});
    }

    sort(all(V));

    vector<int> prefix;
    for(int i=0; i<N; i++){
        if(i>0) prefix.push_back(prefix.back()+V[i].first);
        else prefix.push_back(V[i].first);
    }
    DP[0][1][0]=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<=N; k++){
                if(DP[i][j][k]==1e18) continue;
                if(j>0&&DP[i+1][j-1][k]>DP[i][j][k]){
                    DP[i+1][j-1][k]=DP[i][j][k];
                    backtrack[i+1][j-1][k]={i, j, k};
                }
                if(k+j<=N&&DP[i][k+j][j]>DP[i][j][k]+prefix[N-1-i]){
                    DP[i][k+j][j]=DP[i][j][k]+prefix[N-1-i];
                    backtrack[i][k+j][j]={i, j, k};
                }
            }
        }
    }

    vector<array<int, 3>> tracking;
    int curi=N, curj=0, curk=0;
    int t=0;
    while(curi!=0||curj!=1||curk!=0){
        tracking.push_back({curi, curj, curk});
        array<int, 3> nxt=backtrack[curi][curj][curk];
        curi=nxt[0];
        curj=nxt[1];
        curk=nxt[2];
    }

    reverse(all(tracking));
    reverse(all(V));

    vector<string> temp[2];

    temp[0].push_back("");
    int curpointer=0;

    for(auto a : tracking){
        int nxti=a[0];
        int nxtj=a[1];
        int nxtk=a[2];
        //cout << "nxti : " << nxti << " nxtj : " << nxtj << " nxtk : " << nxtk << "\n";
        if(nxti>curi){
            //cout << "curpointer : " << curpointer << " V[curpointer].second : " << V[curpointer].second << "\n";
            ans[V[curpointer].second]=temp[0].back();
            curpointer++;
            temp[0].pop_back();
        }
        else{
            vector<string> nxttemp[2];
            nxttemp[0]=temp[1];
            for(auto s : temp[0]){
                nxttemp[0].push_back(s+".");
                nxttemp[1].push_back(s+"-");
            }
            swap(temp, nxttemp);
        }
        curi=nxti;
        curj=nxtj;
        curk=nxtk;
    }

    for(int i=0; i<N; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
