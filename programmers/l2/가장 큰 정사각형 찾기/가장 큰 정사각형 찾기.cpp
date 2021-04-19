#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board){
    int len1 = board.size();
    int len2 = board[0].size();
    int MAX=0;
    
    if(len1 < 2 || len2 < 2) {
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(board[i][j] == 1) return 1;
            }
        }
    }
    
    for(int i=1;i<len1;i++){
        for(int j=1;j<len2;j++){
            if(board[i][j] == 1) board[i][j] = min({board[i-1][j-1],board[i-1][j],board[i][j-1]})+1;
            
            if(board[i][j] > MAX) MAX = board[i][j];
        }
    }

    return MAX * MAX;
}
