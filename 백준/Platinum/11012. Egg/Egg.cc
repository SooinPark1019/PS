#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long MultiplierFenwick[100005];

struct query{
    int x, b, t, value;
};
struct folks{
    int x, y;
};

bool cmpfolks(folks A, folks B){
    return A.x<B.x;
}

bool cmpquery(query A, query B){
    return A.x<B.x;
}
void multiplierupdate(int index, int value){
    while(index<=100001){
        MultiplierFenwick[index]+=value;
        index+=index&(-index);
    }
    return;
}
long long multipliersum(int index){
    long long ret=0;
    while(index>0){
        ret+=MultiplierFenwick[index];
        index-=index&(-index);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        memset(MultiplierFenwick, 0, sizeof(MultiplierFenwick));
        int N, M;
        cin >> N >> M;
        vector<folks> folksvector;
        vector<int> xvector;
        long long ans=0;
        for(int i=0; i<N; i++){
            int x, y;
            cin >> x >> y;
            x++;
            y++;
            folksvector.push_back({x, y});
            xvector.push_back(x);
        }
        vector<query> queryvector;
        for(int i=0; i<M; i++){
            int l, r, b ,t;
            cin >> l >> r >> b >> t;
            l++;
            r++;
            b++;
            t++;
            queryvector.push_back({l, b, t, 1});
            queryvector.push_back({r+1, b, t, -1});
            xvector.push_back(l);
            xvector.push_back(r+1);
        }
        sort(xvector.begin(), xvector.end());
        sort(queryvector.begin(), queryvector.end(), cmpquery);
        sort(folksvector.begin(), folksvector.end(), cmpfolks);
        xvector.erase(unique(xvector.begin(), xvector.end()), xvector.end());
        int queryindex=0;
        int folksindex=0;
        for(int i=0; i<xvector.size(); i++){
            int curx=xvector[i];
            while(queryindex<queryvector.size()&&queryvector[queryindex].x<=curx){
                int b=queryvector[queryindex].b;
                int t=queryvector[queryindex].t;
                int value=queryvector[queryindex].value;
                queryindex++;
                multiplierupdate(b, value);
                multiplierupdate(t+1, -1*value);
            }
            while(folksindex<folksvector.size()&&folksvector[folksindex].x<=curx){
                int y=folksvector[folksindex].y;
                folksindex++;
                ans+=multipliersum(y);
            }
        }
        cout << ans << "\n";

    }


    return 0;
}
