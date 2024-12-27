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

vector<string> ans;
int N;
int finish=0;
bool string_check(string& str){
    //cout << "check_str : " << str << "\n";
    int flag=0;
    for(int i=1; i<=str.length()/2; i++){
        //cout << str.substr(str.length()-i, i) << " " << str.substr(str.length()-2*i, i) << "\n";
        if(str.substr(str.length()-i, i)==str.substr(str.length()-2*i, i)){
            return false;
        }
    }
    //cout << "flag : " << flag << "\n";
    return true;
}
void sol(string& cur_str){
    //cout << "cur_str : " << cur_str << "\n";
    if(!string_check(cur_str)||finish) return;
    if(cur_str.length()==N){
        ans.push_back(cur_str);
        finish=1;
        return;
    }   
    cur_str+='1';
    sol(cur_str);
    cur_str.pop_back();
    cur_str+='2';
    sol(cur_str);
    cur_str.pop_back();
    cur_str+='3';
    sol(cur_str);
    cur_str.pop_back();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    string S="";
    sol(S);
    sort(all(ans));
    cout << ans[0];
    return 0;
}
