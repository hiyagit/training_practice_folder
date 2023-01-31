#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/types.h>

dev_t dev = MKDEV(100, 0);

static int __init maj_st_start(void)
{
    register_chrdev_region(dev, 1, "device2");
    printk(KERN_INFO "Major number: %d  Minor number: %d\n", MAJOR(dev), MINOR(dev));
    printk(KERN_INFO "Kernel module inserted successfully..!!\n");
    return 0;
}

static void __exit maj_st_end(void)
{
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO " Kernel module removed successfully..!!\n");
}

module_init(maj_st_start);
module_exit(maj_st_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hiya");
MODULE_DESCRIPTION("Statically allocation of Major and Minor number");