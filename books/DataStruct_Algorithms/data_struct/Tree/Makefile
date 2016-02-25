SUBDIRS=binaryTree\
		infix \
		linkedBinaryTree \
		booster

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

