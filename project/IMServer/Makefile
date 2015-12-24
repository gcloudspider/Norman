SUBDIRS = src test

.PHONY:all clean dist

all clean:
	cd $(SUBDIRS) && $(MAKE) $@

dist:
	tar -zcvf imserver-1.0.tar.gz ./db ./doc ./src ./test ./Makefile ./README.md
