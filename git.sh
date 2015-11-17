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

CURRPATH=`pwd`

echo "Realdy to push code to Github....."

echo "Checking Coding......"

echo "Add Code to Local git  repository"

sudo git add --all .

sudo git commit -a -m "Merge code"

sudo git push
