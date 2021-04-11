#include <iostream>
using namespace std;

const int MAX = 100000;

int inOrder[MAX+1];
int postOrder[MAX+1];
int idex[MAX+1];

void preOrder(int inBegin, int inEnd, int postBegin, int postEnd){
    if (inBegin > inEnd || postBegin > postEnd) return;
 
    int root = postOrder[postEnd];
    cout << root << " ";
 
    preOrder(inBegin, idex[root] - 1, postBegin, postBegin + (idex[root] - inBegin) - 1);
    preOrder(idex[root] + 1, inEnd, postBegin + (idex[root] - inBegin), postEnd - 1);
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> inOrder[i];
	}
	for(int i=0;i<n;i++){
		cin >> postOrder[i];
	}
	
	for(int i=0;i<n;i++){
		idex[inOrder[i]] = i;
	}
	
	preOrder(0,n-1,0,n-1);
}
