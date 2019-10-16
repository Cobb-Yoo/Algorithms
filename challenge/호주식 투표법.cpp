#include <stdio.h>
#include <stdlib.h>

char name[1000][80];
int vote[1000][1000] = {0};

main(){
	int peaple;//입후보의 수 
	int j,pointing=0;
	char line[2000];
	int got_ratio[1000]={0};
	
	scanf("%d",&peaple);
	
	for(int i=0;i < peaple;i++){
		scanf("%s",name[i]);
	}
	
	gets(line);
	while(gets(line) && *line){ // 더 이상 입력이 없을 때 까지 받음 
		j++;
		for(int i =0;i < peaple;i++){ // 그걸 투표 배열에 저장 
			vote[j][i] = line[i];// j가 투표한 사람들의 수, i는 그 사람의 투표 순서. 
		}
	}
	 
	for(int i=0, max=0;;i++){
		for(int count=0;count < peaple;count ++){
			got_ratio[vote[count][i]]++;
		}
		
		for(j=0;j<peaple;j++){
			if(max < got_ratio[j]){
				max = got_ratio[j];
				pointing = j;
			}
		}
		
		if(max >= peaple*(i+1) / 2){
			printf("%s\n",name[pointing]);
			break;	
		}
	}
}
