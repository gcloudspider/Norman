#!/bin/bash
#/usr/local/bin/inotifywait -qmcre attrib,modify,move,create,delete $WAIT_DIR  \
WAIT_DIR="/var/www"
/usr/local/bin/inotifywait -qmre attrib,modify,move,create,delete $WAIT_DIR --format '"%w" "%f" "%e" "%T"' --timefmt='%F_%T' \
            | while read DIR FILE EVENT TIME ;do

        echo $DIR $FILE $EVENT $TIME
done
