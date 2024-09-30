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
//#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = 5e5+5;
const int D = 20;
const int debug=0;

/*
*/

int DPB[20][305][305][20][3];
int DPA[20][305][305][20][3];
int N;
vector<int> V;

void sol(int DP[20][305][305][20][3], string& S){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<=S.length(); k++){
                DP[0][i][j][k][1]=1;
            }
        }
    }
    for(int i=1; i<=N; i++){//구간의 크기
        for(int j=0; j+i-1<N; j++){//구간 시작점
            if(debug) cout << "j : " << j << " " << j+i << " ";
            for(int k=1; k<=min((int)S.length(), i); k++){//길이
                if(debug) cout << "k : " << k << " ";
                for(int l=0; l+k-1<S.length(); l++){//문자열에서의 시작점
                    if(debug) cout << "l : " << l << " ";
                    for(int a=0; a<3; a++){//이전거에서 가져옴
                        DP[k][j][j+i][l][a]+=DP[k][j][j+i-1][l][a];
                        DP[k][j][j+i][l][a]%=mod;
                    }
                    //l~l+k-1을 볼거임
                    //앞에다가 추가하는 경우부터 생각
                    //추가하는 위치보다 현재 원소가 크면->모든 경우에서 더 커짐
                    //같으면->작은 애들에 대해서 작아지고 큰 애들에 대해서 커지고 같은 애들에 대해서 같아짐
                    //작으면->모든 경우에 대해서 작아짐
                    assert(i+j-1>=0&&i+j-1<N);
                    assert(l>=0&&l<S.length());
                    if(V[i+j-1]<S[l]-'0'){
                        DP[k][j][j+i][l][0]+=((DP[k-1][j][j+i-1][l+1][0]+DP[k-1][j][j+i-1][l+1][1])%mod+DP[k-1][j][j+i-1][l+1][2])%mod;
                        DP[k][j][j+i][l][0]%=mod;
                    }
                    else if(V[i+j-1]==S[l]-'0'){
                        DP[k][j][j+i][l][0]+=DP[k-1][j][j+i-1][l+1][0];
                        DP[k][j][j+i][l][0]%=mod;
                        DP[k][j][j+i][l][1]+=DP[k-1][j][j+i-1][l+1][1];
                        DP[k][j][j+i][l][1]%=mod;
                        DP[k][j][j+i][l][2]+=DP[k-1][j][j+i-1][l+1][2];
                        DP[k][j][j+i][l][2]%=mod;
                    }
                    else{
                        DP[k][j][j+i][l][2]+=((DP[k-1][j][j+i-1][l+1][0]+DP[k-1][j][j+i-1][l+1][1])%mod+DP[k-1][j][j+i-1][l+1][2])%mod;
                        DP[k][j][j+i][l][2]%=mod;
                    }
                    //뒤에다가 추가하는 경우를 생각
                    //큰 애들은 언제나 큰 경우로 가고 작은 애들은 언제나 작은 애들로 간다
                    //추가하는 위치보다 현재 원소가 작은지 같은지 큰지에 따라서 전이가 이루어짐
                    DP[k][j][j+i][l][2]+=DP[k-1][j][j+i-1][l][2];
                    DP[k][j][j+i][l][2]%=mod;
                    DP[k][j][j+i][l][0]+=DP[k-1][j][j+i-1][l][0];
                    DP[k][j][j+i][l][0]%=mod;
                    assert(l+k-1>=0&&l+k-1<S.length());
                    if(V[i+j-1]<S[l+k-1]-'0'){
                        DP[k][j][j+i][l][0]+=DP[k-1][j][j+i-1][l][1];
                        DP[k][j][j+i][l][0]%=mod;
                    }
                    else if(V[i+j-1]==S[l+k-1]-'0'){
                        DP[k][j][j+i][l][1]+=DP[k-1][j][j+i-1][l][1];
                        DP[k][j][j+i][l][1]%=mod;
                    }
                    else{
                        DP[k][j][j+i][l][2]+=DP[k-1][j][j+i-1][l][1];
                        DP[k][j][j+i][l][2]%=mod;
                    }
                    if(debug) cout << "DP : " << DP[k][j][j+i][l][0] << " " << DP[k][j][j+i][l][1] << " " << DP[k][j][j+i][l][2] << "\n";
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> N;
    cin >> A >> B;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    sol(DPA, A);
    sol(DPB, B);

    int Q;
    cin >> Q;
    while(Q--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int a=0;
        for(int i=0; i<min((int)B.length(), r-l+2); i++){
            a+=((DPB[i][l][r+1][B.length()-i][0]+DPB[i][l][r+1][B.length()-i][1])%mod+DPB[i][l][r+1][B.length()-i][2])%mod;
            a%=mod;
        }
        int b=0;
        for(int i=0; i<min((int)A.length(), r-l+2); i++){
            b+=((DPA[i][l][r+1][A.length()-i][0]+DPA[i][l][r+1][A.length()-i][1])%mod+DPA[i][l][r+1][A.length()-i][2])%mod;
            b%=mod;
        }
        if(min((int)B.length(), r-l+2)==B.length()){
            a+=(DPB[B.length()][l][r+1][0][0]+DPB[B.length()][l][r+1][0][1])%mod;
            a%=mod;
        }
        if(min((int)A.length(), r-l+2)==A.length()){
            b+=DPA[A.length()][l][r+1][0][0];
            b%=mod;
        }
        if(debug) cout << a << " " << b << "\n";
        a-=b;
        a+=mod;
        a%=mod;
        cout << a << "\n";
    }
    
    return 0;
}