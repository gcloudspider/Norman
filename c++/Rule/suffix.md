###################################################
## Create Date:2016年01月11日 星期一 12时47分30秒
##
##Author:Norman
##
##Description: 每日一点
###################################################

####用++iter替代iter++ (使用前自增运算符会更高效)
    void FSlateNotificationManager::GetWindows(TArray<TSharedRef<SWindow>>&OutWindows) const{
        for(auto Iter(NotificationLists.CreateConstItearator());iter;++iter){
        TSharedPtr<SNotificationList>NotificationList = *iter;
        }
    }
    区别:
        内部结构的区别
        1.前自增运算符改变了对象的状态并返回对象改变后的状态,不需要创建临时对象
        MyOwnClass &operator++(){
            ++meOwnField;
            return (*this);
        }
        2.后自增运算符也改变了对象的状态但是返回的对象是改变前的状态,并且需要创建一个临时对象
        MyOwnClass operator++(int){
            MyOwnClass tmp = *this;
            ++(*this);
            return tmp;
        }

