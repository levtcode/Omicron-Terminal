/* Dueño: axel. Sin fork ni privilegios: corre en las dos plataformas. */
#include "omicron/policy.h"

int main(void)
{
    /* TODO: realpath desenmascara "/tmp/../home" -> om_policy_validate == -1 */
    return 77; /* borrar esta línea al implementar (77 = SKIP en ctest) */
}
