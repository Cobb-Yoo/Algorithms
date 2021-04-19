#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long nn = sqrt(n);
    
    if(n == nn*nn) return (nn+1) * (nn+1);
    return -1;
}
