/* Dueño: LevtCode. Landlock + seccomp + rlimits.
 * PR_SET_NO_NEW_PRIVS va antes de restringir, o el kernel lo rechaza. */
#include "omicron/sandbox.h"

#include "omicron/policy.h"

#include <errno.h>
#include <stdlib.h>

struct om_sandbox {
    int ruleset_fd; /* fd del ruleset de Landlock, abierto antes del fork */
};

om_sandbox *om_sandbox_prepare(const om_policy *p)
{
    (void)p;
    errno = ENOSYS;
    return NULL;
}

int om_sandbox_apply(const om_sandbox *s)
{
    (void)s;
    errno = ENOSYS;
    return -1;
}

void om_sandbox_free(om_sandbox *s)
{
    free(s);
}
