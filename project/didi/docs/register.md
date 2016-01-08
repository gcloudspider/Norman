###################################################
## Create Date:2016年01月06日 星期三 08时27分01秒
##
##Author:Norman
##
##Description: 
###################################################

注册用户:

示例:
{"head":{"packtype":1,"event":1,"version":"1.0","reqId":"4581ee3b-9f24-4d35-abce-94635e0f9e84"},"body":{"usertype":1,"telphone":"1234567123","nickname":"norman","username":"张三","passwd":"123456"}}

响应:

注册成功:
{"head":{"packtype":2,"version":"1.0","reqId":""},"body":{"recode":"200","remsg":"user register success!"}}

注册失败:
{"head":{"packtype":2,"version":"1.0","reqId":""},"body":{"recode":"403","remsg":"user register failed!"}}

用户已存在:
{"head":{"packtype":2,"version":"1.0","reqId":""},"body":{"recode":"405","remsg":"user register is exist"}}
