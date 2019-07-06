#include <cstdio>

using namespace std;
typedef long long LONGLONG;
typedef unsigned long long ULONGLONG;

LONGLONG Sums(ULONGLONG n)
{
    ULONGLONG iCount = 0;
    ULONGLONG iFactor = 1;
    ULONGLONG iLowerNum = 0;
    ULONGLONG iCurrNum = 0;
    ULONGLONG iHigherNum = 0;
    
    while( n / iFactor != 0)
    {
        iLowerNum = n - (n / iFactor) * iFactor;
        iCurrNum = (n / iFactor) % 10;
        iHigherNum = n / (iFactor * 10);
        
        switch (iCurrNum)
        {
            case 0:
                iCount += iHigherNum * iFactor;
                break;
            case 1:
                iCount += iHigherNum * iFactor + iLowerNum + 1;
                break;
            default:
                iCount += (iHigherNum + 1) * iFactor;
                break;    
        } 
        iFactor *= 10;
    }
    return iCount;
}

int main()
{
    ULONGLONG input;
    scanf("%lld", &input);
    printf("%lld", Sums(input));
    return 0;       
} 
