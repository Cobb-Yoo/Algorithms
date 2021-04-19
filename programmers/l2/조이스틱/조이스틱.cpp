#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    string str="";

    int len = name.size();

    for(int i=0;i<len;i++) str+="A";

    int start = 0;
    int left,right;

    while(1){
        left = right = start;

        if(name[start] < 'N') answer += name[start] - 'A';
        else answer += 'Z' - name[start] + 1;
        name[start] = 'A';

        if(str == name) break;

        int mov = 0;

        while(1){
            ++mov;
            left--;
            right++;

            if(left < 0) left = len-1;
            if(right > len-1) right = 0;

            if(name[right] != 'A'){
                answer += mov;
                start = right;
                break;
            }

            if(name[left] != 'A'){
                answer += mov;
                start = left;
                break;
            }
        }
    }

    return answer;
}
