#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {    
    for(int i=1;i*i<=red;i++){
        if(!(red%i)){
            int a = i + 2;
            int b = red/i + 2;
            
            if(brown + red == a * b) return {b,a};
        }
    }
}
