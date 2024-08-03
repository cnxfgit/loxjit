DASM= luajit $(DASMDIR)/dynasm.lua
DASMDIR= ./dynasm
DASMDISTFLAGS= -LN

.PHONY: jit_x64.h lox

default: jit_x64.h lox

jit_x64.h: jit_x64.dasc
	$(DASM) $(DASMDISTFLAGS) -o jit_x64.h jit_x64.dasc

lox: chunk.h chunk.c common.h compiler.h compiler.c debug.h debug.c main.c jit.h jit.c \
		memory.h memory.c object.h object.c scanner.h scanner.c table.h table.c value.h value.c vm.h vm.c
	gcc -g $^ -o lox -O0
	