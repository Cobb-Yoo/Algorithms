#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    int len = s.size();
    vector<vector<int>> v;
    vector<int> tmp;

    int num = 0;
    bool flag;
    for(int i=1;i<len-1;i++){
        if(s[i] == '{' ) {
            flag = 1;
        }
        else if(s[i] == ',') {
            if(flag){
                tmp.push_back(num);
                num = 0;
            }
        }
        else if(s[i] == '}'){
            flag = 0;
            tmp.push_back(num);
            num = 0;
            v.push_back(tmp);
            tmp.clear();
        }
        else {
            num *= 10;
            num += s[i]-'0';
        }
    }

    sort(v.begin(), v.end(), cmp);

    flag = 1;
    len = v.size();
    for(int i=0;i<len;i++){
        if(i == 0) {
            answer.push_back(v[0][0]);
            continue;
        }

        for(int j=0;j<v[i].size();j++){
            if(find(answer.begin(), answer.end(), v[i][j]) == answer.end()) answer.push_back(v[i][j]);
        }
    }

    return answer;
}
