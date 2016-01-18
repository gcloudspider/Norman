###################################################
#### Create Date:2016年01月17日 星期日 11时04分11秒
####
####Author:Norman
####
####Description: 不要去做编译器工作
###################################################

####此Bug出现在MySQL源代码中:
    按此写原因:编译器会将代码优化成以下(此更接近于编译器,提高运行效率)
    static int rr_cmp(uchar* a,uchar* b){
        if(a[0] != b[0])
            return (int) a[0] - (int)b[0];
        if(a[1] != b[1])
            return (int) a[1] - (int)b[1];
        if(a[2] != b[2])
            return (int) a[2] - (int)b[2];
        if(a[3] != b[3])
            return (int) a[3] - (int)b[3];
        if(a[4] != b[4])
            return (int) a[4] - (int)b[4];
        if(a[5] != b[5])
            return (int) a[1] - (int)b[5];  <<<<=== return(int) a[5] - (int)[5]
        if(a[6] != b[6])
            return (int) a[6] - (int)b[6];
        return (int)a[7] - (int)b[7]
    }

####说明:
    实现循环,拷贝其中鞭个数组下标忘记更改

####建议:
    static int rr_cmp(uchar* a,uchar* b){
        for(size_t i=0;i<7;i++){
            if(a[i] != b[i])
                return a[i] - b[i];
        }
        return a[7] - b[7];
    }
    
    优势:
        1.容易理解
        2.降低犯错几率
