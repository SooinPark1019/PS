#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
const int debug = 1;
const int MAX = 1<<15+5;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A;
    vector<int> B;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }
    vector<int> prefix;
    for(int i=0; i<N; i++){
        if(i==0) prefix.push_back(A[i]);
        else{
            prefix.push_back(prefix.back()+A[i]);
        }
    }
    int x=0;
    while(x<N){
        if(prefix[x]>M) break;
        x++;
    }
    x--;
    if(x<0) cout << -1;
    else{
        vector<int> ans;
        vector<pii> suffixmax(x+1);
        for(int i=x; i>=0; i--){
            if(i==x) suffixmax[i]={B[i], i};
            else{
                if(suffixmax[i+1].first<=B[i]){
                    suffixmax[i]={B[i], i};
                }
                else suffixmax[i]=suffixmax[i+1];
            }
        }
        int curA=0;
        int curB=0;
        int curtime=0;
        while(curA<=x&&curB<=x&&curtime<=M){
            int index=suffixmax[curB].second;
            int a=suffixmax[curB].first;
            while(curB<=index){
                curtime+=B[curB];
                curB++;
            }
            if(curtime>M) break;
            while(curtime<=M&&curA<=x){
                int balloon=0;
                while(curA<=x&&prefix[curA]<=curtime){
                    balloon++;
                    curA++;
                }
                if(balloon==0) break;
                while(balloon--){
                    ans.push_back(curtime);
                    curtime+=a;
                    if(curtime>M) break;
                }
            }
        }
        while(curB<=x){
            curtime+=B[curB];
            curB++;
        }
        if(curtime<=M) cout << -1;
        else{
            cout << ans.size() << "\n";
            for(auto k : ans){
                if(k<=M) cout << k << " "; 
            }
        }
    }
    return 0;
}