#include <string>
#include <vector>

using namespace std;

pair<int,int> arr[] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

int distance(pair<int,int> a, pair<int,int> b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int len = numbers.size();
    pair<int,int> l_posi = {3,0};
    pair<int,int> r_posi = {3,2};
    
    for(int i=0;i<len;i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            l_posi = arr[numbers[i]];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            r_posi = arr[numbers[i]];
        }
        else{
            int l_dis = distance(arr[numbers[i]], l_posi);
            int r_dis = distance(arr[numbers[i]], r_posi);
            
            if(l_dis == r_dis) {
                if(hand == "right") {
                    answer += 'R';
                    r_posi = arr[numbers[i]];
                }
                else {
                    answer += 'L';
                    l_posi = arr[numbers[i]];
                }
            }
            else if(l_dis > r_dis) {
                answer += 'R';
                r_posi = arr[numbers[i]];
            }
            else {
                answer += 'L';
                l_posi = arr[numbers[i]];
            }
        }
    }
    
    return answer;
}
