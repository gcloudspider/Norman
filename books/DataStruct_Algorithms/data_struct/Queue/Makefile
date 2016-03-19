SUBDIRS=arrayQueue \
		linkedQueue \
		railroadWithQueue \
		railroadWithNoQueue \
		wireRouter

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

