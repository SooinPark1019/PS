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

set<pair<char, int>> V[3];//0-홀수 더하기, 1-짝수 곱하기, 2-나머지
set<pair<char, int>> total;

void printV0(){
    cout << (*V[0].begin()).first << " " << (*V[0].begin()).second << endl;
    total.erase(*V[0].begin());
    V[0].erase(V[0].begin());
}

void printV1(){
    cout << (*V[1].begin()).first << " " << (*V[1].begin()).second << endl;
    total.erase(*V[1].begin());
    V[1].erase(V[1].begin());
}

void printV2(){
    cout << (*V[2].begin()).first << " " << (*V[2].begin()).second << endl;
    total.erase(*V[2].begin());
    V[2].erase(V[2].begin());
}

void printtotal(){
    cout << (*total.begin()).first << " " << (*total.begin()).second << endl;
    total.erase(total.begin());
}

void erasepair(char c, int a){
    total.erase({c, a});
    if(c=='+'&&a%2!=0){
        V[0].erase({c, a});
    }
    else if(c=='*'&&a%2==0){
        V[1].erase({c, a});
    }
    else{
        V[2].erase({c, a});
    }
    return;
}

void alwayswin(){
    while(total.size()>0){
        printtotal();
        if(total.size()==0) return;
        char c;
        int a;
        cin >> c >> a;
        total.erase({c, a});
    }
    return;
}

void dosecond(){
    while(total.size()>0){
        char c;
        int a;
        cin >> c >> a;
        erasepair(c, a);
        if(total.size()==0) break;
        if(V[0].size()>0&&(V[0].size()%2!=0||(V[1].size()==0&&V[2].size()==0))) printV0();
        else if(V[1].size()>0) printV1();
        else printV2();
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int initial;
    for(int i=0; i<N; i++){
        char c;
        int a;
        cin >> c >> a;
        if(c=='+'&&a%2!=0) V[0].insert({c, a});
        else if(c=='*'&&a%2==0) V[1].insert({c, a});
        else V[2].insert({c, a});
        total.insert({c, a});
    }
    cin >> initial;

    if(V[1].size()==0){
        if((initial+V[0].size())%2==0){
            cout << "you" << endl;
            char c;
            int a;
            cin >> c >> a;
            total.erase({c, a});
            alwayswin();
        }
        else{
            cout << "me" << endl;
            alwayswin();
        }
    }
    else if(V[1].size()==1){
        if(V[0].size()%2!=0){
            cout << "me" << endl;
            printV1();
            char c;
            int a;
            cin >> c >> a;
            total.erase({c, a});
            alwayswin();
        }
        else{
            cout << "you" << endl;
            dosecond();
        }
    }
    else{
        cout << "you" << endl;
        dosecond();
    }
    
    return 0;
}