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
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> graycode;
    graycode.push_back(0);
    for(int i=1; i<(1<<11); i++){
        graycode.push_back(i^(i>>1));
    }

    //for(auto i : graycode) cout << i << " ";
    //cout << "\n";

    int N;
    cin >> N;
    int K;
    cin >> K;
    int flag=0;
    int querycnt=0;
    for(int i=1; i<=N; i++){
        cout << i << " " << i << endl;
        int a;
        cin >> a;
        if(a==N){
            flag=1;
            break;
        }
        if(a<K){
            querycnt++;
            assert(querycnt<=2500);
            cout << i << " " << i << endl;
            int a;
            cin >> a;
            if(a==N){
                flag=1;
                break;
            }
        }
        else{
            querycnt++;
            assert(querycnt<=2500);
            cout << i << " " << i << endl;
            int b;
            cin >> b;
            for(int j=0; j<(1<<(N-i+1))-1; j++){
                //cout << graycode[j] << " " <<graycode[j+1] << " " << (graycode[j]^graycode[j+1]) << endl;
                int a=31-__builtin_clz((graycode[j]^graycode[j+1]));
                //cout << "a : " << a << "\n";
                querycnt++;
                assert(querycnt<=2500);
                cout << i << " " << i+a << endl;
                cin >> a;
                if(a==N){
                    flag=1;
                    break;
                }
                else if(a>K){
                    querycnt++;
                    assert(querycnt<=2500);
                    cout << i << " " << i << endl;
                    int b;
                    cin >> b;
                    if(b==N){
                        flag=1;
                        break;
                    }
                    else if(b>a){
                        K=b;
                        break;
                    }
                    querycnt++;
                    assert(querycnt<=2500);
                    cout << i << " " << i << endl;
                    int c;
                    cin >> c;
                    if(b<a){
                        K=a;
                        break;
                    }
                }
            }
            if(flag==1) break;
        }
    }
    assert(flag==1);

    return 0;
}
