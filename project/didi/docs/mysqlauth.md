===========================
###Create Date:2016年01月08日 星期五 08时49分41秒
###Author:Norman
###Description: MySQL密码验证实现原理
===========================

用户密码保存在mysql.user表password列,并且以hash值形式加密保存
###验证过程:
    1.客户端请求连接
    2.服务器随机生成一个random string发送给客户端
    3.客户端收到random string后进行hash加密
        3.1:将密码hash 得到hash值 hash_stage1    eg.hash_stage1 = sha1("password");
    	3.2:二次hash 得到hash_stage2  eg.hash_stage2=sha1(hash_stage1);
    	3.3:将二次hash得到的值与random string进行hash 得到hash_stage3 eg.hash_stage3 = sha1("random string",hash_stage2)
    	3.4:异或处理 reply=xor(hash_stage1,hash_stage3);
    	3.5:将reply的值发送给服务器端
    4.服务器端收到reply后同样进行hash运算
    	4.1:将保存的hash形式密码hashpassword 与random string进行hash
        	server_hash_stage1 = sha1("random string","hashpassword");
        4.2:将客户端发送的reply与刚才得到的hash值进行异或运算,得到xor_value 
        	eg.xor_value=xor(reply,server_hash_stage1)
        4.3:将得到异或值进行hash 得到server_hash_stage2
        	eg.server_hash_stage2 = sha1(server_hash_stage1)
        4.4:将最后得到hash值server_hash_stage2与保存的密码hashpassword进行比较
        	eg.server_hash_stage2 == hashpassword 相等则验证通过

