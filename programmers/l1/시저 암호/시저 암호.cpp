#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    int len = s.length();

    string answer = "";

    for(int i=0;i<len;i++){
        if(s[i] == ' ') answer += ' ';
        else {
            int num;
            s[i] >= 'a' ? num = 'a' : num = 'A';
            answer += char((((int)s[i]-num + n)%26)+num);
        }
    }

    return answer;
}
