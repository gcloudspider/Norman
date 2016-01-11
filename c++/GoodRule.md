###################################################
## Create Date:2016年01月11日 星期一 12时47分30秒
##
##Author:Norman
##
##Description: 
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
