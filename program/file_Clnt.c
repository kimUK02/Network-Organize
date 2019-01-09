#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF_SIZE 30
int main(int argc, char const *argv[])
{
    int sd; 
    FILE *fp;

    char buff[BUFF_SIZE];
    char file_name[BUFF_SIZE];
    int read_cnt;
    struct sockaddr_in serv_adr;
    if(argc != 3){
        printf("Usage: %s <IP> <Port>\n",argv[0]);
        exit(-1);    
    }
    printf("input file name: ");
    scanf("%s",file_name);
    fp = fopen(file_name,"wb");

    sd = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port=htons(atoi(argv[2]));

    connect(sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
    write(sd, file_name, strlen(file_name)+1);
        fwrite((void*)buff, 1, read_cnt, fp);
    fclose(fp);
    close(sd);
    return 0;
}
