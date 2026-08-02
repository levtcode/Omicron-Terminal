/* Doble de test: sandbox que no hace nada. Permite testear pty.c aislado.
 * SOLO se linkea en binarios de test; el binario omicron no puede usarlo. */
#include "omicron/sandbox.h"

#include <stdlib.h>

struct om_sandbox {
    int unused;
};

om_sandbox *om_sandbox_prepare(const om_policy *p)
{
    (void)p;
    return calloc(1, sizeof(om_sandbox));
}

int om_sandbox_apply(const om_sandbox *s)
{
    (void)s;
    return 0;
}

void om_sandbox_free(om_sandbox *s)
{
    free(s);
}
