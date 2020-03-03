#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void alarmHandler(int signo);

int main(void){

    alarm(2);

    signal(SIGALRM, alarmHandler);

    for(int i = 1; i < 10; i++){
        printf("%d\n", i);
        sleep(1);    
    }

    return 0;

}

static void alarmHandler(int signo){
    printf("Alarm signal sent!\n");
}