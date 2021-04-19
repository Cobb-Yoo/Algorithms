#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) a ^= b ^= a ^= b;
    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
    return answer;
}
