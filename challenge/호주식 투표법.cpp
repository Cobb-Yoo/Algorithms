#include <stdio.h>
#include <stdlib.h>

char name[1000][80];
int vote[1000][1000] = {0};

main(){
	int peaple;//���ĺ��� �� 
	int j,pointing=0;
	char line[2000];
	int got_ratio[1000]={0};
	
	scanf("%d",&peaple);
	
	for(int i=0;i < peaple;i++){
		scanf("%s",name[i]);
	}
	
	gets(line);
	while(gets(line) && *line){ // �� �̻� �Է��� ���� �� ���� ���� 
		j++;
		for(int i =0;i < peaple;i++){ // �װ� ��ǥ �迭�� ���� 
			vote[j][i] = line[i];// j�� ��ǥ�� ������� ��, i�� �� ����� ��ǥ ����. 
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
