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
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
K번째 자리부터 보자
5보다 작은수가 처음으로 나오는 부분이 존재한다면 해당 위치부터 5로 바꾸기 시작
건너뛴 애들만큼 0붙이고 쭉 5

5보다 작은 수가 나오지 않는다면
맨 앞자리를 +1 뒤를 모두 0 다음 5

digitDP[tight][자릿수][5의 개수]//0이면 tight, 1이면 X
*/
int DP[2][20][20];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    int K;
    cin >> S >> K;
    
    int N=S.length();

    for(int i=0; i<2; i++){
        for(int j=0; j<20; j++){
            for(int k=0; k<20; k++){
                DP[i][j][k]=1e18;
            }
        }
    }

    DP[0][0][0]=0;

    for(int i=0; i<2; i++){
        for(int j=0; j<S.length(); j++){
            for(int k=0; k<20; k++){
                if(DP[i][j][k]==1e18) continue;
                //cout << "i : " << i << " j : " << j << " k : " << k << " DP : " << DP[i][j][k] << "\n"; 
                if(i==0){
                    if(S[j]-'0'==5){
                        DP[0][j+1][k+1]=min(DP[0][j+1][k+1], DP[i][j][k]*10+5);//tight
                        DP[1][j+1][k]=min(DP[1][j+1][k], DP[i][j][k]*10+6);
                    }
                    else{
                        DP[0][j+1][k]=min(DP[0][j+1][k], DP[i][j][k]*10+S[j]-'0');//tight
                        //cout << S[j]-'0' << "\n";
                        if(S[j]-'0'<5){
                            DP[1][j+1][k+1]=min(DP[1][j+1][k+1], DP[i][j][k]*10+5);
                        }
                        if(S[j]-'0'<9){
                            DP[1][j+1][k]=min(DP[1][j+1][k], DP[i][j][k]*10+S[j]-'0'+1);
                        }
                    }
                }
                else{
                    DP[1][j+1][k+1]=min(DP[1][j+1][k+1], DP[i][j][k]*10+5);
                    DP[1][j+1][k]=min(DP[1][j+1][k], DP[i][j][k]*10);
                }
            }
        }
    }

    string temp="";
    if(N>=K){
        for(int i=0; i<N; i++){
            if(i<K) temp+='5';
            else temp+='0';
        }
        temp+='1';
    }
    else{
        for(int i=0; i<K; i++){
            temp+='5';
        }
    }
    reverse(all(temp));
    int ans=stoll(temp);
    int a=stoll(S);
    for(int i=0; i<2; i++){
        for(int j=0; j<17; j++){
            for(int k=K; k<17; k++){
                if(DP[i][j][k]>a) ans=min(ans, DP[i][j][k]);
            }
        }
    }

    cout << ans;

    return 0;
}
