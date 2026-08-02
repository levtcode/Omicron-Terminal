/* Dueño: axel. Seatbelt: generar perfil SBPL en prepare, sandbox_init en apply. */
#include "omicron/sandbox.h"

#include "omicron/policy.h"

#include <errno.h>
#include <stdlib.h>

struct om_sandbox {
    char *profile; /* texto SBPL, construido antes del fork */
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
