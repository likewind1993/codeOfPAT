#include <cstdio>
#include <vector>
using namespace std;
int main() {
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if(a == 1) printf("1");
    bool state = false;
    for(int i = 2; a >= 2;i++) {
        int cnt = 0, flag = 0;
        while(a % i == 0) {
            cnt++;
            a = a / i;
            flag = 1;
        }
        if(flag) {
            if(state) printf("*");
            printf("%d", i);
            state = true;
        }
        if(cnt >= 2)
            printf("^%d", cnt);
    }
    return 0;
}
