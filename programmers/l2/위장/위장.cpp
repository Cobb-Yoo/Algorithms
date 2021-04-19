#include <string>
#include <vector>
#include <map>

using namespace std;
int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for(vector<string> i : clothes) m[i[1]]++;        
    
    map<string, int>::iterator iter;
    
    int answer = 1;
    for(iter=m.begin();iter!=m.end();iter++){
        answer *= (iter->second + 1);
    }
    return (answer-1);
}
