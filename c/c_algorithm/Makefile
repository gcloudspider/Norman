SUBDIRS=Common_algorithms\
		distSort\
		fileDestory\
		bubblesort

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

