#!/bin/bash
#Global Var
SysVer=
ProName="NyServer"
ProVer="1.0.0"
CurrentPath=`pwd`
OSVersion=""
IsRoot=""

isRoot(){
	CurrentUser=`whoami`
	if [ $CurrentUser = "root" ];then
  		IsRoot="1"
	else
  		IsRoot="0"
	fi
}

checkOS(){
	if [[ -f /usr/bin/lsb_release ]]; then
        	OS=$(/usr/bin/lsb_release -a |grep Description |awk -F : '{print $2}' |sed 's/^[ \t]*//g')
	else
        	OS=$(cat /etc/issue |sed -n '1p')
	fi
	OSVersion=`echo -e "${OS}" | awk '{print $1}'`
}

checkDepend() {
    rpm='cmake libuuid-devel openssl-devel device-mapper-devel ncurses-devel readline-devel' 
    for i in $rpm
    do
        if test -z `rpm -qa $i`
        then
            echo "$i isn't installed!"
            echo "starting install $i"
            yum -y install $i
        else
            echo "$i was installed!"
        fi
    done
}

print_help(){
    echo "Usage: $0 [ options ] "
    echo "Options:"
    echo "  -h|--help           Show this help text."
    echo "  -c|--clean          Clean all build"
    echo "  -d|--debug          Build debug version"
    echo "  -r|--release        Build release version"
}

getSysVer(){
    ldconfig
    if [ $(getconf WORD_BIT) = '32' ] && [ $(getconf LONG_BIT) = '64' ] ; then
        SysVer="64"
    else
        SysVer="32"
    fi
}

build_version(){
    if [ $1 = "debug" ];then
	echo "build debug"
	cmake -DCMAKE_BUILD_TYPE=Debug .
    else
	echo "build release"
	cmake -DCMAKE_BUILD_TYPE=Release .
    fi
}

build() {
    echo "#ifndef __VERSION_H__" > nyinc/version.h
    echo "#define __VERSION_H__" >> nyinc/version.h
    echo "#define VERSION \"$ProVer\"" >> nyinc/version.h
    echo "#endif" >> nyinc/version.h

    if [ ! -d nylib ]
    then
        mkdir nylib
    fi

    cd nyutil
    
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make nyutil successed";
    else
        echo "make nyutil failed";
        exit;
    fi
    if [ -f libnyutil.a ] 
    then
        cp libnyutil.a ../nylib/
    fi

    cd ../filemo
    build_version $1
    cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make filemo successed";
    else
        echo "make filemo failed";
        exit;
    fi
    if [ -f libfilemo.a ]
    then
        cp libfilemo.a ../nylib/
    fi

    cd ../netmo
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make netmo successed";
    else
        echo "make netmo failed";
        exit;
    fi
    if [ -f libnetmo.a ]
    then
        cp libnetmo.a ../nylib/
    fi

    cd ../sysmo
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make sysmo successed";
    else
        echo "make sysmo failed";
        exit;
    fi
    if [ -f libsysmo.a ]
    then
        cp libsysmo.a ../nylib/
    fi

    cd ../cprotocol
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make cprotocol successed";
    else
        echo "make cprotocol failed";
        exit;
    fi
    if [ -f libcprotocol.a ]
    then
        cp libcprotocol.a ../nylib/
    fi

    cd ../client
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make client successed";
    else
        echo "make client failed";
        exit;
    fi
    if [ -f libclient.a ]
    then
        cp libclient.a ../nylib/
    fi

    cd ../hprotocol
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make hprotocol successed";
    else
        echo "make hprotocol failed";
        exit;
    fi
    if [ -f libhprotocol.a ]
    then
        cp libhprotocol.a ../nylib/
    fi

    cd ../httpserv
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make httpserv successed";
    else
        echo "make httpserv failed";
        exit;
    fi
    if [ -f libhttpserv.a ]
    then
        cp libhttpserv.a ../nylib/
    fi

    cd ../service
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make service successed";
    else
        echo "make service failed";
        exit;
    fi
    if [ -f libservice.a ] 
    then
        cp libservice.a ../nylib/
    fi

    cd ../nyserver
    build_version $1
    #cmake .
    make
    if [ $? -eq 0 ]; then
        echo "make nyserver successed";
    else
        echo "make nyserver failed";
        exit;
    fi

    cd ../

    build_version=$ProName-$SysVer-$ProVer-$1
    build_name=$build_version.tar.gz
    if [ -e "$build_name" ]; then
        rm $build_name
    fi
    mkdir -p ../../iss/$build_version
    mkdir -p ../../iss/$build_version/nyserver

    cp ../../iss/cfg/servcfg ../../iss/$build_version/nyserver/servcfg
    cp ../../iss/cfg/nylog ../../iss/$build_version/nyserver/nylog
    cp ../../iss/cfg/run.sh ../../iss/$build_version/nyserver/run.sh
    cp ./nyserver/nyserver ../../iss/$build_version/nyserver/

    cd ../../iss/
    tar zcvf  $build_name -C $build_version/ nyserver

    rm -rf $build_version
}

