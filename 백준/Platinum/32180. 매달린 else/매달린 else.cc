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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

vector<string> V;
int i=-1;

void sol(string state, int bracket){
    int cnt=0;
    while(1){
        i++;
        if(i>=V.size()) return;
        //assert(i>=0&&i<V.size());
        cout << V[i] << " ";
        if(V[i]=="{"){
            if(i==0){
                sol("0", 1);
            }
            else{
                string a=V[i-1];
                sol(a, 1);
                if((a=="else"||V[i+1]!="else")&&bracket==0){
                    cout << "} ";
                    return;
                }
            }
        }
        else if(V[i]=="}"){
            return;
        }
        else if(V[i]=="end"){
            return;
        }
        else if(V[i]=="if"||V[i]=="else"){
            if(V[i+1]=="{"){
                continue;
            }
            else{
                cout << "{ ";
                string a=V[i];
                sol(a, 0);
                assert(i+1<V.size());
                if((a=="else"||V[i+1]!="else")&&bracket==0){
                    cout << "} ";
                    return;
                }
            }
        }
        else if(V[i]==";"){
            if(bracket==0){
                cout << "} ";
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt=0;
    while(1){
        string S;
        cin >> S;
        V.push_back(S);
        if(S=="end") break;
    }
    
    sol("0" , 1);
    return 0;
}