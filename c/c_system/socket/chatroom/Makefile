SUBDIRS = src\
		  client\
		  test

.PHONY:all clean dist $(SUBDIRS)

all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)


dist:
	tar -zcvf chatserver-1.0.tar.gz ./db ./src ./conf ./Makefile ./include
