SUBDIRS = src test

.PHONY:all clean disct
	
all clean:
	cd $(SUBDIRS) && $(MAKE) $@

disct:
	tar -zcvf managesystem.1.0-tar.gz ./db ./doc ./src ./test ./Makefile ./README.md
