#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int tmp_x = x;
    int sum=0;
    while(tmp_x > 0){
        sum += tmp_x % 10;
        tmp_x /= 10;
    }
    
    return x % sum ? false : true;
}
