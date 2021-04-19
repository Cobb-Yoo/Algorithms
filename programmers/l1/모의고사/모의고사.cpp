#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int spineBreaker1[] = {1,2,3,4,5};
int spineBreaker2[] = {2,1,2,3,2,4,2,5};
int spineBreaker3[] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    int score[3]={0};
    int len = answers.size();
    for(int i=0;i<len;i++){
        if(answers[i] == spineBreaker1[i%5]) score[0]++;
        if(answers[i] == spineBreaker2[i%8]) score[1]++;
        if(answers[i] == spineBreaker3[i%10]) score[2]++;
    }

    vector<int> answer;

    int MAX = max(score[0],max(score[1],score[2]));

    for(int i=0;i<3;i++)
        if(MAX == score[i]) answer.push_back(i+1);

    return answer;
}
