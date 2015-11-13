#!/bin/sh         
#FileName:delete.sh      
#Version:V0.1         
#Author:Norman        
#Date:2015-11-13 

CURRPATH=`pwd`

#需要排除删除的文件后缀
EXCUSESUFFIX='.h .cpp .c .sh .md .txt'

cd $CURRPATH 2>/dev/null

if [ $? -ne 0 ];
then
	echo "Not Find This Dir!"
	exit 1
fi

echo "Are you Realdy Delete $CURRPATH Dir temp file.... "

filelist=`ls 2>/dev/null`
#echo "Current List Info:$filelist"
for file in $filelist
	do
		echo "Loading ${file}......"
		if [ -d $file ];
		then
			echo "Checking $file Dir"
			echo "Dir $file cleaning......"
		else
			echo "checking $file in excuseSuffix list"
		fi
done
