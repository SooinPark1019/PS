#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define pii pair<int, int>
#define all(V) V.begin(), V.end()
#define ll long long
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")

struct Hashing {
    int P, M;
    vector<ll> h, p;
    Hashing(int P, int M) : P(P), M(M){}
    void build(const string &s){
        int n = s.size();
        h = p = vector<long long>(n+1); p[0] = 1;
        for(int i=1; i<=n; i++) h[i] = (h[i-1] * P + s[i-1]) % M;
        for(int i=1; i<=n; i++) p[i] = p[i-1] * P % M;
    }
    ll get_hash(int s, int e) const {
        int res = (h[e] - h[s-1] * p[e-s+1]) % M;
        return (res + M) % M;
    }
};//build(문자열)로 빌드, get_hash(시작 위치, 끝 위치)로 해당 부분 문자열의 해시값을 계산

int mod1=1e9+33;
int mod2=1e9+97;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    int N=S.length();

    Hashing H1(47, mod1);
    //Hashing H2(67, mod2);

    H1.build(S);
    //H2.build(S);

    int left=1;
    int right=N;
    int ans=N;
    while(left<=right){
        int mid=(left+right)>>1;
        unordered_map<ll, int> M;
        int onecnt=0;
        for(int i=0; i+mid<=N; i++){
            ll a=H1.get_hash(i+1, i+mid);
            //ll b=H2.get_hash(i+1, i+mid);
            M[a]++;
            if(M[a]==1) onecnt++;
            else if(M[a]==2) onecnt--;
        }
        if(onecnt>=1){
            ans=min(ans, mid);
            right=mid-1;
        }
        else left=mid+1;
    }

    unordered_map<ll, int> M;
    for(int i=0; i+ans<=N; i++){
        ll a=H1.get_hash(i+1, i+ans);
        //ll b=H2.get_hash(i+1, i+ans);
        M[a]++;
    }

    for(int i=0; i+ans<=N; i++){
        ll a=H1.get_hash(i+1, i+ans);
        //ll b=H2.get_hash(i+1, i+ans);
        if(M[a]==1){
            cout << S.substr(i, ans);
            break;
        }
    }

    return 0;
}