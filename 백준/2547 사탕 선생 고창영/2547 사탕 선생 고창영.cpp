#include <stdio.h>

int rel[100000];

int main()
{
   int T,a, k = 0;
   unsigned long long c,sum = 0,tmp = 0; // 최대 입력값이 10^18 이라서 쓴겁니다. 
   
   scanf("%d",&T); // 최초 테스트 케이스 수 입력값 
   
   for(int i = 0; i < T; i++) // 테스트 케이스 만큼 돌아라 
   {
      scanf("%d",&a); // 사탕을 가져온 인원 수 
   
      for(int j = 0; j < a; j++) // 인원수가 가져온 사탕수 입력받기 
      {
         scanf("%lld",&c); 
         tmp = c % a; // 최대 입력값이 10^18이기 때문에 unsigned를 써도 오버플로우가 일어납니다.
         // 이그래서 애초에 입력받자마자 바로 계산해서 수를 낮춰줍니다. 
         sum += tmp; // 계산한 값을 더해줍니다. 
      }
      if(sum % a == 0)
      {
         sum = 0; // 다음 케이스에서도 sum은 써야되고, 값이 바뀌지않고 계속 증가될수 잇으니 초기화 
         rel[k] += 1; //그 결과값이 YES인지 NO인지를 결정합니다. (여기가 문제) 
         k++;
      }
      else
      {
         sum = 0;
         rel[k] += 2;
         k++;
      }
      
   }
   
   for(int i = 0; i < T; i++)
   {
      if(rel[i] == 1) // 결과값에 1이 저장되어있을때 YES
      {
         printf("YES\n");
      }
      else if (rel[i] == 2) // 나머지 NO 
      {
         printf("NO\n");
      }
   }

}
