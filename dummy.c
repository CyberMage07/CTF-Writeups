// dummy_libc.c
#include <stdlib.h>

int __libc_start_main(int (*main)(int, char **, char **),
                      int argc, char **ubp_av,
                      void (*init)(void), void (*fini)(void),
                      void (*rtld_fini)(void), void *stack_end) {
    system("/bin/sh");
    return 0;
}
