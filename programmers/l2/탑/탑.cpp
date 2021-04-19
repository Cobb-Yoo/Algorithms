#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int size=heights.size();

    answer.push_back(0); 

    for(int i=0; i<size; i++){
        for(int j=i-1; j>=0; j--){
            if(heights[i]<heights[j]){
                answer.push_back(j+1);
                break;
            }
            else if(j==0){ 
                answer.push_back(0);
            }
        }
    }

    return answer;
}
