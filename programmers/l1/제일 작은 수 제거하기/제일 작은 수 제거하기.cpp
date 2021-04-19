#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int len = arr.size();    
    
    if(len == 1) {
        answer.push_back(-1);
        return answer;
    }
    
    int min = 987654321;
    int pos = 0;
    
    
    for(int i=0;i<len;i++){
        answer.push_back(arr[i]);
        if(min > arr[i]){
            min = arr[i];
            pos = i;
        }
    }
    
    answer.erase(answer.begin()+pos);
    
    return answer;
}
