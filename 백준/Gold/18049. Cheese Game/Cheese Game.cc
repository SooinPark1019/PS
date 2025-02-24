#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

int DP[100005][3];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        vector<int> V;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            V.push_back(a);
        }
        memset(DP, 0, sizeof(DP));
        for(int i=0; i<N; i++){
            for(int j=0; j<3; j++){
                //cout << "i : " << i << " j : " << j << " DP : " << DP[i][j] << "\n";
                if(j==0){
                    DP[i+1][1]=max(DP[i+1][1], DP[i][j]);
                }
                else if(j==1){
                    DP[i+1][0]=max(DP[i+1][0], DP[i][j]+V[i]);
                    if(i>0) DP[i+1][2]=max(DP[i+1][2], DP[i][j]+min(V[i], V[i-1]));
                }
                else{
                    DP[i+1][0]=max(DP[i+1][0], DP[i][j]+V[i]);
                    DP[i+1][1]=max(DP[i+1][1], DP[i][j]);
                }
            }
        }
        cout << max({DP[N][0], DP[N][1], DP[N][2]}) << "\n";
    }
}