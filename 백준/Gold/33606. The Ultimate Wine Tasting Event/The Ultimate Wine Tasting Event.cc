#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long

using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        string S;
        cin >> S;
        int cnt=0;
        for(int i=0; i<N; i++){
            if(S[i]=='W') cnt++;
        }
        int acnt=0;
        int bcnt=0;
        for(int i=0; i<N; i++){
            if(S[i]=='R') break;
            acnt++;
        }
        for(int j=2*N-1; j>=N; j--){
            if(S[j]=='W') break;
            bcnt++;
        }
        //cout << cnt << " " << acnt << " " << bcnt << "\n";
        if(cnt%2||cnt/2>acnt||cnt/2>bcnt) cout << "NO\n";
        else cout << "YES\n";
    }
}