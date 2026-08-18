/* Política del sandbox: describe qué se le permite al proceso aislado.
 * Son datos puros. No llama al kernel ni protege nada por sí sola:
 * la traducen sandbox_darwin.c (Seatbelt) y sandbox_linux.c (Landlock). */
#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <sys/resource.h>

typedef struct om_policy om_policy;

struct om_policy {
    char **ro_paths;   /* rutas de solo lectura */
    size_t ro_count;
    char **rw_paths;   /* rutas de lectura y escritura */
    size_t rw_count;
    bool   allow_net;
    rlim_t max_procs;
    rlim_t max_mem;    /* bytes */
};

/* Política mínima razonable. NULL si falta memoria. */
om_policy *om_policy_default(void);

/* Agregan una ruta. 0 ok, -1 error (errno). La ruta se copia. */
int om_policy_add_ro(om_policy *p, const char *path);
int om_policy_add_rw(om_policy *p, const char *path);

/* Parsea flags hasta "--". Deja en *cmd_index el índice del comando en argv. */
int om_policy_parse_args(om_policy *p, int argc, char **argv, int *cmd_index);

/* Canonicaliza con realpath y rechaza lo inseguro. 0 ok, -1 rechazada. */
int om_policy_validate(om_policy *p);

void om_policy_free(om_policy *p);
