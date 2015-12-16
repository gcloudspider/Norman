###################################################
## Create Date:2015年12月16日 星期三 21时46分58秒
##
##Author:Norman
##
##Description: 
###################################################

rebar构建项目:
    1.mkdir rebarapp
    2.cd rebarapp
    3.创建项目:
        rebar create-app appid=rebarapp

    rebar根据默认模板(template)在当前目录下生成src文件夹,包含文件:
        rebarapp.app.src 应用资源描述文件，影响后面编译生成的rebarapp.app里内容
        rebarapp_app.erl应用的Application Behaviour代码文件
        rebarapp_sup.erl应用的Supervisor Behaviour代码文件

rebar内置gen_server, gen_fsm application等 Erlan/OTP行为模式的模板,可以自动生成这些行为模式的框架代码
