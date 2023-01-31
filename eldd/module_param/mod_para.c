#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

/*MODULE_LICENSE("GPL"); -> tells that module bears free license*/
MODULE_LICENSE("Dual BSD/GPL");
/*-> tells the name of author*/
MODULE_AUTHOR("Hiya");

/*variables are declared as static to keep their scope local to this module and to avoid namespace pollution*/
static char* charvar = "parameter";
static int intvar = 12;

/*using the following macro, variables are enabled to be modified from command line
 * module_param takes three arguments: var name, type of variable, permission*/
module_param(charvar,charp,S_IRUGO);
module_param(intvar,int,S_IRUGO);

static int __init param_init(void)
{
	printk(KERN_ALERT "We are in init function\n");
	printk(KERN_ALERT "The value of charvar is %s\n",charvar);
	printk(KERN_ALERT "The value of intvar is %d\n",intvar);
	return 0;
}

static void __exit param_exit(void)
{
	printk(KERN_ALERT "Goodbye\n");
}

module_init(param_init);
module_exit(param_exit);

