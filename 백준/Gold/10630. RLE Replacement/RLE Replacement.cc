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
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

void input(vector<pair<char, int>>& V){
    while(1){
        char c;
        cin >> c;
        if(c=='$') return;
        int a;
        cin >> a;
        V.push_back({c, a});
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<char, int>> A;
    vector<pair<char, int>> B;
    vector<pair<char, int>> C;

    input(A);
    input(B);
    input(C);

    //for(auto p : A) cout << p.first << " " << p.second << " ";
    //cout << "\n";
    //for(auto p : B) cout << p.first << " " << p.second << " ";
    //cout << "\n";
    //for(auto p : C) cout << p.first << " " << p.second << " ";
    //cout << "\n";

    int index=-1;

    for(int i=0; i<A.size(); i++){
        int flag=0;
        for(int j=0; j<B.size(); j++){
            if(i+j>=A.size()) break;
            if(A[i+j].first!=B[j].first){
                break;
            }
            if(j==0||j==B.size()-1){
                if(A[i+j].second<B[j].second){
                    break;
                }
            }
            else{
                if(A[i+j].second!=B[j].second){
                    break;
                }
            }
            if(j==B.size()-1) flag=1;
        }
        if(flag==1){
            index=i;
            break;
        }
    }

    //cout << "index : " << index << "\n";

    vector<pair<char, int>> ans;

    for(int i=0; i<A.size(); i++){
        if(i==index){
            if(B.size()==1){
                for(int j=0; j<C.size(); j++) ans.push_back({C[j].first, C[j].second});
                if(A[i].second>B[0].second) ans.push_back({A[i].first, A[i].second-B[0].second});
            }
            else{
                if(A[i].second>B[0].second) ans.push_back({A[i].first, A[i].second-B[0].second});
                for(int j=0; j<C.size(); j++) ans.push_back({C[j].first, C[j].second});
                if(A[i+B.size()-1].second>B[B.size()-1].second) ans.push_back({A[i+B.size()-1].first, A[i+B.size()-1].second-B[B.size()-1].second});
            }
            i+=B.size()-1;
        }
        else ans.push_back({A[i].first, A[i].second});
    }
    for(int i=0; i<ans.size()-1; i++){
        if(ans[i+1].first==ans[i].first){
            ans[i+1].second+=ans[i].second;
            ans[i].second=0;
        }
    }
    for(int i=0; i<ans.size(); i++){
        if(ans[i].second==0) continue;
        cout << ans[i].first << " " << ans[i].second << " ";
    }
    cout << "$";
    
    return 0;
}
