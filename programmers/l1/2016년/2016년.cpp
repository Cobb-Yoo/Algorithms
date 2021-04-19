#include <string>
#include <vector>

using namespace std;

int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
string week[] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};

string solution(int a, int b) {
    int sum=0;
    for(int i=0;i<a-1;i++){ //해당하는 달의 날은 더하면 안되므로 a-1
        sum += month[i];
    }
    sum += b;
    
    return week[sum%7];;
}
