#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
 
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> mp;
    map<string, int>::iterator it;
    map<int, string>::iterator rit;
    map<int, string> rev;
    pair<int, int> arr[10001];
    
    for(int i=0; i<genres.size(); i++){
        it = mp.find(genres[i]);
        
        if(it != mp.end()){ //map에 있으면 누적 추가해줌.
            int pre = it->second;
            mp[genres[i]] = pre+plays[i];
        }else{// map에 없으면 추가 
            mp.insert({genres[i], plays[i]}); //map은 key값의 오름차순으로 자동으로 정렬해줌 (우선순위) 
        }
    }

    for(it = mp.begin(); it != mp.end(); it++){//기존 mp의 value를 음수로 만들고 key, value를 서로 바꿈. 
        rev.insert({-(it->second), it->first});
    }
    
    for(rit = rev.begin(); rit != rev.end(); rit++){
        string gen = rit->second;// tmp값 
    
        memset(arr, 0, sizeof(arr));
        
        int idx = 0;
        for(int i=0; i<genres.size(); i++){
            if(gen.compare(genres[i]) == 0){
                arr[idx++] = {-plays[i], i}; // sort가 오름차순이기 때문에 first를 음수로 둠.피스트(납작해졌군). 
            }
        }
        
        sort(arr, arr+idx);
        
        if(idx==1){
            answer.push_back(arr[0].second);             
        }else{
            answer.push_back(arr[0].second);
            answer.push_back(arr[1].second);     
        }
        
    }
    
    return answer;
}
