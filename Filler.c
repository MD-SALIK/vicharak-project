#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>

#define DRIVER_NAME "/dev/md_salik_alim"
#define PUSH_DATA_IOW('a','b',struct data *)

struct data
{
   int length;
   char *data
};

int main(void){
    int fd,ret;
    struct data d;

    fd=open(DRIVER_NAME,O_RDWR);
    if(fd<0){
        perror("Failed to open device file");
        return -1;
    }

    printf("Enter data to push:")
    char buffer[256];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strcspn(buffer,"\n")]='\0';

    d.length = strlen(buffer);
    d.data = malloc(d.length+1);
    if(!d.data){
        perror("Memory allocation failed");
        close(fd);
        return -1;
    }
    printf("Data pushed successfully: %s\n,buffer");

    free(d.data);
    close(fd);
    return 0;
}
