#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> M;
    int N;
    cin >> N;
    vector<int> V;
    int index=0;
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        if(M.find(S)==M.end()){
            M[S]=index;
            index++;
        }
        V.push_back(M[S]);
    }
    int ans=1e18;
    for(int i=0; i<N; i++){
        //cout << "i : " << i << "\n";
        int cnt[50]={};
        int colorcnt=0;
        for(int j=i; j>=0; j--){
            //cout << "j : " << j << "\n";
            cnt[V[j]]++;
            if(cnt[V[j]]==1){
                colorcnt++;
                //cout << colorcnt << "\n";
                int seccnt[50]={};
                int rightindex=i+1;
                for(int k=i+1; k<N; k++){
                    //cout << "k : " << k << "\n";
                    while(rightindex<k) rightindex++;
                    while(rightindex<N&&colorcnt<index){
                        seccnt[V[rightindex]]++;
                        if(cnt[V[rightindex]]+seccnt[V[rightindex]]==1) colorcnt++;
                        rightindex++;
                        //cout << "rightindex : " << rightindex << " colorcnt : " << colorcnt << "\n"; 
                    }
                    //cout << "colorcnt : " << colorcnt << " rightindex : " << rightindex << "\n";
                    if(colorcnt==index) ans=min(ans, i-j+1+rightindex-k);
                    seccnt[V[k]]--;
                    if(cnt[V[k]]+seccnt[V[k]]==0) colorcnt--;
                }
            }
        }
    }
    cout << ans;
}