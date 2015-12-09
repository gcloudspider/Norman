/*########################################################
##File Name: syschmod.c
##Created Time:2015年12月09日 星期三 09时08分24秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include"head.h"
void usage(){
    fprintf(stderr,"Usage: systrim <filename>\n");
    exit(2);
}

int strtrim(const char* src){
    int fd;
    char ch;
    int ret;
    int rd_off =0,wr_off=0;
    fd = open(src,O_RDWR);
    if(-1 == fd){
        perror("error");
        return -1;
    }
    while(1){
        ret = read(fd,&ch,1);
        if(ret <=0)break;
        rd_off = lseek(fd,0,SEEK_CUR);
        if(ch !=' '){
            lseek(fd,wr_off,SEEK_SET);
            write(fd,&ch,1);
            wr_off=lseek(fd,0,SEEK_CUR);
        }
        lseek(fd,rd_off,SEEK_SET);
    }
    ftruncate(fd,wr_off);
    close(fd);
    return 0;
}

int main(int argc,char* argv[]){
    int ch;
    int ret;

    while((ch=getopt(argc,argv,"hv"))!=EOF){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'v':
                break;
            default:
                usage();
                break;
        }
    }

    if(argc <2){
        usage();
    }
 
    strtrim(argv[1]);
}
