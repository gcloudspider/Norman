SUBDIRS=binsort binsort1 binsort2 equivClass equivNode chain circular

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

