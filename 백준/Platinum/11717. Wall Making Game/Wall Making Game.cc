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
int DP[25][25][25][25];
char arr[25][25];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W;
    cin >> H >> W;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++) cin >> arr[i][j];
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for(int x1=0; x1+i<H; x1++){
                for(int y1=0; y1+j<W; y1++){
                    int x2=x1+i;
                    int y2=y1+j;
                    //cout << "x1 : " << x1 << " x2 : " << x2 << " y1 : " << y1 << " y2 : " << y2 << "\n";
                    if(i==0&&j==0){
                        if(arr[x1][y1]=='X') DP[x1][y1][x2][y2]=0;
                        else DP[x1][y1][x2][y2]=1;
                        continue;
                    }
                    vector<int> temp;
                    for(int x3=x1; x3<=x2; x3++){
                        for(int y3=y1; y3<=y2; y3++){
                            //cout << "x3 : " << x3 << " y3 : " << y3 << "\n";
                            if(arr[x3][y3]=='X') continue;
                            int a=0;
                            if(x3-1>=x1&&y3-1>=y1) a^=DP[x1][y1][x3-1][y3-1];
                            if(x3+1<=x2&&y3-1>=y1) a^=DP[x3+1][y1][x2][y3-1];
                            if(x3-1>=x1&&y3+1<=y2) a^=DP[x1][y3+1][x3-1][y2];
                            if(x3+1<=x2&&y3+1<=y2) a^=DP[x3+1][y3+1][x2][y2];
                            //cout << "a : " << a << "\n";
                            temp.push_back(a);
                        }
                    }
                    zip(temp);
                    DP[x1][y1][x2][y2]=-1;
                    for(int i=0; i<temp.size(); i++){
                        if(temp[i]!=i){
                            DP[x1][y1][x2][y2]=i;
                            break;
                        }
                    }
                    if(DP[x1][y1][x2][y2]<0) DP[x1][y1][x2][y2]=temp.size();
                }
            }
        }
    }

    if(DP[0][0][H-1][W-1]) cout << "First";
    else cout << "Second";
    
    return 0;
}
