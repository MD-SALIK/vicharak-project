#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioct.h>

#define DRIVER_NAME "/dev/md_salik_alim"
#define POP_DATA_IOR('a','c',struct data *)

struct data {
    int length;
    char *data;

};

int main (void){
    int fd,ret;
    struct data d;

    fd =open(DRIVER_NAME,O_RDWR);
    if(fd<0){
        perror("Failed to open device file");
        return -1;
    }

    printf("Enter the maximum data length to pop:");
    scanf("%d",&d.length);
    getchar();

    d.data=malloc(d.length+1);
    if(!d.data){
        perror("Memory allocation failed");
        close(fd);
        return -1;
    }
    memset(d.data,0,d.length+1);
    ret = ioctl (fd,POP_DATA, &d);
    if(ret<0){
        perror("Failed to pop data");
        free(d.data);
        close(fd);
        return -1;
    }
    printf("poped data: %s\n", d.data);
    free(d.data);
    close(fd);
    return 0;
}
