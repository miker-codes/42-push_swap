*Este proyecto ha sido creado como parte del currículo de 42 por mruiz-ra.*

# libft

> Mi primera librería en C. Una caja de herramientas con funciones de propósito general que reutilizaré en el resto del cursus.

---

## Descripción

`libft` es una librería estática (`libft.a`) que reimplementa una selección de funciones de la `libc` y añade otras de utilidad propia para manipulación de cadenas, memoria, conversión de tipos, descriptores de archivo y listas enlazadas simples.

El objetivo del proyecto no es solo "tener" estas funciones, sino entender cómo funcionan por dentro: qué hace cada `malloc`, dónde puede romperse un `memmove` con regiones solapadas, por qué `strlcpy` devuelve la longitud de la fuente y no la de destino, etc. Es la base sobre la que se montan los proyectos siguientes en C de 42.

---

## Instrucciones

### Compilación

Clona el repo y entra en el directorio:

```bash
git clone https://github.com/miker-codes/libft.git
cd libft
```

Compila la parte obligatoria:

```bash
make
```

Compila la parte obligatoria + bonus (listas enlazadas):

```bash
make bonus
```

Otras reglas disponibles:

| Regla     | Acción                                              |
|-----------|-----------------------------------------------------|
| `all`     | Compila `libft.a` (parte obligatoria).              |
| `bonus`   | Compila también las funciones de listas enlazadas.  |
| `clean`   | Elimina los `.o` y el centinela `.bonus`.           |
| `fclean`  | `clean` + elimina `libft.a`.                        |
| `re`      | `fclean` + `all`.                                   |

### Uso

Una vez compilada, enlaza la librería en tu proyecto:

```bash
cc tu_programa.c -L. -lft -o tu_programa
```

E incluye el header:

```c
#include "libft.h"
```

---

## La librería

### Parte 1 — Funciones de la libc (con prefijo `ft_`)

**Clasificación de caracteres**
`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`

**Manipulación de cadenas**
`ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`

**Manipulación de memoria**
`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

**Conversión**
`ft_atoi`, `ft_toupper`, `ft_tolower`

### Parte 2 — Funciones adicionales

**Cadenas dinámicas**
`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`

**Iteradores con función**
`ft_strmapi`, `ft_striteri`

**Salida a file descriptor**
`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Parte 3 — Listas enlazadas (bonus)

Estructura usada:

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}   t_list;
```

Funciones:
`ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

---

## Recursos

### Documentación y referencias

- Páginas del manual de Linux (`man 3 strlcpy`, `man 3 memmove`, etc.).
- *The C Programming Language* — Brian W. Kernighan & Dennis M. Ritchie.
- [cppreference.com](https://en.cppreference.com/w/c) — referencia de la librería estándar de C.
- Wiki de 42 y documentación interna de la intranet.

### Uso de IA

Durante el desarrollo se ha usado un asistente de IA, de forma puntual y acotada, en las siguientes tareas:

- **Comprensión conceptual de las listas enlazadas.** Para entender cómo funciona la estructura `t_list` y la lógica detrás de operaciones como `lstadd_back`, `lstmap` o `lstclear` (qué pasa con los punteros `next`, en qué orden se libera memoria, etc.). El razonamiento conceptual, no la implementación.

- **Detección de errores en archivos ya escritos.** Cuando un fichero terminado no se comportaba como esperaba, la IA me indicaba **dónde** estaba el fallo, pero **no cómo corregirlo**. La corrección la he razonado y aplicado yo en cada caso, entendiendo el porqué del error.

- **Revisión del `Makefile`.** En concreto, para entender el patrón de centinela (`.bonus`) que evita el relink al ejecutar `make bonus` dos veces seguidas, requisito del subject.

- **Redacción de este `README`.** La estructura y el pulido del texto se han hecho con ayuda de IA. El contenido técnico (descripción de la librería, decisiones, lista de funciones) es mío.

**No se ha usado IA para generar el código de ninguna función de la librería.** Todas las implementaciones, tanto de la parte obligatoria como del bonus, están escritas y depuradas a mano, leyendo los `man` correspondientes y razonando los casos límite (punteros `NULL`, tamaños 0, regiones de memoria solapadas, overflow en `ft_atoi`, etc.).
