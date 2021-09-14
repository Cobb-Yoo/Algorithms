// 첫번째 접근 방법 : 등차수열의 합
using namespace std;


long long solution(int price, int money, int count)
{    
    long long a = price, b = money, c = count;
    // long long result = count * (price + price*count)/2-money;    안됨
    //long long result = count * price * (1+count)/2-money;         안됨ㅠ 
    long long result = c * a * (1+c)/2-b;
    
    if(result > 0) return result;
    return 0;
}

// 형변환을 잘 생각을 해야한다.  
