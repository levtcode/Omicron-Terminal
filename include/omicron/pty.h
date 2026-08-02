/* PTY: crea el par master/slave, lanza el hijo ya aislado y bombea E/S. */
#ifndef OMICRON_PTY_H
#define OMICRON_PTY_H

#include <sys/types.h>

#ifndef OM_POLICY_FWD
#define OM_POLICY_FWD
typedef struct om_policy om_policy;
#endif

/* Códigos de salida reservados del hijo: distinguen "no se ejecutó" de "falló". */
#define OM_EXIT_SANDBOX 127 /* el sandbox no se pudo aplicar; nunca hubo exec */
#define OM_EXIT_EXEC    126 /* el sandbox se aplicó pero el exec falló */

typedef struct {
    int   master_fd;
    pid_t pid;
} om_pty;

/* fork + setsid + TIOCSCTTY + cerrar fds + om_sandbox_apply + execvp. */
int om_pty_spawn(char *const argv[], const om_policy *p, om_pty *t);

/* Bombea entre la terminal real y master_fd hasta que el hijo termine. */
int om_pty_pump(om_pty *t);

int  om_pty_resize(om_pty *t, unsigned rows, unsigned cols);
int  om_pty_wait(om_pty *t, int *status);
void om_pty_kill(om_pty *t);

#endif /* OMICRON_PTY_H */
