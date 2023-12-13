obj-m = plus1.o

KDIR := /home/psofcake/WSL2-Linux-Kernel-linux-msft-wsl-5.15.133.1 
PWD := $(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.kr *.mod.* .*.cmd *.o *.ko
