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
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
각 단어마다 짝을 지어준 다음에
DP[i][j]=인덱스 i, 인덱스 j인 경우의 최소 비용
*/

int DP[1005][1005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    cin.ignore();
    while(TC--){
        string lineA, lineB;
        getline(cin, lineA);
        getline(cin, lineB);
        //cout << lineA << "\n";
        //cout << lineB << "\n";
        vector<string> wordA, wordB;
        string temp="";
        for(auto c : lineA){
            if(c==' '){
                wordA.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        wordA.push_back(temp);
        temp="";
        for(auto c : lineB){
            if(c==' '){
                wordB.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        wordB.push_back(temp);
        //for(auto i : wordA) cout << i << " ";
        //cout << "\n";
        if(wordA.size()<wordB.size()) swap(wordA, wordB);
        int cost[10][10]={};
        for(int i=0; i<wordA.size(); i++){
            for(int j=0; j<wordB.size(); j++){
                string a=wordA[i];
                string b=wordB[j];
                for(int k=0; k<=a.length(); k++){
                    for(int l=0; l<=b.length(); l++){
                        DP[k][l]=1e18;
                    }
                }
                DP[0][0]=0;
                for(int k=0; k<=a.length(); k++){
                    for(int l=0; l<=b.length(); l++){
                        if(k<a.length())DP[k+1][l]=min(DP[k+1][l], DP[k][l]+1);
                        if(l<b.length())DP[k][l+1]=min(DP[k][l+1], DP[k][l]+1);
                        if(k<a.length()&&l<b.length()){
                            if(a[k]==b[l]) DP[k+1][l+1]=min(DP[k+1][l+1], DP[k][l]);
                            else DP[k+1][l+1]=min(DP[k+1][l+1], DP[k][l]+1);
                        }
                    }
                }
                cost[i][j]=DP[a.length()][b.length()];
            }
        }
        int ans=1e18;
        vector<int> perm;
        for(int i=0; i<wordA.size(); i++){
            perm.push_back(i);
        }
        do{
            int temp=0;
            for(int j=0; j<wordB.size(); j++){
                temp+=cost[perm[j]][j];
            }
            ans=min(ans, temp);
        }while(next_permutation(perm.begin(), perm.end()));
        cout << ans << "\n";
    }
    return 0;
}
