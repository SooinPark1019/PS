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
const int mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        int arr[55][55];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[N-1-i][N-1-j];
            }
        }
        vector<int> temp(6, -1);
        temp[0]=arr[0][0];
        map<vector<int>, int> DP[50][50];
        DP[0][0][temp]=1;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                //cout << "i : " << i << " j : " << j << "\n";
                //cout << "temp : ";
                for(auto& p : DP[i][j]){
                    vector<int> temp=p.first;
                    //for(auto k : temp) cout << k << " ";
                    //cout << "\n";
                    vector<int> down(6);
                    down[0]=temp[3];
                    down[3]=temp[5];
                    down[5]=temp[2];
                    down[2]=temp[0];
                    down[1]=temp[1];
                    down[4]=temp[4];
                    //for(auto k : down) cout << k << " ";
                    //cout << "\n";
                    if(i<N-1&&(down[0]==arr[i+1][j]||down[0]==-1)){
                        down[0]=arr[i+1][j];
                        DP[i+1][j][down]=1;
                    }
                    vector<int> right(6);
                    right[5]=temp[1];
                    right[4]=temp[5];
                    right[0]=temp[4];
                    right[1]=temp[0];
                    right[2]=temp[2];
                    right[3]=temp[3];
                    //for(auto k : right) cout << k << " ";
                    //cout << "\n";
                    if(j<N-1&&(right[0]==arr[i][j+1]||right[0]==-1)){
                        right[0]=arr[i][j+1];
                        DP[i][j+1][right]=1;
                    }
                }
            }
        }
        if(DP[N-1][N-1].size()==0) cout << "No\n";
        else{
            cout << "Yes\n";
            vector<int> A={0, 4, 3, 2, 1, 5};
            for(auto p : DP[N-1][N-1]){
                for(auto i : A){
                    cout << max(0ll, p.first[i]) << " ";
                }
                cout << "\n";
                break;
            }
        }
    }
    
    return 0;
}
