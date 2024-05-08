#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("test");

static int devnode_dev_const_init(void)
{
	return 0;
}

static void devnode_dev_const_exit(void)
{
}

module_init(devnode_dev_const_init);
module_exit(devnode_dev_const_exit);
