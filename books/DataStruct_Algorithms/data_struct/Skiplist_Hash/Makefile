SUBDIRS=sortedChain\
		skipList \
		threeToLong \
		stringToInt \
		hashTable \
		hashChains \
		compress \
		decompress

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

