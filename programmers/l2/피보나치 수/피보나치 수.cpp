#include <string>
#include <vector>

using namespace std;
const int MAX = 100000;

int solution(int n) {
    int arr[MAX+1] ={0};
    arr[1] = 1;
    for(int i=2;i<=MAX;i++){
        arr[i] = (arr[i-1] + arr[i-2])%1234567;
    }
    
    return arr[n];
}
