#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
pair<int,int> kij;
pair<int,int> sij;
vector<string> md;

int main(){
	string king, stone;
	cin >> king >> stone >> n;
	
	kij.first = king[0]-'A'; // 0~7
	kij.second = king[1]-'1';
	sij.first = stone[0]-'A';
	sij.second = stone[1]-'1';
	
	for(int i=0;i<n;i++){
		string tmp;
		cin >> tmp;
		
		int a = 0,b = 0;
		if(tmp[0] == 'R') a = 1;
		else if(tmp[0] == 'L') a = -1;
		else if(tmp[0] == 'B') b = -1;
		else b = 1;
		
		if(tmp.size() == 2){
			if(tmp[1] == 'B') b = -1;
			else b = 1;
		}
		
		int next_king_x = kij.first + a;
		int next_king_y = kij.second + b;
		
		if(0<=next_king_x&&next_king_x<8 && 0<=next_king_y&&next_king_y<8){
			if(next_king_x == sij.first && next_king_y == sij.second){
				int next_stone_i = sij.first + a;
				int next_stone_j = sij.second + b;
				
				if(0<=next_stone_i&&next_stone_i<8 && 0<=next_stone_j&&next_stone_j<8){
					kij.first += a;
					kij.second += b;
					sij.first += a;
					sij.second += b;
				}
				else continue;
			}
			else{
				kij.first += a;
				kij.second += b;
			}
		}
	}
	
	cout << (char)(kij.first+'A') << kij.second+1 << endl;
	cout << (char)(sij.first+'A') << sij.second+1 << endl;
}
