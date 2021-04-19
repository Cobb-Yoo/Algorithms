#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a,int b){
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> arr; //first = location, second = priorities
    int len = priorities.size();
    
    for(int i=0;i<len;i++) arr.push_back({i,priorities[i]});
    
    sort(priorities.begin(),priorities.end(),cmp);
    
    for(int i=0;i<len;i++){
        if(priorities[i] != arr[i].second){
            arr.push_back(arr[i]);
            arr.erase(arr.begin()+i);
            i--;
        }else if(arr[i].first == location){
            return i+1;
        }
    }
}
