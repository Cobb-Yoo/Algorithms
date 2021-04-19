#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s[i] == ' '){
            cnt = 0;
            answer += " ";
            continue;
        }
        
        if(cnt & 1) {// È¦¼ö
            if('Z' >= s[i]) answer += s[i]-'A' + 'a';
            else answer += s[i];
        }else{
            if('a' <= s[i]) answer += s[i]-'a' + 'A';
            else answer += s[i];
        }
        cnt++;
    }
    return answer;
}
