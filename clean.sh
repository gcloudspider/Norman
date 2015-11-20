#!/bin/sh         
#FileName:delete.sh      
#Version:V0.1         
#Author:Norman        
#Date:2015-11-13 

CURRPATH=`pwd`

#需要排除删除的文件后缀
EXCLUDESUFFIX='*.h *.cpp *.c *.sh *.md *.txt *.dia'

cd $CURRPATH 2>/dev/null

if [ $? -ne 0 ];
then
	echo "Not Find This Dir!"
	exit 1
fi

echo "Are you Realdy Delete $CURRPATH Dir temp file.... "
getFileList() {
	filelist=`ls 2>/dev/null`
}

putFileList() {
	for file in $filelist
		do
			echo $CURRPATH
			isDir "$file"
		done
}

isFileInExclude() {
	for suffix in $EXCLUDESUFFIX
		do
			echo $suffix $1
		done
}

isDir() {
	if [ -d "$1" ];
	then
		echo "$1 is Dir...."
		getFileList $1
		putFileList
	else 
		echo "$1 is file...."
		#isFileInExclude ${file##*.}
	fi
}

#get "Current List Info:$filelist"
getFileList $CURRPATH

putFileList

