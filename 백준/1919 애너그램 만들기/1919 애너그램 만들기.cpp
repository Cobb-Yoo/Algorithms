#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr1['z'+1];
int arr2['z'+1];

int main(){
	memset(arr1,0,sizeof(arr1));
	memset(arr2,0,sizeof(arr2));
	
	string s1,s2;
	cin >> s1 >> s2;
	
	for(int i=0;i<s1.size();i++) arr1[s1[i]]++;
	for(int i=0;i<s2.size();i++) arr2[s2[i]]++;
	
	int answer = 0;
	
	for(int i='a';i<='z';i++){
		answer += abs(arr1[i]-arr2[i]);          
	}
	
	cout << answer << endl;
}
