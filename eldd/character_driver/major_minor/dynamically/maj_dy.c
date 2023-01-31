#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

dev_t dev = 0;

static int __init maj_dy_start(void)
{
    /*Allocating Major and minor number*/
    alloc_chrdev_region(&dev, 0, 1, "device1");
    printk(KERN_INFO "Major number: %d   Minor number: %d\n", MAJOR(dev), MINOR(dev));
    printk(KERN_INFO "Kernel module inserted successfully..!!\n");
    return 0;
}

static void __exit maj_dy_end(void)
{
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO "Kernel module removed successfully..!!\n");
}

module_init(maj_dy_start);
module_exit(maj_dy_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hiya");
MODULE_DESCRIPTION("Dynamically allocating the Major and Minor number");