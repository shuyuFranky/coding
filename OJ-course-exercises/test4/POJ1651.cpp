/**
 * Multiplication Puzzle
 * 区间dp
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[105][105];
int arr[105];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<N;i++)
        for(int j=i+2;j<N;j++){
           dp[i][j]=1<<25;
        }
    memset(dp,0,sizeof(dp));
    for(int i=0;i+2<N;i++)
        dp[i][i+2]=arr[i]*arr[i+1]*arr[i+2];
    for(int l=2;l<N;l++){
        for(int i=0;i<N;i++){
            int j=i+l;
            if(j>=N) break;
            for(int t=i+1;t<j;t++){
                int x=dp[i][t]+dp[t][j]+arr[t]*arr[i]*arr[j];
                if(dp[i][j]==0)
                    dp[i][j]=x;
                else
                    dp[i][j]=min(dp[i][j],x);
            }
        }
    }
    cout<<dp[0][N-1]<<endl;
    return 0;
}