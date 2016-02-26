SUBDIRS=auto \
		const \
		decltype \
		for \
		namespace \
		nullptr \
		referred \
		regular \
		string \
		template \
		varInit \
	

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

