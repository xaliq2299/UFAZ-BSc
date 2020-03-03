#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct arg
{
    int n, p, t;
    long u;
};

void* calculate_u(void* arg){
    int i;
    struct arg* a = arg;
    a->u = 0;
    for( i = 0; i < a->p; i++)
        a->u+=(a->t-1)*a->p+i;

printf("u_%d=%ld\n",a->t,a->u);
pthread_exit(arg);
}

int main(int argc, char *argv[]){
    int i, n, p;
    pthread_t *tabtid;
    long sum;
    struct arg* a;
    if (argc != 3) {
        fprintf(stderr, "usage");
        exit(0);    
    }
    n = atoi(argv[1]);
    p = atoi(argv[2]);
    tabtid = calloc(n, sizeof(*tabtid));

    for( i = 0; i < n; i++)
    {
        a = malloc(sizeof *a);
        a->n = n; a->p = p;
        a->t = i+1; a->u = 0;
        if (pthread_create(&tabtid[i], NULL, calculate_u, (void*) a)) {
            perror("pthread_create");
            exit(1);
        }
    }

    for(i = 0; i < n; i++)
    {
        struct arg* pa;
        if (pthread_join(tabtid[i],(void*)&pa) == -1) 
            perror("pthread_join");
        sum+=pa->u;
        free(pa);
    }
    
    printf("son = %ld\n",sum);
    exit(0);

}
