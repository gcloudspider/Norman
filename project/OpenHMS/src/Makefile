SUBDIRS=framework jsoncpp pugixml openhms_server

.PHONY:all clean

all:
	@for DIR in $(SUBDIRS); do		\
		make $@ -C $$DIR;			\
	done

clean:
	@for DIR in $(SUBDIRS); do		\
		make $@ -C $$DIR;			\
	done
