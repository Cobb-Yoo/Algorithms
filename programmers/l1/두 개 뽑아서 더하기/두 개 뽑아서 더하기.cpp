#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int len = numbers.size();
    
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            if(i == j) continue;
            answer.push_back(numbers[i]+numbers[j]);
        }
    }
    
    sort(answer.begin(), answer.end());   
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
 
    return answer;
}
