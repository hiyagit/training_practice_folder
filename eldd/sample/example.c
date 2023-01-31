#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/cdev.h>

dev_t dev = 0;
static struct cdev file_cdev;
static int file_open(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *filp, char __user *buff, size_t len, loff_t *off);
static ssize_t file_write(struct file *filp, const char __user *buff, size_t len, loff_t *off);
static int file_release(struct inode *inode, struct file *file);
static struct file_operations file_fops = {
    .owner = THIS_MODULE,
    .open = file_open,
    .read = file_read,
    .write = file_write,
    .release = file_release,
};

static int file_open(struct inode *inode, struct file *file)
{
    printk("\n\nDriver open function called..\n");
    return 0;
}
static ssize_t file_read(struct file *filp, char __user *buff, size_t len, loff_t *off)
{
    printk("\n\nDriver read function called..\n");
    return 0;
}
static ssize_t file_write(struct file *filp, const char __user *buff, size_t len, loff_t *off)
{
    printk("\n\nDriver write function called..\n");
    return 0;
}
static int file_release(struct inode *inode, struct file *file)
{
    printk("\n\nDriver release function called..\n");
    return 0;
}
static int __init file_init(void)
{
    alloc_chrdev_region(&dev, 0, 1, "sample_file");
    printk("\n\nMajor number: %d    Minor number: %d\n",MAJOR(dev),MINOR(dev));
    cdev_init(&file_cdev,&file_fops);
    cdev_add(&file_cdev, dev, 1);

    return 0;
}
static void __exit file_exit(void)
{  
    cdev_del(&file_cdev);
    unregister_chrdev_region(&dev, 1);
    printk("\n\nDevice driver removed successfully..\n");
}

module_init(file_init);
module_exit(file_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hiya");