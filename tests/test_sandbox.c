/* Linkea el sandbox REAL de la plataforma. Mismas aserciones en macOS y Linux;
 * si algún día divergen, el contrato de sandbox.h está mal. */
#include "omicron/policy.h"
#include "omicron/sandbox.h"

int main(void)
{
    /* TODO: abrir una ruta fuera de la policy debe fallar con EPERM */
    return 77; /* borrar esta línea al implementar (77 = SKIP en ctest) */
}
