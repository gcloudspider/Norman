/*mZSQLyog Ultimate v11.24 (32 bit)
MySQL - 5.6.12-log : Database - mailarchive
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`didi` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `didi`;

/*Table structure for table `dadauser` */

DROP TABLE IF EXISTS `didiuser`;

CREATE TABLE `didiuser` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `userid` int(10) NOT NULL COMMENT '用户ID',
  `username` varchar(255) NOT NULL COMMENT '真实用户名',
  `nickname` varchar(255) NOT NULL COMMENT '昵称',
  `passwd` varchar(255) NOT NULL COMMENT '密码',
  `telphone` varchar(255) NOT NULL COMMENT '电话号码',
  PRIMARY KEY (`id`),
  UNIQUE KEY `userid` (`userid`),
  UNIQUE KEY `telphone` (`telphone`)
) ENGINE=InnoDB AUTO_INCREMENT=4959 DEFAULT CHARSET=utf8;


DROP TABLE IF EXISTS `didiorders`;

CREATE TABLE `didiorders` (
    `id` int(10) NOT NULL AUTO_INCREMENT,
    `orderid` int(10) NOT NULL COMMENT '订单号',
    `starting` varchar(255) NOT NULL COMMENT '始发地',
    `destination` varchar(255) NOT NULL COMMENT '目的地',
    `userid` int(10) NOT NULL COMMENT '订单发起人id',
    `driverid` int(10) NOT NULL COMMENT '订单接收司机id',
    `starttime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00' COMMENT '上车时间',
    `arrivaltime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00' COMMENT '到达时间',
    `payment` varchar(255) NOT NULL COMMENT '付款(元)',
    PRIMARY KEY(`id`),
    UNIQUE KEY `orderid` (`orderid`)
)ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `dididriver`;

CREATE TABLE `dididriver` (
    `id` int(10) NOT NULL AUTO_INCREMENT,
    `driverid` int(10) NOT NULL COMMENT '司机证件号',
    `drivername` varchar(255) NOT NULL COMMENT '司机姓名',
    `driverpasswd` varchar(255) NOT NULL COMMENT '司机登录密码',
    `drivertelphone` varchar(255) NOT NULL COMMENT '司机电话号码',
    `drivercarnum` varchar(255) NOT NULL COMMENT '车牌号',
    PRIMARY KEY(`id`),
    UNIQUE KEY `driverid` (`driverid`),
    UNIQUE KEY `drivertelphone` (`drivertelphone`)
)ENGINE=InnoDB AUTO_INCREMENT=4959 DEFAULT CHARSET=utf8;

/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
