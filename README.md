# `alloca` vs `malloc`/`free` vs `VLA`

Allocate a dynamic amount of memory, using each of:

* `alloca`
* `malloc` (followed by `free`)
* compiler implemented `VLA`

## `alloca`

```
int *values = (int *)alloca(sizeof(int) * count);
```

Operates by manipulating the stack pointer to give the appropriate amount of space. As this memory is "allocated" in the same fashion as normal non-dynamic variables, it is also "freed" in the same way.

## `malloc` (followed by `free`)

```
int *values = (int *)malloc(sizeof(int) * count);
```

Requests the C library to allocate some memory on the heap, outside of the stack. Thus, the subsequent call to `free` is required to cause the allocated memory to be freed.

## compiler implemented `VLA`

```
int values[count];
```

Rely on the compiler to dynamically allocate the memory. This operates in a very similar way to `alloca`, manipulating the stack pointer.
