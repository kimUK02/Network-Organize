#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF_SIZE 30

int main(int argc, char const *argv[])
{
    int serv_sd, clnt_sd;
    FILE *fp;
    char buf[BUFF_SIZE];
    char file_name[BUFF_SIZE];
    int read_cnt;

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    if(argc != 2){
        printf("Usage: %s <port>\n",argv[0]);
        exit(1);    
    }

    serv_sd = socket(PF_INET, SOCK_STREAM, 0);
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = AF_INET;
    serv_adr.sin_port = htons(atoi(argv[1]));
    
    bind(serv_sd, 0, sizeof(serv_sd));
    listen(serv_sd,5);
    
    clnt_adr_sz = sizeof(clnt_adr);
    clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        
    clnt_adr_sz = sizeof(clnt_adr);
    clnt_sd =accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

    read(clnt_sd, file_name, BUFF_SIZE);
    fp = fopen(file_name,"rb");
    if(fp != NULL){
        while(1){
            read_cnt = fread(buf, 1, BUFF_SIZE, fp);
            if(read_cnt < BUFF_SIZE){
                write(clnt_sd, buf,read_cnt);    
                break;
            }
            write(clnt_sd, buf,BUFF_SIZE);
        }
    }

    
    return 0;
}

