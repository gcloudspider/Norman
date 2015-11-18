#!/bin/sh
#############################################################
#Create Date:2015-11-13
#Author:Norman
#Descript: Git code to Github
##
#
#
#
#############################################################

#1.clean up code
#2.Merge code
#3.code review

CURRPATH=`pwd`

echo "Realdy to push code to Github....."

echo "Checking Coding......"

echo "Add Code to Local git  repository"

sudo git add --all .

sudo git commit -a -m "clean up code"

sudo git push
