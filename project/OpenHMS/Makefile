SUBDIRS = src \
		  test

.PHONY:all clean dist install $(SUBDIRS)

all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

install:
	@echo "waiting...."

dist:
	tar -zcvf imserver-1.0.tar.gz ./db ./doc ./src ./test ./Makefile ./README.md
