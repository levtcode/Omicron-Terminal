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

/* Ojo al implementar: sandbox_init() está marcada deprecada desde macOS 10.8 y
 * con -Werror el build falla por -Wdeprecated-declarations. Sigue siendo la API
 * viva de Seatbelt, así que NO apagar OMICRON_WERROR: envolver solo la llamada.
 *     #pragma clang diagnostic push
 *     #pragma clang diagnostic ignored "-Wdeprecated-declarations"
 *     rc = sandbox_init(s->profile, 0, &err);
 *     #pragma clang diagnostic pop
 */
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
