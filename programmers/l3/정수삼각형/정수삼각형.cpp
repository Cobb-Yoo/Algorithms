#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int len = triangle.size();

    for(int i=len-2;i>=0;i--){
        int len2 = triangle[i].size();
        for(int j=0;j<len2;j++) triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]);
    }
    return triangle[0][0];
}
