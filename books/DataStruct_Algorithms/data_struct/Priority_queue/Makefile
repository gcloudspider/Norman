SUBDIRS= huffmanTree \
		heapSort \
		lptSchedule \
		maxHblt \
		maxHeap

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

