//boj 9248 Suffix Array
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;

int pos[500005]={};
int SA[500005]={};
string S;
int d;

bool cmp(int i, int j){
    if(pos[i]==pos[j]){
        i+=d;
        j+=d;
        if(i>=S.length()||j>=S.length()) return i>j;
        else return pos[i]<pos[j];
    }
    return pos[i]<pos[j];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin >> S;
    for(int i=0; i<S.length(); i++){
        SA[i]=i;
        pos[i]=S[i];
    }
    for(d=1; ; d*=2){
        sort(SA, SA+S.length(), cmp);
        int temp[500005]={};
        for(int i=0; i<S.length()-1; i++){
            temp[i+1]=temp[i]+cmp(SA[i], SA[i+1]);
        }
        for(int i=0; i<S.length(); i++){
            pos[SA[i]]=temp[i];
        }
        if(temp[S.length()-1]==S.length()-1) break;
    }
    int k=0;
    int lcp[600005]={};
    for(int i=0; i<S.length(); i++){
        k=max(k-1, 0);
        if(pos[i]==S.length()-1) continue;
        for(int j=SA[pos[i]+1]; S[i+k]==S[j+k]; k++);
        lcp[pos[i]]=k;
    }
    int ans=0;
    for(int i=0; i<S.length()-1; i++){
        ans=max(ans, lcp[i]);
    }
    cout << ans;
    return 0;
}
