#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    int left = 0,right = 0;
    int len = p.size();
    bool flag = 1;
    string answer = "";

    for(int i=0;i<len;i++){
        p[i] == '(' ? left++ : right++;

        if(right > left) flag = 0;
        else if(right == left){
            if(!flag){
                answer += '(';
                answer += solution(p.substr(i+1,len-(i+1))); // i 다음부터 마지막까지
                answer += ')';
                for(int j=1;j<i;j++) answer += (p[j] == '(' ? ')': '(');
            }else{
                answer += p.substr(0,i+1);
                answer += solution(p.substr(i+1,len-(i+1)));
            }

            return answer;
        }
    }
}
