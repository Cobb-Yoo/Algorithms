#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a,string b){
    return a > b;
}

string solution(vector<string> participant, vector<string> completion) {
    int len1 = participant.size();
    int len2 = completion.size();
    
    sort(participant.begin(),participant.end(),cmp);
    sort(completion.begin(),completion.end(),cmp);
    
    
        for(int i=0;i<len2;i++){
            if(participant[i] != completion[i]){
                return participant[i];
            }
        }
    
    
    
    return completion.back();
}
