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
const ll mod = 1e9+7;
const int MAX = 1e7;

vector<int> failure(string& s){
    vector<int> f(s.length());
    int j=0;
    for(int i=1; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}

ll DP[3*MAX+10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, K1, K2;
    cin >> N >> K1 >> K2;
    string P1="";
    string P2="";
    if(K1>0) cin >> P1;
    if(K2>0) cin >> P2;
    vector<int> f1=failure(P1);
    vector<int> f2=failure(P2);

    if(K1>N) cout << 0;
    else if(K2==0) cout << 0;
    else if(K2>N){
        if(K1==0){
            ll ans=1;
            for(int i=0; i<N; i++){
                ans*=2;
                ans%=mod;
            }
            cout << ans;
            return 0;
        }
        DP[0]=1;
        for(int i=0; i<N; i++){
            for(int j=0; j<K1; j++){
                for(int k=0; k<2; k++){
                    if(DP[i*K1*2+j*2+k]==0) continue;

                    int tempj=j;
                    while(tempj>0&&P1[tempj]!='0') tempj=f1[tempj-1];
                    if(P1[tempj]=='0') tempj++;
                    if(tempj==K1){
                        tempj=f1[tempj-1];
                        DP[(i+1)*K1*2+tempj*2+1]+=DP[i*K1*2+j*2+k];
                        DP[(i+1)*K1*2+tempj*2+1]%=mod;
                    }
                    else{
                        DP[(i+1)*K1*2+tempj*2+k]+=DP[i*K1*2+j*2+k];
                        DP[(i+1)*K1*2+tempj*2+k]%=mod;
                    }

                    tempj=j;
                    while(tempj>0&&P1[tempj]!='1') tempj=f1[tempj-1];
                    if(P1[tempj]=='1') tempj++;
                    if(tempj==K1){
                        tempj=f1[tempj-1];
                        DP[(i+1)*K1*2+tempj*2+1]+=DP[i*K1*2+j*2+k];
                        DP[(i+1)*K1*2+tempj*2+1]%=mod;
                    }
                    else{
                        DP[(i+1)*K1*2+tempj*2+k]+=DP[i*K1*2+j*2+k];
                        DP[(i+1)*K1*2+tempj*2+k]%=mod;
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0; i<=K1; i++){
            ans+=DP[N*K1*2+i*2+1];
            ans%=mod;
        }
        cout << ans;
    }
    else if(K1==0){
        DP[0]=1;
        for(int i=0; i<N; i++){
            for(int j=0; j<K2; j++){
                for(int k=0; k<2; k++){
                    if(DP[i*K2*2+j*2+k]==0) continue;

                    int tempj=j;
                    while(tempj>0&&P2[tempj]!='0') tempj=f2[tempj-1];
                    if(P2[tempj]=='0') tempj++;
                    if(tempj!=K2){
                        DP[(i+1)*K2*2+tempj*2+k]+=DP[i*K2*2+j*2+k];
                        DP[(i+1)*K2*2+tempj*2+k]%=mod;
                    }

                    tempj=j;
                    while(tempj>0&&P2[tempj]!='1') tempj=f2[tempj-1];
                    if(P2[tempj]=='1') tempj++;
                    if(tempj!=K2){
                        DP[(i+1)*K2*2+tempj*2+k]+=DP[i*K2*2+j*2+k];
                        DP[(i+1)*K2*2+tempj*2+k]%=mod;
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0; i<=K2; i++){
            ans+=DP[N*K2*2+i*2+0];
            ans%=mod;
        }
        cout << ans;
    }
    else{
        DP[0]=1;
        for(int i=0; i<N; i++){
            for(int j=0; j<K1; j++){
                for(int k=0; k<K2; k++){
                    for(int a=0; a<2; a++){
                        if(DP[i*K1*K2*2+j*K2*2+k*2+a]==0) continue;
                        //cout << i << " " << j << " " << k << " " << a << " " << DP[i*K1*K2*2+j*K2*2+k*2+a] << "\n";
                        //cout << DP[i*j*k+a*MAX] << "\n";
                        //cout << i << " " << j << " " << k << " " << a << "\n";
                        int tempa=j;
                        int tempb=k;
                        while(tempa>0&&P1[tempa]!='0') tempa=f1[tempa-1];
                        if(P1[tempa]=='0') tempa++;
                        while(tempb>0&&P2[tempb]!='0') tempb=f2[tempb-1];
                        if(P2[tempb]=='0') tempb++;
                        //cout << tempa << " " << tempb << "\n";
                        if(tempb!=K2){
                            if(tempa==K1){
                                tempa=f1[tempa-1];
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+1]+=DP[i*K1*K2*2+j*K2*2+k*2+a];
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+1]%=mod;
                            }
                            else{
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+a]+=DP[i*K1*K2*2+j*K2*2+k*2+a];
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+a]%=mod;
                            }
                        }
                        tempa=j;
                        tempb=k;
                        while(tempa>0&&P1[tempa]!='1') tempa=f1[tempa-1];
                        if(P1[tempa]=='1') tempa++;
                        while(tempb>0&&P2[tempb]!='1') tempb=f2[tempb-1];
                        if(P2[tempb]=='1') tempb++;
                        //cout << tempa << " " << tempb << "\n";
                        if(tempb!=K2){
                            if(tempa==K1){
                                tempa=f1[tempa-1];
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+1]+=DP[i*K1*K2*2+j*K2*2+k*2+a];
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+1]%=mod;
                            }
                            else{
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+a]+=DP[i*K1*K2*2+j*K2*2+k*2+a];
                                DP[(i+1)*K1*K2*2+tempa*K2*2+tempb*2+a]%=mod;
                            }
                        }
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0; i<=K1; i++){
            for(int j=0; j<K2; j++){
                //cout << DP[N*i*j+1*MAX] << "\n";
                ans+=DP[N*K1*K2*2+i*K2*2+j*2+1];
                ans%=mod;
            }
        }
        cout << ans;
    }

    return 0;
}
