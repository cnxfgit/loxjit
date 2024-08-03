#ifndef clox_jit_h
#define clox_jit_h

#include "object.h"

typedef struct dasm_State dasm_State;

#define Dst vm.J
#define Dst_DECL JitState *J
#define Dst_REF (J->D)


typedef struct {
    dasm_State *D;
    void ** jgbl;
    ObjClosure *closure;
    Value value;
    Value valTrue;
    Value valFalse;
} JitState;

void *jitCompile(ObjClosure *closure);

void freeJitCode(void *code);

#endif