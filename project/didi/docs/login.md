###################################################
## Create Date:2016年01月06日 星期三 14时55分21秒
##
##Author:Norman
##
##Description: 
###################################################
用户请求登录:

示例:
{"head":{"packtype":1,"event":2,"version":"1.0","reqId":"8087cdf7-f4f6-456e-943f-d0adc17332e9"},"body":{"usertype":2,"telphone":"15012960449","passwd":"134567"}}!

用户密码验证成功返回:
    recode: 201
    remsg: "passwd auth successful!"
示例:
{"head":{"packtype":2,"event":2,"version":"1.0","reqId":"8087cdf7-f4f6-456e-943f-d0adc17332e9"},"body":{"recode":201,"remsg":"passwd auth successful!"}}

用户不存在返回:
    recode:404
    remsg: "user not exist"

用户密码验证失败:
    recode:406
    remsg: "passwd auth failed!"
