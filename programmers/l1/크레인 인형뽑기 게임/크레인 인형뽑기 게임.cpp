#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len1 = board.size();
    int len2 = moves.size();

    stack<int> basket;
    
    for(int i=0;i<len2;i++){
        int check = moves[i]-1;
        for(int j=0;j<len1;j++){
            if(board[j][check] != 0){
                if(!basket.empty() && basket.top() == board[j][check]){
                    answer += 2;
                    basket.pop();
                }else{
                    basket.push(board[j][check]);
                }
                board[j][check] = 0;
                break;
            }
        }
    }

    return answer;
}
