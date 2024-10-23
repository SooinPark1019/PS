#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

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
const ll MAX = 1e5+5;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    map<int, string> M;
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        int curindex=S.length()-2;
        int havepoint=0;
        for(auto i : S){
            if(i=='.'){
                havepoint=1;
                break;
            }
        }
        while(havepoint>0&&curindex>0&&(S[curindex]=='0'||S[curindex]=='.')){
            curindex--;
        }
        if(curindex==0) cout << "a" << "\n";
        else{
            while(curindex>=0){
                if(S[curindex]!='.') cout << (char)('a'+(S[curindex]-'0'));
                else cout << (char)('a'+11);
                curindex--;
            }
            cout << "\n";
        }
    }
    return 0;
}