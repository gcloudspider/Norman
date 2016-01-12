###################################################
## Create Date:2016年01月12日 星期二 11时16分19秒
##
##Author:Norman
##
##Description: 
###################################################

####UML图:
    
    SingleCore  <---- CoreAFactory <----- main (客户端)
        ^                   ^
        |                   |
        |                   |
    SingleCoreA         AFactoryMethod
        ^                   |
        |                   |
        |                   |
        ---------------------
          new CSingleCoreA()
