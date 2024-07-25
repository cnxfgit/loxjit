/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "jit_x64.dasc".
*/

#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif

#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1

// 调用者保存寄存器：RAX, RDI, RSI, RDX, RCX, R8-R11。
// 被调用者保存寄存器：RBP, RBX, R12-R15。
#define Dt1(_V) (int)(ptrdiff_t)&(((VM *)0)_V)
#define Dt2(_V) (int)(ptrdiff_t)&(((Value *)0)_V)
#define Dt3(_V) (int)(ptrdiff_t)&(((CallFrame *)0)_V)
#define Dt4(_V) (int)(ptrdiff_t)&(((JitState *)0)_V)
#define Dt5(_V) (int)(ptrdiff_t)&(((ObjClosure *)0)_V)
 

#define Dt6(_V) (int)(ptrdiff_t)&(((Value *)0)_V)
#define Dt7(_V) (int)(ptrdiff_t)&(((CallFrame *)0)_V)
#define Dt8(_V) (int)(ptrdiff_t)&(((Obj *)0)_V)
#define Dt9(_V) (int)(ptrdiff_t)&(((ObjFunction *)0)_V)
#define DtA(_V) (int)(ptrdiff_t)&(((ObjNative *)0)_V)
#define DtB(_V) (int)(ptrdiff_t)&(((ObjString *)0)_V)
#define DtC(_V) (int)(ptrdiff_t)&(((ObjUpvalue *)0)_V)
#define DtD(_V) (int)(ptrdiff_t)&(((ObjClosure *)0)_V)
#define DtE(_V) (int)(ptrdiff_t)&(((ObjClass *)0)_V)
#define DtF(_V) (int)(ptrdiff_t)&(((ObjInstance *)0)_V)
#define Dt10(_V) (int)(ptrdiff_t)&(((ObjBoundMethod *)0)_V)
#define Dt11(_V) (int)(ptrdiff_t)&(((Table *)0)_V)
#define Dt12(_V) (int)(ptrdiff_t)&(((Entry *)0)_V)





static const unsigned char actionList[105] = {
  250,15,248,10,85,72,137,229,80,83,65,84,65,85,65,86,65,87,73,137,252,252,
  73,191,237,237,77,139,175,233,255,250,15,72,191,237,237,72,184,237,237,252,
  255,208,255,250,15,72,184,237,237,252,255,208,72,137,199,72,184,237,237,252,
  255,208,72,199,199,237,72,184,237,237,252,255,208,255,72,184,237,237,252,
  255,208,65,139,135,233,131,232,1,248,1,91,88,65,95,65,94,65,93,65,92,93,195,
  255
};

enum {
  jitGlobal_main,
  jitGlobal__MAX
};

const char loxJIT_arch[] = "x64";

// 要保证栈对齐 16字节 即除rbp外，push reg要成对出现，否则会造成Segmentation fault (core dumped)
static void preCall(Dst_DECL) {
    dasm_put(Dst, 0, (unsigned int)((ptrdiff_t)&vm), (unsigned int)(((ptrdiff_t)&vm)>>32), Dt1(->frames));
}

static void jitOpConstant(dasm_State *state, ObjClosure *closure, size_t* i) {
    Value constant = closure->function->chunk.constants.values[*i];
    (*i)++;
    dasm_put(Dst, 31, (unsigned int)((ptrdiff_t)constant), (unsigned int)(((ptrdiff_t)constant)>>32), (unsigned int)((ptrdiff_t)push), (unsigned int)(((ptrdiff_t)push)>>32));
}

static void jitOpNil(dasm_State *state) {
    dasm_put(Dst, 31, (unsigned int)((ptrdiff_t)NIL_VAL), (unsigned int)(((ptrdiff_t)NIL_VAL)>>32), (unsigned int)((ptrdiff_t)push), (unsigned int)(((ptrdiff_t)push)>>32));
}

static void jitOpTrue() {}

static void jitOpFalse() {}

static void jitOpPop() {}

static void jitOpGetLocal() {}

static void jitOpSetLocal() {}

static void jitOpGetGlobal() {}

static void jitOpDefineGlobal() {}

static void jitOpSetGlobal() {}

static void jitOpGetUpvalue() {}

static void jitOpSetUpvalue() {}

static void jitOpGetProperty() {}

static void jitOpSetProperty() {}

static void jitOpGetSuper() {}

static void jitOpEqual() {}

static void jitOpGreater() {}

static void jitOpLess() {}

static void jitOpAdd() {}

static void jitOpSubtract() {}

static void jitOpMultiply() {}

static void jitOpDivide() {}

static void jitOpNot() {}

static void jitOpNegate() {}

static void jitOpPrint(dasm_State *state) {
    dasm_put(Dst, 45, (unsigned int)((ptrdiff_t)pop), (unsigned int)(((ptrdiff_t)pop)>>32), (unsigned int)((ptrdiff_t)(ptrdiff_t)printValue), (unsigned int)(((ptrdiff_t)(ptrdiff_t)printValue)>>32), '\n', (unsigned int)((ptrdiff_t)putchar), (unsigned int)(((ptrdiff_t)putchar)>>32));
}

static void jitOpJump() {}

static void jitOpJumpIfFalse() {}

static void jitOpLoop() {}

static void jitOpCall() {}

static void jitOpInvoke() {}

static void jitOpSuperInvoke() {}

static void jitOpClosure() {}

static void jitOpCloseUpvalue() {}

    //| sub rax, 1
    //| mov CARG1, CF->slots
    //| call64 closeUpvalues

static void jitOpReutrn(dasm_State *state) {
    dasm_put(Dst, 76, (unsigned int)((ptrdiff_t)pop), (unsigned int)(((ptrdiff_t)pop)>>32), Dt1(->frameCount));
}

static void jitOpClass() {}

static void jitOpInherit() {}

static void jitOpMethod() {}
