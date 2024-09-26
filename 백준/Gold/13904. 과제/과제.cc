#include <bits/stdc++.h>

using namespace std;

struct number{
    int day, value;
};
struct comp{
    bool operator()(number A, number B){
        if(A.value==B.value)
            return A.day>B.day;
        return A.value<B.value;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<number, vector<number>, comp> PQ;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        PQ.push({a, b});
    }
    int cur=1;
    vector<int> V(1005, 0);
    while(!PQ.empty()){
        int day=PQ.top().day;
        int value=PQ.top().value;
        PQ.pop();
        for(int i=day; i>=1; i--){
            if(V[i]==0){
                V[i]=value;
                break;
            }
        }
    }
    int ans=0;
    for(int i=0; i<1002; i++){
        ans+=V[i];
    }
    cout << ans;
    return 0;
}
