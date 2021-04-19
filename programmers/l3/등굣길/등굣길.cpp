#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int arr[101][101];
    memset(arr,0,sizeof(arr));
    int len = puddles.size();
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1){
                arr[i][j]=1;
                continue;
            }
            
            bool flag = 1;
            
            if(flag){
                for(int k=0;k<len;k++)
                    if(i==puddles[k][1] && j==puddles[k][0])
                        flag = 0;    
            }
            
            if(!flag) arr[i][j]=0;
            else arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 1000000007;
        }
    }
    
    return arr[n][m];
}
