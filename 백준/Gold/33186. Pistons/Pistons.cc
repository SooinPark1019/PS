#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

int imos[2000005];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int cursz=0;
    int curplus=0;
    int ans=0;

    for(int i=0; i<N; i++){
        int a;
        char c;
        cin >> a >> c;
        cursz+=a;
        if(a==0){
            curplus++;
            imos[M]-=2;
            imos[2*M]+=2;
        }
        else if(a==M){
            curplus--;
            imos[M]+=2;
            imos[2*M]-=2;
        }
        else{
            if(c=='U'){
                curplus++;
                imos[M-a]-=2;
                imos[2*M-a]+=2;
            }
            else{
                curplus--;
                imos[a]+=2;
                imos[M+a]-=2;
            }
        }
    }
    ans=max(ans, cursz);
    for(int i=1; i<=2*M; i++){
        //cout << curplus << "\n";
        cursz+=curplus;
        curplus+=imos[i];
        ans=max(ans, cursz);
    }
    cursz+=curplus;
    ans=max(ans, cursz);
    cout << ans;
}