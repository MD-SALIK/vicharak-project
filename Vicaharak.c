#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/wait.h>
#include<linux/sched.h>
#include<linux/slab.h>

#define DEVICE_NAME"md_salik_alim"

static int__init vicharak_init(void){
    printk(KERN_INFO "Initializing the vicharak module\n");
    return 0;
}

static void_exit vicharak_exit(void){
    printk(KERN_INFO "Exiting the vicharak module\n");

}

module_init(vicharak_init);
module_exit(vicharak_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MD SALIK ALIM");
MODULE_DESCRIPTION("Dynamic circular queue device driver");
