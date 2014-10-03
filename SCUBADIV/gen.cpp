#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    printf("2\n");
    for(int i=0;i<2;++i){
        printf("21 79\n");
        printf("1000\n");
        for(int i=0;i<500;++i){
            printf("%d %d %d\n", rand()%10+1, rand()%20 + 1, rand()%300 + 270);
        }
        for(int i=0;i<500;++i){
            printf("%d %d %d\n", rand()%3+1, rand()%4+2, rand()%200 + 233);
        }
    }
    return 0;
}