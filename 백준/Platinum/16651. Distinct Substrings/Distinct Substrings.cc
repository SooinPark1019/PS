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
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
어차피 서로 다른 문자열들의 시작점은 반드시 모두 첫 문자열에서 있어야 한다
일단 시작문자에서 출발하는 문자열은 전체 문자열의 길이만큼 있을 것이고
z function이다
조금 더 정확히는 z function을 전체 문자열에 대해서 구하고
첫번째 문자를 뺀 문자열에 대해서 구하고
두번째 문자를 뺀 문자열에 대해서 구하고
.
.
.
각 값에 대해 만약 최댓값이 문자열의 끝까지 닿는다면 해당 문자에서는 어떤 것도 시작할 수 없고, 그렇지 않다면 해당 문자에서 전체 문자열의 끝까지
에다가 그 Z값을 빼야한다
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin >> S;
    int N=S.length();
    //cout << S.length() << "\n";
    int K;
    cin >> K;
    /*string T="";
    set<string> strings;
    for(int i=0; i<K; i++){
        T+=S[i%S.length()];
    }
    for(int i=0; i<T.length(); i++){
        for(int j=i; j<T.length(); j++){
            strings.insert(T.substr(i, j-i+1));
        }
    }
    cout << strings.size() << "\n";*/
    for(int i=0; i<min((int)N, K-N); i++){
        S+=S[i];
    }
    //cout << S << "\n";
    vector<int> Z(S.length());
    for(int i=0; i<N; i++){
        string temp=S.substr(i);
        vector<int> A;
        A.push_back(temp.length());
        int L=0, R=0;
        for(int j=1; j<temp.length(); j++){
            if(j>R){
                L=j;
                R=j;
                while(R<temp.length()&&temp[R]==temp[R-L]) R++;
                A.push_back(R-L);
                R--;
            }
            else{
                if(A[j-L]<=R-j){
                    A.push_back(A[j-L]);
                }
                else{
                    L=j;
                    while(R<temp.length()&&temp[R]==temp[R-L]) R++;
                    A.push_back(R-L);
                    R--;
                }
            }
            /*if(i==10){
                cout << A[j] << " ";
            }*/
            Z[j+i]=max(Z[j+i], A[j]);
        }
    }
    int ans=0;
    for(int i=0; i<N; i++){
        //cout << S[i] << " " << Z[i] << "\n";
        if(Z[i]+i>=S.length()) continue;
        //cout << K-i-Z[i] << "\n";
        ans+=max(0ll, K-i-Z[i]);
    }
    cout << ans;
}