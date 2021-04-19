#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int len = people.size();
    
    sort(people.begin(),people.end());
    int i=0;
    int j=len-1;
    for(;i<=j;j--){
        if(people[i] + people[j] <= limit){
            answer++;
            i++;
        }else{
            answer++;
        }
    }
    return answer;
}
