/**
* Create Date:2016年02月18日 星期四 17时59分23秒
* 
* Author:Norman
* 
* Description: 
*/

####Linux下I2C结构:
    1.I2C host模式
    Nand  LCD
    |       |                  (逻辑虚拟出来的接口)
    --------------------------
              i2c-core         (i2C Host)
    --------------------------
    |       |      |   |   |   (I2C接口可以接Nandflash LCD等)
    Nand   LCD   ==
