/* Dueño: LevtCode. Portable: usar posix_openpt, no openpty (evita #ifdef). */
#include "omicron/pty.h"

#include "omicron/sandbox.h"

#include <errno.h>

int om_pty_spawn(char *const argv[], const om_policy *p, om_pty *t)
{
    (void)argv;
    (void)p;
    (void)t;
    /* Orden obligatorio en el hijo: cerrar fds ANTES de om_sandbox_apply. */
    errno = ENOSYS;
    return -1;
}

int om_pty_pump(om_pty *t)
{
    (void)t;
    errno = ENOSYS;
    return -1;
}

int om_pty_resize(om_pty *t, unsigned rows, unsigned cols)
{
    (void)t;
    (void)rows;
    (void)cols;
    errno = ENOSYS;
    return -1;
}

int om_pty_wait(om_pty *t, int *status)
{
    (void)t;
    (void)status;
    errno = ENOSYS;
    return -1;
}

void om_pty_kill(om_pty *t)
{
    (void)t;
}
