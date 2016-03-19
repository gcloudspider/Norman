SUBDIRS=arrayStack\
		derivedArrayStack \
		derivedArrayStackWithCatch \
		derivedLinkedStack \
		hanoiRecursive \
		hanoiUsingStacks \
		linkedStack \
		printMatchedPairs\
		railroadWithStacks \
		switchBox \
		equivalenceClasses

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

