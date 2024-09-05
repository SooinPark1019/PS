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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const ll MAX = 200000;

/*
먼저 O(Nlog(N))풀이를 생각해보자
이분탐색+KMP를하면 O(Nlog(N))안에 가능할듯. 다만 패턴의 길이 뒤에 필요한 자투리를 남겨야 한다는 점에 주의하자.

N이 10^7이라서 O(N)풀이를 웬만하면 짜야 할 것 같기는 한데, 한번 짜보도록 하자.
*/

vector<int> failure(string& s){
    vector<int> f(s.length());
    int j=0;
    for(int i=1; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}//실패함수 반환

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        string S;
        cin >> S;
        int leadingzero=0;
        int cur=0;
        while(cur<N&&S[cur]=='0'){
            leadingzero++;
            cur++;
        }
        if(leadingzero==N){
            cout << "0\n";
            continue;
        }
        string T=S.substr(leadingzero);
        cur=0;
        int leadingone=0;
        while(cur<T.length()&&T[cur]=='1'){
            leadingone++;
            cur++;
        }
        if(leadingone==T.length()){
            for(int i=0; i<leadingone-1; i++) cout << "1";
            if(leadingzero==0) cout << "0\n";
            else cout << "1\n";
            continue;
        }
        int nextzero=0;
        while(cur<T.length()&&T[cur]=='0'){
            nextzero++;
            cur++;
        }
        string A=T.substr(max(0, leadingone-nextzero), T.length()-leadingone);
        reverse(all(A));
        reverse(all(T));
        //cout << T << " " << A << "\n";
        vector<char> ans;
        for(int i=0; i<T.length(); i++){
            if(i<A.length()){
                if(A[i]==T[i]) ans.push_back('0');
                else ans.push_back('1');
            }
            else ans.push_back(T[i]);
        }
        for(int i=ans.size()-1; i>=0; i--) cout << ans[i];
        cout << "\n";
    }
}
