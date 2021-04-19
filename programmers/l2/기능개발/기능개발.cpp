#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len = progresses.size();
    int day;
	int max_day=0; 
    
    for(int i=0;i<len;i++){
        day = (99 - progresses[i])/speeds[i] + 1;
        
        if(answer.empty() || max_day < day) answer.push_back(1);
        else answer.back()++;
        
        if(max_day < day) max_day = day;
    }
    
    return answer;
}
