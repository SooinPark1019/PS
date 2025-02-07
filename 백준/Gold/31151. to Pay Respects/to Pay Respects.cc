#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define ll long long

using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X, R, P, K;
    cin >> N >> X >> R >> P >> K;
    priority_queue<int> PQ;
    string S;
    cin >> S;
    int ans=0;
    for(int i=0; i<N; i++){
        int curscore=(N-i)*P;
        ans+=X;
        if(S[i]=='1'){
            curscore+=R*(N-i);
            ans-=R*(N-i);
        }
        PQ.push(curscore);
    }
    for(int i=0; i<K; i++){
        ans+=PQ.top();
        PQ.pop();
    }
    cout << ans;
}   