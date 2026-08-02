# Omicron

Terminal Unix con sandbox: el proceso hijo se lanza con capacidades reducidas
por el kernel, no filtrando el texto del comando.

## Build

```
make        # compila
make test   # compila y corre los tests
make run ARGS="--allow-rw /tmp -- /bin/sh"
```

Requiere CMake >= 3.20 y un compilador C11. macOS y Linux.

## Estructura

```
include/omicron/   contrato: policy.h, sandbox.h, pty.h
src/               implementación (un sandbox por plataforma)
tests/             ctest
docs/adr/          decisiones arquitectónicas
```

## Reparto

| Archivo | Dueño |
|---|---|
| `src/main.c`, `src/policy.c`, `src/sandbox_darwin.c` | axel |
| `src/pty.c`, `src/sandbox_linux.c` | LevtCode |
| `include/`, `CMakeLists.txt` | compartidos: PR aprobado por ambos |
| `tests/test_*.c` | el dueño del módulo |

## Meta v1

```
omicron --allow-ro /usr --allow-rw /tmp -- /bin/sh
```

Adentro: `ls /tmp` funciona, `cat ~/.ssh/id_rsa` da `EPERM`.
