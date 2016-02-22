SUBDIRS=Vector\
		List \
		Matrix \
		Stack \
		Queue

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

