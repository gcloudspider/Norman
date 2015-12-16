###################################################
## Create Date:2015年12月16日 星期三 21时35分51秒
##
##Author:Norman
##
##Description: 
###################################################

安装rebar:
    1.github源码安装:
    git clone git://github.com/rebar/rebar.git
    cd rebar
    ./bootstrap

    2.从https://github.com/rebar/rebar/wiki/rebar下载编译好的版本

配置rebar:
    编译好后生成名为rebar独立的erlang脚本,将它放在项目路径下,或把rebar放在系统目录path下

    sudo mv rebar /usr/local/bin/

测试:
    rebar -c 列出可执行的rebar命令.或rebar -h查看帮助
