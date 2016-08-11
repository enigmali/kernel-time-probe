#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/hrtimer.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Enigma Li <lizhilong.enigma@gmail.com>");
MODULE_DESCRIPTION("Kernel Timer Probe.");

#include <linux/hrtimer.h>

ktime_t __probe_start;
ktime_t __probe_end;

static int time_measure_start(void)
{
	__probe_start = ktime_get();
	printk(">>> @START: %lld.\n", __probe_start.tv64);
	return 0;
}
EXPORT_SYMBOL(time_measure_start);

static int time_measure_end(void)
{
	__probe_end = ktime_get();
	printk(">>> @END: %lld.\n", __probe_end.tv64);
	return 0;
}
EXPORT_SYMBOL(time_measure_end);

static int __init __ib_probe_init(void)
{
    printk(KERN_INFO ">>> Mod ib_probe loaded!\n");
    return 0;
}
 
static void __exit __ib_probe_exit(void)
{
    printk(KERN_INFO ">>> Mod ib_probe exit!\n");
}
 
module_init(__ib_probe_init);
module_exit(__ib_probe_exit);
