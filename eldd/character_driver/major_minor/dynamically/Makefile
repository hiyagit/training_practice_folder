obj-m := maj_dy.o
KERN_DIR = /lib/modules/$(shell uname -r)/build/

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean