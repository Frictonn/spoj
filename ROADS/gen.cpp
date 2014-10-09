#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    printf("1\n");
    int K, N, R;
    K=9999;
    N=99;
    R=9999;
    printf("%d\n%d\n%d\n", K, N, R);
    
    for(int i=0;i<R;++i){
        printf("%d %d %d %d\n", rand()%N+1, rand()%N+1, rand()%99+1, rand()%100);
    }
    
    /*
    for(int i=0;i<N;++i){
        printf("%d %d %d %d\n", i+1, i+2, rand()%99+1, rand()%100);
    }
    */
    return 0;
}