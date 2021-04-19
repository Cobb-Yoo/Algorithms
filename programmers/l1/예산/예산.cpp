#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int sum = 0;
    int len = d.size();
    int answer=0;
    sort(d.begin(),d.end());
    
    for(int i=0;i<len;i++){
        sum += d[i];
        if(sum > budget) break;
        answer++;
    }
    return answer;
}
