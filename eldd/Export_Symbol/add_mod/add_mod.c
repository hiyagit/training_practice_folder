#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

/*MODULE_LICENSE("GPL"); -> tells that module bears free license*/
MODULE_LICENSE("Dual BSD/GPL");
/*-> tells the name of author*/
MODULE_AUTHOR("Hiya");

static int add_a = 0;
static int add_b = 0;

/*this is a addition function that we are going to export as symbol*/
static int add_fun(int a, int b)
{
        return (a+b);
}

/*Command to export symbol into kernel symbol table*/
EXPORT_SYMBOL(add_fun);



/* module_param takes three arguments: var name, type of variable, permission*/
module_param(add_a,int,S_IRUGO);
module_param(add_b,int,S_IRUGO);

/*to initialise this module and load it into kernel symbol table*/
static int __init hello_init(void)
{
	printk(KERN_ALERT "Hello to all\n");
	printk(KERN_ALERT "Addition result: %d\n",add_fun(add_a,add_b)) ;
	return 0;
}


/*to remove module from kernel symbol table*/
static void __exit hello_exit(void)
{
	printk(KERN_ALERT"Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);
