代码分布:

didi
    |----conf                           //配置文件目录
    |       |____didi.conf              //主程序配置文件
    |       |____zlog.conf              //日志系统配置文件 zlog
    |
    |----db                             //数据库
    |     |____didi.sql                 //mysql Script
    |
    |----docs
    |       |____INSTALL.md             //安装文档
    |       |____Layout.md              //布局文档
    |       |____login.md               //登录json数据格式
    |       |____register.md            //注册json数据格式
    |       |____tasklist.md            //开发任务进度表
    |       |____mysqlauth.md           //MySQL密码验证文档
    |
    |----include                        //头文件
    |       |____didi.h
    |       |____iniparser.h            
    |       |____dictionary.h
    |       |____cjson.h
    | 
    |----src                            //源代码
    |       |____client
    |       |       |____include
    |       |       |____src
    |       |       |____Makefile
    |       |       
    |       |____driver
    |       |       |____include
    |       |       |____src
    |       |       |____Makefile
    |       |       
    |       |____didi.c
    |       |____cjson.c
    |       |____iniparser.c
    |       |____dictionary.c
    |       |____didi_parse_conf.c
    |       |____didi_log_manage.c
    |       |____didi_db_manage.c
    |       |____didi_cache_manage.c
    |       |____didi_common.c
    |       |____didi_core_manage.c
    |       |____didi_event_manage.c
    |       |____didi_loop_manage.c
    |       |____didi_package_msg.c
    |       |____Makefile
    |
    |----test                           //单元测试
    |       |____test_create_json*.c
    |       |____test_daemon.c
    |       |____test_genreqId.c
    |       |____test_iniparser.c
    |       |____test_*_database.c
    |       |____test_parse_json*.c
    |       |____test_uuid_*.c
    |       |____test_zlog.c
    |       |____Makefile
    |
    |----Makefile
    |----README.md
