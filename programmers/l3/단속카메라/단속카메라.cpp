#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){    
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(),routes.end(),cmp);
    
    int camera = -30001;
    
    for(auto route : routes){
        if(route[0] > camera){
            camera = route[1];
            answer++;
        }
    }
    
    return answer;
}
