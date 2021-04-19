#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p=0;
    int y=0;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i] == 'p' || s[i] == 'P') p++;
        else if(s[i] == 'y' || s[i] == 'Y') y++;
    }
    
    if(p != y) answer = false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
