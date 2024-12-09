#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>

#define DRIVER_NAME "/dev/md_salik_alim"
#define SET_SIZE_OF_QUEUE_IOW('a','a',int*);

int main(void){
    int fd,size,ret;
    fd=open(DRIVER_NAME,O_RDWR);
    if(fd<0){
        perror("Failed to set size of the queue");
        return -1;
    }
        scanf("%d,&size");

        ret= ioctl(fd,SET_SIZE_OF_QUEUE_IOW,&size);
        if(ret<0){
            perror("Failed to ett size of the queue");
            close(fd);
            return -1;
        }
    printf("Queue size set to %d successfully\n",size);
    close(fd);
    return 0;
}
