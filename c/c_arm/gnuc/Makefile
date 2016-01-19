SUBDIRS = beep \
		  c_ledall_spark\
		  c_led_spark\
		  encapsulation\
		  key

.PHONY:all clean dist $(SUBDIRS)

all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)


dist:
	tar -zcvf gnuc.tar.gz $(SUBDIRS) ./Makefile ./README.md
