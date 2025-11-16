#include "types.h"
#include "stat.h"
#include "user.h"

void test_is_proc_valid(){
    // Test is_proc_valid
    int pid = getpid(); 
    int valid1 = isprocvalid(1);
    int valid2 = isprocvalid(2);
    int valid3 = isprocvalid(pid);
    int valid4 = isprocvalid(10000);
    
    printf(1,"\n_______TESTING is_proc_valid(pid)_______\n");
    printf(1, "isprocvalid(%d): %d\n", 1, valid1);
    printf(1, "isprocvalid(%d): %d\n", 2, valid2);
    printf(1, "isprocvalid(%d): %d\n", pid, valid3);
    printf(1, "isprocvalid(%d): %d\n", 10000, valid4);
}
int main()
{
    test_is_proc_valid();
    exit();
}