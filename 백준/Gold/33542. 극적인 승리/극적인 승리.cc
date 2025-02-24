#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, B;
    cin >> A >> B;
    int N;
    cin >> N;
    
    vector<pii> L;
    vector<pii> R;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        L.push_back({a, i});
        R.push_back({b, i});
    }
    sort(all(R));
    if(B>A){
        cout << 1 << " " << 1;
    }
    else{
        int ans=1e18;
        int ansl, ansr;
        for(int i=0; i<N; i++){
            if(B+L[i].first>A&&ans>B+L[i].first){
                ans=B+L[i].first;
                ansl=L[i].second+1;
                ansr=-1;
            }
        }
        for(int i=0; i<N; i++){
            if(B+R[i].first>A&&ans>B+R[i].first){
                ans=B+R[i].first;
                ansl=-1;
                ansr=R[i].second+1;
            }
        }
        for(int i=0; i<N; i++){
            int curscore=B+L[i].first;
            int left=0;
            int right=N-1;
            int index=N;
            while(left<=right){
                int mid=(left+right)>>1;
                if(R[mid].first+curscore>A){
                    index=min(mid, index);
                    right=mid-1;
                }
                else left=mid+1;
            }
            if(index==N) continue;
            if(R[index].second==L[i].second) index++;
            if(index==N) continue;
            pii temp=R[index];
            if(temp.first+curscore<ans){
                ans=temp.first+curscore;
                ansl=i+1;
                ansr=temp.second+1;
            }
        }
        if(ans==1e18) cout << "No";
        else cout << ansl << " " << ansr;
    }
}