#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int tomato[1005][1005]={};
int main(void)
{
    queue <pair<int, int> > Q;
    int N, M;
    int dx[4]= {1, -1, 0, 0};
    int dy[4]= {0, 0, 1, -1};
    int bak=0;
    int month=0;
    scanf("%d %d", &N, &M);
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
            scanf("%d", &tomato[i][j]);
    }
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(tomato[i][j]==1)
            {
                Q.push(make_pair(i, j));
                bak++;
            }
            else if(tomato[i][j]==-1)
            {
                bak++;
            }
        }
    }
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++)
        {
            if(x+dx[i]>M||x+dx[i]<1||y+dy[i]>N||y+dy[i]<1)
                continue;
            else if(tomato[x+dx[i]][y+dy[i]]==0)
            {
                tomato[x+dx[i]][y+dy[i]]=tomato[x][y]+1;
                Q.push(make_pair(x+dx[i], y+dy[i]));
                bak++;
                month=tomato[x][y];
            }

        }
    }
    if(bak==N*M)
        printf("%d", month);
    else
        printf("%d", -1);


    return 0;
}
