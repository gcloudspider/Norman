SUBDIRS = src \
		  test

.PHONY:all clean dist $(SUBDIRS)

all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)


dist:
	tar -zcvf CountWord-1.0.tar.gz ./db ./doc ./src ./test ./Makefile ./README.md
