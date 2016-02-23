SUBDIRS=Vector\
		List \
		Matrix \
		Stack \
		Queue \
		Skiplist_Hash

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