cleanObj() {
    CMAKEFILES="CMakeFiles"
    CMAKECACHE="CMakeCache.txt"
    CMAKEFILE="Makefile"
    CMAKEINSTALL="cmake_install.cmake"
    if [ $OSVersion = "Ubuntu" ];then
	if [ $IsRoot = "0" ];then
	    sudo rm -rf $CMAKEFILES $CMAKECACHE $CMAKEFILE $CMAKEINSTALL
	fi 
    else
    	rm -rf $CMAKEFILES $CMAKECACHE $CMAKEFILE $CMAKEINSTALL
    fi
}

cleanCPack(){
    CPACKCONFIG="CPackConfig.cmake"
    CPACKSOURCECONFIG="CPackSourceConfig.cmake"
    CPACKINSTALLMANI="install_manifest.txt"
    CPACKSPEC="nyserver.spec"
    CPACKPACKAGE="_CPack_Packages"
    if [ $OSVersion = "Ubuntu" ];then
        if [ $IsRoot = "0" ];then
            sudo rm -rf $CPACKPACKAGE $CPACKSPEC $CPACKINSTALLMANI $CPACKSOURCECONFIG $CPACKCONFIG
        fi
    else
        rm -rf $CPACKPACKAGE $CPACKSPEC $CPACKINSTALLMANI $CPACKSOURCECONFIG $CPACKCONFIG
    fi
}

cleanMSVC(){
    MSVCIPCH="ipch"
    MSVCSDF="nyserver.sdf"
    if [ $OSVersion = "Ubuntu" ];then
        if [ $IsRoot = "0" ];then
            rm -rf $MSVCSDF $MSVCIPCH
        fi  
    else
        rm -rf $MSVCSDF $MSVCIPCH
    fi 
}

cleanSubDir() {
    if [ -d $1/$2 ]; then
        cd $1/$2
        make clean 2>/dev/null
        cleanObj
        cd - >/dev/null
    fi
}

clean() {
    cd nyutil
    make clean 2>/dev/null
    cleanObj

    cd ../filemo
    make clean 2>/dev/null
    cleanObj
    cleanSubDir ../filemo test

    cd ../netmo
    make clean 2>/dev/null
    cleanObj
    cleanSubDir ../netmo test

    cd ../sysmo
    make clean 2>/dev/null
    cleanObj
    cleanSubDir ../sysmo test

    cd ../cprotocol
    make clean 2>/dev/null
    cleanObj

    cd ../client
    make clean 2>/dev/null
    cleanObj

    cd ../hprotocol
    make clean 2>/dev/null
    cleanObj

    cd ../httpserv
    make clean 2>/dev/null
    cleanObj

    cd ../service
    make clean 2>/dev/null
    cleanObj
    cleanSubDir ../service db
    cleanSubDir ../service event
    cleanSubDir ../service observer
    cleanSubDir ../service runtime
    cleanSubDir ../service task

    cd ../nyserver
    make clean 2>/dev/null
    cleanObj
    cleanCPack
    cd $CurrentPath
    cleanMSVC
}

isRoot
checkOS
arg=`echo $1 | tr -d '-'`
case $arg in
    c|clean)
        echo "clean all build..."
        clean
        ;;
    d|debug)
        echo "build debug version..."
    	getSysVer
    	checkDepend
        clean
	build $arg
        ;;
    r|release)
        echo "build release version..."
    	getSysVer
    	checkDepend
        clean
	build $arg
        ;;
    h|help)
        print_help
        ;;
    *)
    	getSysVer
    	checkDepend
        clean
    	build debug
	clean
	build release
        ;;
esac
