/* Frontera de seguridad. Una firma, dos implementaciones (darwin / linux).
 * Nada fuera de estos tres símbolos sabe qué mecanismo de kernel se usa. */
#ifndef OMICRON_SANDBOX_H
#define OMICRON_SANDBOX_H

#ifndef OM_POLICY_FWD
#define OM_POLICY_FWD
typedef struct om_policy om_policy;
#endif

/* Opaco: cada plataforma define su propio contenido en su .c */
typedef struct om_sandbox om_sandbox;

/* Corre en el PADRE, antes del fork. Puede reservar memoria. NULL si falla. */
om_sandbox *om_sandbox_prepare(const om_policy *p);

/* Corre en el HIJO, entre fork y exec. Irreversible. Sin malloc.
 * 0 ok, -1 error: el hijo debe hacer _exit(OM_EXIT_SANDBOX). */
int om_sandbox_apply(const om_sandbox *s);

void om_sandbox_free(om_sandbox *s);

#endif /* OMICRON_SANDBOX_H */
