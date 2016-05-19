#include <stdio.h>
#include <sys/statvfs.h>

#define _FILE_OFFSET_BITS 64
typedef enum {
    TOTAL_SIZE,///文件系统的大小
    FREE_SIZE, ///自由空间
    USED_SIZE, ///已用空间
    AVAIL_SIZE ///用户实际可以使用的空间
}VFsize;

//把数字大小转换成字符形式
char * byte_size_to_string(fsblkcnt_t size) {
    const double k = 1024;
    const double m = k*1024;
    const double g = m*k;
    static char size_str[128] = {0};
    if(size>=g)
        sprintf(size_str,"%0.2lf GB",size/g);
    else if(size>=m)
        sprintf(size_str,"%0.2lf MB",size/m);
    else if(size>=k)
        sprintf(size_str,"%0.2lf KB",size/k);
    else
        sprintf(size_str,"%0.0lf Byte",size>=0?size:0.0);
    return size_str;
}
///文件系统的各种信息数据的大小
fsblkcnt_t get_vfs_size(struct statvfs *buf,VFsize flag){
    fsblkcnt_t block;
    fsblkcnt_t bsize;
    bsize = buf->f_bsize;
    switch (flag){
    case TOTAL_SIZE:
        block = buf->f_blocks;
    break;
    case FREE_SIZE:
        block = buf->f_bfree;
    break;
    case USED_SIZE:
        block = buf->f_blocks - buf->f_bavail;
    break;
    case AVAIL_SIZE:
        block = buf->f_bavail;
    break;
    default:
        block = 0;
    break;
    }
    return  bsize * block;
}
int main(int argc, char **argv) {
    char *pathname;
    struct statvfs buf;
    fsblkcnt_t total_size;
    fsblkcnt_t used_size;
    fsblkcnt_t avail_size;
    int error;
    pathname = "/boot";
    if(argc>1){
        pathname = argv[1];
    }
    //把文件系统信息读入 struct statvfs buf 中
    error = statvfs(pathname,&buf);
    //错误检查
    if(error <0){
        fprintf(stderr,"statvfs():%m\n");
        return error;
    }
    //输出结果，此结果与gparted一致，与df出入较大
    printf("FileSystem of \'%s\':\n",pathname);
    total_size = get_vfs_size(&buf,TOTAL_SIZE);
    printf("       total:%s\n",byte_size_to_string(total_size));
    used_size = get_vfs_size(&buf,USED_SIZE);
    printf("       used :%s\n",byte_size_to_string(used_size));
    avail_size = get_vfs_size(&buf,AVAIL_SIZE);
    printf("       Avail:%s\n",byte_size_to_string(avail_size));
    return 0;
}
