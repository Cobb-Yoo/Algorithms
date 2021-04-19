#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a,int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),cmp);
    int len = citations.size();

    for(int i=0;i<len;i++){
        if(citations[i] >= i+1) answer = i+1;
    }

    return answer;
}
