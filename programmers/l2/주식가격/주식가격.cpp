#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size(); 
    
    for(int i=0;i<len-1;i++){
        answer.push_back(0);
        for(int j=i+1;j<len;j++){
            if(prices[i] <= prices[j]) answer[i]++;
            else {
                answer[i]++;
                break;
            }
        }
    }
    answer.push_back(0);
    return answer;
}
