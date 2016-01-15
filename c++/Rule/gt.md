###################################################
#### Create Date:2016年01月15日 星期五 08时36分10秒
####
####Author:Norman
####
####Description: 
###################################################

####大于0并不意味着等于1
    bool operator()(const GUID& _key1,const GUID& _key2)const {
        return memcmp(&_key1,&_key2,sizeof(GUID)) == -1;
    }

    注:不能将memcpy strcmp以及其他一些标准函数的返回值和1 -1 这些具体数字做比较
        因为这些函数返回值只保证大于0或小于0(并不保证大于0就等于1,小于0就等于-1)
        上面代码可能在很长时间都能正常工作。如果换了编译器源代码，或通过其他方式优化了memcpy()函数然后代码就不能正常工作了

    正确代码:
        bool operator()(const GUID& _key1,const GUID* _key2)const{
            return memcmp(&_key1,&_key2,sizeof(GUID))<0;
        }

    建议:
        不要依赖函数本身行为,如果文档上说一个函数能返回一个不等于0的值
        就是说可能返回-1 0 2 或1024
        经常看到函数返回值就是-1 0 或1 但并不能保证它每次都会这么做
