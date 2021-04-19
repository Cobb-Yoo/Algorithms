#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int len = arr.size();
    double answer = 0;
    for(int i=0;i<len;i++) answer += arr[i];
    answer /= len;
    return answer;
}
