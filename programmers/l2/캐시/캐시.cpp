#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int len = cities.size();
    bool flag = 0;
    if(cacheSize == 0) return len*5;
    vector<string> cache;
    
    for(int i=0;i<len;i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        int len2 = cache.size();
        flag = 0;
        
        for(int j=0;j<len2;j++){
            if(cities[i] == cache[j]){
                answer++;
                cache.erase(cache.begin()+j);
                cache.push_back(cities[i]);
                flag = 1;
                break;
            }
        }
        if(!flag){
            answer+=5;
            if(len2 == cacheSize) cache.erase(cache.begin());
            cache.push_back(cities[i]);
        }
    }
    
    return answer;
}
