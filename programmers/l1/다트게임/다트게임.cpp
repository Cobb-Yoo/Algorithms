#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cnt=0;
    int len = dartResult.length();
    int num=0;
    vector<int> arr;
    
    for(int i=0;i<len;i++){
        if(dartResult[i] == 'S'){
            arr.push_back(num);
            cnt++;
            num=0;
        }else if(dartResult[i] == 'D'){
            arr.push_back(num*num);
            cnt++;
            num=0;
        }else if(dartResult[i] == 'T'){
            arr.push_back(num*num*num);
            cnt++;
            num=0;
        }else if(dartResult[i] == '*'){
            if(cnt == 1){
                arr[0] *= 2;
            }else{
                arr[cnt-2] *= 2;
                arr[cnt-1] *= 2;
            }
        }else if(dartResult[i] == '#'){
            arr[cnt-1] = -arr[cnt-1];
        }else{
            num *=10;
            num += (dartResult[i] - '0');
        }
    }
    
    for(int i=0;i<cnt;i++){
        answer += arr[i];
    }
    return answer;
}
