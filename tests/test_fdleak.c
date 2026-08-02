/* Protege la costura pty <-> sandbox: un fd heredado atraviesa el sandbox
 * entero, porque Landlock y Seatbelt restringen abrir rutas, no fds ya abiertos.
 * El hijo se autoinspecciona con fcntl(fd, F_GETFD) de 3 a 255. */
#include "omicron/pty.h"

int main(void)
{
    /* TODO: spawn y exigir status 0 = solo 0, 1 y 2 abiertos en el hijo */
    return 77; /* borrar esta línea al implementar (77 = SKIP en ctest) */
}
