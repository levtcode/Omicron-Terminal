/* Dueño: LevtCode. Portable: usar posix_openpt, no openpty (evita #ifdef). */

#include "omicron/pty.h"
#include "omicron/sandbox.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int om_pty_spawn(char *const argv[], const om_policy *pol, om_pty *pty)
{
    (void)argv;
    (void)pol;
    (void)pty;
    /* Orden obligatorio en el hijo: cerrar fds ANTES de om_sandbox_apply. */
    errno = ENOSYS;
    return -1;

    // Hay que corregir muchas cosas, de momento, hacemos que la ejecución llegue hasta aquí
    // y termine de forma segura.
    char *slave_name;

    pty->master_fd = posix_openpt(O_RDWR | O_NOCTTY);
    if (pty->master_fd == -1) {
        perror("Error in posix_openpt");
        return EXIT_FAILURE;
    }

    if (grantpt(pty->master_fd) == -1) {
        perror("Error in grantpt");
        close(pty->master_fd);
        return EXIT_FAILURE;
    }

    if (unlockpt(pty->master_fd) == -1) {
        perror("Error in unlockpt");
        close(pty->master_fd);
        return EXIT_FAILURE;
    }

    slave_name = ptsname(pty->master_fd);
    if (slave_name == NULL) {
        perror("Error in ptsname");
        close(pty->master_fd);
        return EXIT_FAILURE;
    }
}

int om_pty_pump(om_pty *pty)
{
    (void)pty;
    errno = ENOSYS;
    return -1;
}

int om_pty_resize(om_pty *pty, unsigned rows, unsigned cols)
{
    (void)pty;
    (void)rows;
    (void)cols;
    errno = ENOSYS;
    return -1;
}

int om_pty_wait(om_pty *pty, int *status)
{
    (void)pty;
    (void)status;
    errno = ENOSYS;
    return -1;
}

void om_pty_kill(om_pty *pty)
{
    (void)pty;
}
