ifeq ($(KERNELRELEASE),)
KERNELDIR ?=/root/桌面/kernel/linux-2.6.38.mini2440.wei
PWD :=$(shell pwd)

all:modules

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) $@
#make -C /root/桌面/kernel/linux-2.6.38.mini2440.wei/ M=./ modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) $@

else 
	obj-m := we2000.o
endif
