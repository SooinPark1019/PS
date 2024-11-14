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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> V;
    int total=0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
        total+=a;
    }
    int curl=0;
    int curr=N-1;
    int lpointer=0;
    int rpointer=N-1;
    int lsum=0;
    int lcnt=0;
    int rsum=0;
    int rcnt=0;
    int curtotal=total;
    int curcnt=N;
    vector<int> ans;
    while(curl<curr){
        int flag=0;
        while((curtotal-lsum-V[lpointer])*N<=total*(curcnt-lcnt-1)&&lpointer<curr){
            flag=1;
            lsum+=V[lpointer];
            lpointer++;
            lcnt++;
            if(lsum*N>=total*lcnt){
                for(int i=curl; i<lpointer; i++){
                    ans.push_back(i+1);
                }
                curl=lpointer;
                curtotal-=lsum;
                curcnt-=lcnt;
                lsum=0;
                lcnt=0;
                break;
            }
        }
        //cout << (curtotal-rsum-V[rpointer])*N << " " << total*(curcnt-rcnt-1)<< "\n";
        while((curtotal-rsum-V[rpointer])*N<=total*(curcnt-rcnt-1)&&curl<rpointer){
            //cout << curtotal-V[rpointer] << "\n";
            flag=1;
            rsum+=V[rpointer];
            rpointer--;
            rcnt++;
            if(rsum*N>=total*rcnt){
                for(int i=curr; i>rpointer; i--){
                    ans.push_back(i+1);
                }
                curr=rpointer;
                curtotal-=rsum;
                curcnt-=rcnt;
                rsum=0;
                rcnt=0;
            }
        }
        //cout << curl << " " << curr << "\n";
        if(lpointer==curr){
            for(int i=curl; i<=curr; i++){
                ans.push_back(i+1);
            }
            break;
        }
        if(rpointer==curl){
            for(int i=curr; i>=curl; i--){
                ans.push_back(i+1);
            }
            break;
        }
        if(flag==0){
            break;
        }
    }
    if(ans.size()<N) cout << "impossible";
    else{
        reverse(all(ans));
        for(auto i : ans) cout << i << " ";
    }
    return 0;
}