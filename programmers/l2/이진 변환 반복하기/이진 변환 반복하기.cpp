#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int removed, genernation;
int len;

void rmZero(string s){
    len = 0;
    int tmp = s.size();
    for(int i=0;i<tmp;i++){
        if(s[i] == '1') len++;
    }
    
    removed += tmp - len;
}

string get_str(){
    string result = "";
    
    while(len > 0){
        result += len%2 + '0';
        len /= 2;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

vector<int> solution(string s) {
    removed = genernation = 0;
    
    while(s.size() != 1){
        genernation++;
        rmZero(s);
        s = get_str();
    }
    vector<int> answer;
    
    answer.push_back(genernation);
    answer.push_back(removed);
    
    return answer;
}
