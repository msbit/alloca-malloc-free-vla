#!/usr/bin/env bash

CFLAGS="-O0"

rm main.alloca main.malloc-free main.vla

gcc ${CFLAGS} -DUSE_ALLOCA -o main.alloca main.c
gcc ${CFLAGS} -DUSE_MALLOC_FREE -o main.malloc-free main.c
gcc ${CFLAGS} -DUSE_VLA -o main.vla main.c
