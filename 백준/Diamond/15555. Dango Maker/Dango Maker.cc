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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);
const int FLAG_DEBUG = 0;

/*
먼저 해당 위치에서 가로 또는 세로가 시작하는지를 나타내는 배열을 하나 만든다
가로가 시작되면 1, 세로가 시작되면 2, 아무것도 아니면 0

각 묶음에 대해서 번호를 1씩 증가시키면서 정점에 할당
*/

int arr[3005][3005];
bool check(int x, int y, int dx, int dy){
    for(int i=0; i<3; i++){
        if(arr[x+i*dx][y+i*dy]!=i) return false;
    }
    return true;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<char, int> dict;
    dict['R']=0;
    dict['G']=1;
    dict['W']=2;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin >> c;
            arr[i][j]=dict[c];
        }
    }
    int ans=0;
    for(int i=0; i<=N-1+M-1; i++){
        int temp=0;
        int DP[3005][5][2]={};
        for(int x=0; x<N; x++){
            int y=i-x;
            if(y<0||y>=M) continue;
            //cout << "x : " << x << " y : " << y << "\n";
            if(x+2<N&&check(x, y, 1, 0)){
                //cout << "dirx\n";
                DP[x+1][1][0]=max({DP[x+1][1][0], DP[x][0][1]+1, DP[x][1][1]+1, DP[x][2][1]+1, DP[x][0][0]+1, DP[x][1][0]+1, DP[x][2][0]+1});
            }
            if(y+2<M&&check(x, y, 0, 1)){
                //cout << "diry\n";
                DP[x+1][1][1]=max({DP[x+1][1][1], DP[x][0][0]+1, DP[x][0][1]+1, DP[x][1][1]+1, DP[x][2][1]+1});
            }
            for(int k=0; k<3; k++){
                if(k==0){
                    DP[x+1][0][1]=max(DP[x+1][0][1], DP[x][0][1]);
                    DP[x+1][0][0]=max(DP[x+1][0][0], DP[x][0][0]);
                }
                else{
                    DP[x+1][(k+1)%3][0]=max(DP[x+1][(k+1)%3][0], DP[x][k][0]);
                    DP[x+1][(k+1)%3][1]=max(DP[x+1][(k+1)%3][1], DP[x][k][1]);
                }
            }
            for(int a=0; a<3; a++){
                for(int b=0; b<2; b++){
                    //cout << "a : " << a << " b : " << b << " DP : " << DP[x+1][a][b] << "\n";
                    temp=max(temp, DP[x+1][a][b]);
                }
            }
        }
        //cout << i << " " << temp << "\n";
        ans+=temp;
    }
    
    cout << ans;

    return 0;
}