###################################################
## Create Date:2016年01月11日 星期一 12时47分30秒
##
##Author:Norman
##
##Description: 每日一点
###################################################

####c++代码习惯:
    1.尽可能使用枚举类
    enum class PhysGunDrop_t{
        DROPPED_BY_PLAYER,
        THROWN_BY_PLAYER,
        DROPPED_BY_CANNON,
        LAUNCHED_BY_CANNON,
    };
    void CBreakableProp::OnPhysGunDrop(...,PhysGunDrop_t Reason){
        ....
        if(Reason == PhysGunDrop_t::LAUNCHED_BY_CANNON){
            PlayPuntSound();
        }
        ....
    }

    2.用++iter替代iter++
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

