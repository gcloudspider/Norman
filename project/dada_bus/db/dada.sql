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
CREATE DATABASE /*!32312 IF NOT EXISTS*/`dadabus` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `dadabus`;

/*Table structure for table `dadauser` */

DROP TABLE IF EXISTS `dadauser`;

CREATE TABLE `dadauser` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `userid` int(10) NOT NULL COMMENT '用户ID',
  `username` varchar(255) NOT NULL COMMENT '用户名',
  `nickname` varchar(255) NOT NULL COMMENT '昵称',
  `passwd` varchar(255) NOT NULL COMMENT '密码',
  `telphone` varchar(255) NOT NULL COMMENT '电话号码',
  `orders` varchar(255) NOT NULL COMMENT '订单号',
  PRIMARY KEY (`id`),
  UNIQUE KEY `userid` (`userid`),
  KEY `name` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=4959 DEFAULT CHARSET=utf8;


DROP TABLE IF EXISTS `dadaorders`;


/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
