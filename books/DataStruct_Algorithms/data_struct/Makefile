SUBDIRS=Vector\
		List \
		Matrix \
		Stack \
		Queue \
		Skiplist_Hash \
		Tree

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

