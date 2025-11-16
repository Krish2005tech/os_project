// #include "types.h"
// #include "user.h"

// int main(int argc, char *argv[]) {
// int r = hello();
// printf(1, "hello() returned %d\n", r);
// exit();
// }

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
    for(int i=0; i<10; i++)
        hello();
    exit();
}
