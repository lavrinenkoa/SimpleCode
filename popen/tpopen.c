#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
        FILE* pipe;
//        if ((pipe=(FILE*)popen("./test.sh","r"))==NULL)
        if ((pipe=(FILE*)popen("rpm -qa itc-asset-opk-kit","r"))==NULL)
                printf("this is not working\n");
        char buf[1024] = {'\0'};

        int fd=fileno(pipe);

        int bytes = read(fd, buf, 1024);

        printf("bytes read %d\n", bytes);

        printf("The program: %s\n", buf);
        if(pclose(pipe)<0)
                printf("not working\n");
        return 0;
}
