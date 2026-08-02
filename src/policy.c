/* Dueño: axel. Portable: no toca APIs de sandbox. */
#include "omicron/policy.h"

#include <errno.h>
#include <stdlib.h>

om_policy *om_policy_default(void)
{
    errno = ENOSYS;
    return NULL;
}

int om_policy_add_ro(om_policy *p, const char *path)
{
    (void)p;
    (void)path;
    errno = ENOSYS;
    return -1;
}

int om_policy_add_rw(om_policy *p, const char *path)
{
    (void)p;
    (void)path;
    errno = ENOSYS;
    return -1;
}

int om_policy_parse_args(om_policy *p, int argc, char **argv, int *cmd_index)
{
    (void)p;
    (void)argc;
    (void)argv;
    (void)cmd_index;
    errno = ENOSYS;
    return -1;
}

int om_policy_validate(om_policy *p)
{
    (void)p;
    errno = ENOSYS;
    return -1;
}

void om_policy_free(om_policy *p)
{
    (void)p;
}
