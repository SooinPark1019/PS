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
#define int long long
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
간선 거꾸로 놓는 거까지는 맞을 거 같다
*/
char arr[1005][1005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, Y;
    cin >> X >> Y;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            cin >> arr[i][j];
        }
    }
    int flag=0;
    if(Y%2){
        for(int i=0; i<X; i++){
            if(arr[i][Y/2-1]=='X'&&arr[i][Y/2]=='X'&&arr[i][Y/2+1]=='X'){
                arr[i][Y/2-1]='W';
                arr[i][Y/2]='Y';
                arr[i][Y/2+1]='W';
                flag=1;
                break;
            }
        }
    }
    else{
        for(int i=0; i<X; i++){
            if(arr[i][Y/2-2]=='X'&&arr[i][Y/2-1]=='X'&&arr[i][Y/2]=='X'&&arr[i][Y/2+1]=='X'){
                arr[i][Y/2-2]='W';
                arr[i][Y/2-1]='Y';
                arr[i][Y/2]='Y';
                arr[i][Y/2+1]='W';
                flag=1;
                break;
            }
        }
    }
    if(flag==0) cout << "NO";
    else{
        cout << "YES\n";
        for(int i=0; i<X; i++){
            for(int j=0; j<Y; j++){
                if(arr[i][j]=='X') cout << "B";
                else cout << arr[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}