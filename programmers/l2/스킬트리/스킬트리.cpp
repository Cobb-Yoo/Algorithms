#include <string>
#include <vector>
 
using namespace std;
 
bool tree(string tree, string skill) {
    bool broken = false;
    size_t prev = 0;        
    for (auto i : skill) {
        size_t cur = tree.find(i);
		   
        if (cur != string::npos) {
            if (broken || cur < prev) return false;
            else prev = cur;
        } else {
        	broken = true; 	
		}
    }
    return true;
}
 
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (auto i : skill_trees) if (tree(i, skill)) answer++;    
    return answer;
}
