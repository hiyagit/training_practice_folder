#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"add.h"

/*MODULE_LICENSE("GPL"); -> tells that module bears free license*/
MODULE_LICENSE("Dual BSD/GPL");
/*-> tells the name of author*/
MODULE_AUTHOR("Hiya");


static int avd_a=4;
static int avd_b=5;

module_param(avd_a,int,S_IRUGO);
module_param(avd_b,int,S_IRUGO);

	int avg_fun(int x, int y)
{
	int num = 0;
	num = add_fun(x, y);
	return (num/2);
}

/*to initialise this module and load it into kernel symbol table*/
static int __init hello_start(void)
{



	printk(KERN_ALERT "Hello to all\n");
	printk(KERN_ALERT "Average result: %d\n", avg_fun(avd_a, avd_b));
	return 0;
}

/*to remove module from kernel symbol table*/
static void __exit hello_end(void)
{
	printk(KERN_ALERT"Goodbye\n");
}

module_init(hello_start);
module_exit(hello_end);