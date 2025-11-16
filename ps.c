#include "types.h"
#include "stat.h"
#include "user.h"

#define MAXPID 64
#define NAMELEN 16
#define STATELEN 16

int
main(int argc, char *argv[])
{
    int e_flag = 0;

    // Check for -e flag
    if (argc > 1 && strcmp(argv[1], "-e") == 0) {
        e_flag = 1;
    }

    // Set name of this process to "ps"
    fill_proc_name(getpid(), "ps");

    if (!e_flag) {
        printf(1, "PID      NAME      STATE      SYS      INT\n");

        int pid = getpid();

        // buffers
        char statebuf[STATELEN];
        char namebuf[NAMELEN];

        // get fields
        get_proc_name(pid, namebuf, NAMELEN);
        get_proc_state(pid, statebuf, STATELEN);
        int sys = get_num_syscall(pid);
        int tint = get_num_timer_interrupts(pid);

        printf(1, "%d      %s      %s      %d      %d\n",
               pid, namebuf, statebuf, sys, tint);
    }
    else {
        printf(1, "PID      STATE      SYS      INT\n");

        // iterate over all possible PIDs 1..64
        for (int pid = 1; pid <= MAXPID; pid++) {

            if (!isprocvalid(pid))
                continue;

            char statebuf[STATELEN];
            get_proc_state(pid, statebuf, STATELEN);

            int sys = get_num_syscall(pid);
            int tint = get_num_timer_interrupts(pid);

            printf(1, "%d      %s      %d      %d\n",
                   pid, statebuf, sys, tint);
        }
    }

    exit();
}
