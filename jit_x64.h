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











static const unsigned char actionList[1317] = {
  254,0,248,10,85,72,137,229,83,83,65,84,65,85,65,86,65,87,73,137,252,252,73,
  191,237,237,65,131,135,233,1,77,137,252,253,65,139,135,233,131,232,1,105,
  192,239,73,1,197,77,139,151,233,72,199,192,237,72,105,192,239,73,41,194,77,
  137,149,233,77,139,148,253,36,233,77,137,149,233,77,139,183,233,255,249,255,
  72,191,237,237,77,139,151,233,73,137,58,73,129,135,233,239,255,73,129,175,
  233,239,77,139,151,233,73,139,2,255,77,139,149,233,73,139,186,233,77,139,
  151,233,73,137,58,73,129,135,233,239,255,72,199,199,0,0,0,0,77,139,159,233,
  72,131,199,1,72,105,252,255,239,73,41,252,251,73,139,3,77,139,149,233,73,
  137,130,233,255,72,191,237,237,72,190,237,237,72,186,237,237,72,184,237,237,
  252,255,208,72,133,192,15,132,244,247,252,233,244,248,248,1,72,191,237,237,
  72,190,237,237,72,184,237,237,252,255,208,72,199,192,0,0,0,0,252,233,244,
  11,248,2,255,73,139,188,253,36,233,77,139,151,233,73,137,58,73,129,135,233,
  239,255,72,199,199,0,0,0,0,77,139,159,233,72,131,199,1,72,105,252,255,239,
  73,41,252,251,73,139,3,72,191,237,237,72,190,237,237,72,137,194,72,184,237,
  237,252,255,208,73,129,175,233,239,77,139,151,233,73,139,2,255,72,199,199,
  0,0,0,0,77,139,159,233,72,131,199,1,72,105,252,255,239,73,41,252,251,73,139,
  3,72,191,237,237,72,190,237,237,72,137,194,72,184,237,237,252,255,208,72,
  133,192,15,132,244,247,72,191,237,237,72,190,237,237,72,184,237,237,252,255,
  208,72,191,237,237,72,190,237,237,72,184,237,237,255,252,255,208,72,199,192,
  0,0,0,0,252,233,244,11,248,1,255,77,139,149,233,77,139,146,233,77,139,146,
  233,73,139,186,233,77,139,151,233,73,137,58,73,129,135,233,239,255,72,199,
  199,0,0,0,0,77,139,159,233,72,131,199,1,72,105,252,255,239,73,41,252,251,
  73,139,3,77,139,149,233,77,139,146,233,77,139,146,233,77,139,146,233,73,137,
  2,255,72,184,237,237,252,255,208,72,133,192,15,132,244,247,72,199,192,0,0,
  0,0,252,233,244,11,248,1,255,73,129,175,233,239,77,139,151,233,73,139,2,72,
  137,199,72,190,237,237,72,184,237,237,252,255,208,72,133,192,15,132,244,247,
  252,233,244,248,248,1,72,199,192,0,0,0,0,252,233,244,11,248,2,255,73,129,
  175,233,239,77,139,151,233,73,139,2,73,137,194,73,129,175,233,239,77,139,
  151,233,73,139,2,73,137,195,76,137,223,76,137,214,72,184,237,237,252,255,
  208,72,133,192,15,132,244,247,73,139,188,253,36,233,252,233,244,248,248,1,
  73,139,188,253,36,233,248,2,77,139,151,233,73,137,58,73,129,135,233,239,255,
  73,129,175,233,239,77,139,151,233,73,139,2,72,137,199,72,184,237,237,252,
  255,208,72,133,192,15,132,244,247,73,139,188,253,36,233,252,233,244,248,248,
  1,73,139,188,253,36,233,248,2,77,139,151,233,73,137,58,73,129,135,233,239,
  255,73,129,175,233,239,77,139,151,233,73,139,2,72,137,199,72,184,237,237,
  252,255,208,72,199,199,237,72,184,237,237,252,255,208,255,252,233,245,255,
  72,199,199,0,0,0,0,77,139,159,233,72,131,199,1,72,105,252,255,239,73,41,252,
  251,73,139,3,72,137,199,72,184,237,237,252,255,208,72,133,192,15,132,244,
  247,252,233,245,248,1,255,72,199,199,237,77,139,159,233,72,131,199,1,72,105,
  252,255,239,73,41,252,251,73,139,3,72,137,199,72,199,198,237,72,184,237,237,
  252,255,208,72,133,192,15,132,244,247,252,233,244,248,248,1,72,199,199,0,
  0,0,0,252,233,244,11,248,2,77,137,252,253,65,139,135,233,131,232,1,105,192,
  239,73,1,197,255,72,191,237,237,72,199,198,237,72,184,237,237,252,255,208,
  72,133,192,15,132,244,247,252,233,244,248,248,1,72,199,192,0,0,0,0,252,233,
  244,11,248,2,77,137,252,253,65,139,135,233,131,232,1,105,192,239,73,1,197,
  255,73,129,175,233,239,77,139,151,233,73,139,2,72,137,199,72,190,237,237,
  72,199,194,237,72,184,237,237,252,255,208,72,133,192,15,132,244,247,252,233,
  244,248,248,1,72,199,192,0,0,0,0,252,233,244,11,248,2,77,137,252,253,65,139,
  135,233,131,232,1,105,192,239,73,1,197,255,72,191,237,237,72,184,237,237,
  252,255,208,72,137,195,72,137,223,72,184,237,237,252,255,208,72,137,199,77,
  139,151,233,73,137,58,73,129,135,233,239,255,77,139,149,233,73,139,186,233,
  72,184,237,237,252,255,208,76,139,147,233,73,137,130,233,255,77,139,149,233,
  76,139,147,233,77,139,146,233,76,139,155,233,77,137,147,233,255,73,139,191,
  233,72,129,252,239,239,72,184,237,237,252,255,208,73,129,175,233,239,77,139,
  151,233,73,139,2,255,73,129,175,233,239,77,139,151,233,73,139,2,73,137,132,
  253,36,233,73,139,189,233,72,184,237,237,252,255,208,72,184,237,237,131,40,
  1,65,139,135,233,133,192,15,132,244,247,252,233,244,248,248,1,73,129,175,
  233,239,77,139,151,233,73,139,2,72,199,192,1,0,0,0,252,233,244,11,248,2,255,
  77,139,157,233,77,137,159,233,73,139,188,253,36,233,77,139,151,233,73,137,
  58,73,129,135,233,239,77,137,252,253,65,139,135,233,131,232,1,105,192,239,
  73,1,197,72,199,192,1,0,0,0,248,11,65,95,65,94,65,93,65,92,91,91,93,195,255,
  72,191,237,237,72,184,237,237,252,255,208,72,137,199,72,184,237,237,252,255,
  208,72,137,199,77,139,151,233,73,137,58,73,129,135,233,239,255,72,191,237,
  237,72,184,237,237,252,255,208,255
};

enum {
  jitGlobal_main,
  jitGlobal_return,
  jitGlobal__MAX
};

const char loxJIT_arch[] = "x64";

static void debugger() {
    static int num = 0;
    num++;
    printf("debugger:%d\n", num);
}

// 要保证栈对齐 16字节 即除rbp外，push reg要成对出现，否则会造成Segmentation fault (core dumped)
static void preCall(Dst_DECL) {
    int argCount = (J->closure->function->arity);
    dasm_put(Dst, 0);
    dasm_put(Dst, 2, (unsigned int)((ptrdiff_t)&vm), (unsigned int)(((ptrdiff_t)&vm)>>32), Dt1(->frameCount), Dt1(->frameCount), sizeof(CallFrame), Dt1(->stackTop), argCount+1, sizeof(Value), Dt3(->slots), Dt4(->closure), Dt3(->closure), Dt1(->stackTop));
}

static char message[] = "Undefined variable '%s'.";

void setJmpTarget(size_t target) {
    dasm_put(Dst, 82, (target));
}

static void jitOpConstant(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    Value constant = J->closure->function->chunk.constants.values[idx];
    dasm_put(Dst, 84, (unsigned int)((ptrdiff_t)constant), (unsigned int)(((ptrdiff_t)constant)>>32), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpNil(Dst_DECL) {
    dasm_put(Dst, 84, (unsigned int)((ptrdiff_t)NIL_VAL), (unsigned int)(((ptrdiff_t)NIL_VAL)>>32), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpTrue(Dst_DECL) {
    dasm_put(Dst, 84, (unsigned int)((ptrdiff_t)BOOL_VAL(true)), (unsigned int)(((ptrdiff_t)BOOL_VAL(true))>>32), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpFalse(Dst_DECL) {
    dasm_put(Dst, 84, (unsigned int)((ptrdiff_t)BOOL_VAL(false)), (unsigned int)(((ptrdiff_t)BOOL_VAL(false))>>32), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpPop(Dst_DECL) {
    dasm_put(Dst, 101, Dt1(->stackTop), sizeof(Value), Dt1(->stackTop));
}

static void jitOpGetLocal(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t slot = J->closure->function->chunk.code[*i];
    dasm_put(Dst, 114, Dt3(->slots), Dt6([slot]), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpSetLocal(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t slot = J->closure->function->chunk.code[*i];
    dasm_put(Dst, 135, Dt1(->stackTop), sizeof(Value), Dt3(->slots), Dt6([slot]));
}

static void jitOpGetGlobal(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *name = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    dasm_put(Dst, 171, (unsigned int)((ptrdiff_t)&vm.globals), (unsigned int)(((ptrdiff_t)&vm.globals)>>32), (unsigned int)((ptrdiff_t)name), (unsigned int)(((ptrdiff_t)name)>>32), (unsigned int)((ptrdiff_t)&J->value), (unsigned int)(((ptrdiff_t)&J->value)>>32), (unsigned int)((ptrdiff_t)tableGet), (unsigned int)(((ptrdiff_t)tableGet)>>32), (unsigned int)((ptrdiff_t)&message), (unsigned int)(((ptrdiff_t)&message)>>32), (unsigned int)((ptrdiff_t)name->chars), (unsigned int)(((ptrdiff_t)name->chars)>>32), (unsigned int)((ptrdiff_t)runtimeError), (unsigned int)(((ptrdiff_t)runtimeError)>>32));
    dasm_put(Dst, 232, Dt4(->value), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpDefineGlobal(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *name = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    dasm_put(Dst, 251, Dt1(->stackTop), sizeof(Value), (unsigned int)((ptrdiff_t)&vm.globals), (unsigned int)(((ptrdiff_t)&vm.globals)>>32), (unsigned int)((ptrdiff_t)name), (unsigned int)(((ptrdiff_t)name)>>32), (unsigned int)((ptrdiff_t)tableSet), (unsigned int)(((ptrdiff_t)tableSet)>>32), Dt1(->stackTop), sizeof(Value), Dt1(->stackTop));
}

static void jitOpSetGlobal(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *name = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    dasm_put(Dst, 309, Dt1(->stackTop), sizeof(Value), (unsigned int)((ptrdiff_t)&vm.globals), (unsigned int)(((ptrdiff_t)&vm.globals)>>32), (unsigned int)((ptrdiff_t)name), (unsigned int)(((ptrdiff_t)name)>>32), (unsigned int)((ptrdiff_t)tableSet), (unsigned int)(((ptrdiff_t)tableSet)>>32), (unsigned int)((ptrdiff_t)&vm.globals), (unsigned int)(((ptrdiff_t)&vm.globals)>>32), (unsigned int)((ptrdiff_t)name), (unsigned int)(((ptrdiff_t)name)>>32), (unsigned int)((ptrdiff_t)tableDelete), (unsigned int)(((ptrdiff_t)tableDelete)>>32), (unsigned int)((ptrdiff_t)&message), (unsigned int)(((ptrdiff_t)&message)>>32), (unsigned int)((ptrdiff_t)name->chars), (unsigned int)(((ptrdiff_t)name->chars)>>32), (unsigned int)((ptrdiff_t)runtimeError), (unsigned int)(((ptrdiff_t)runtimeError)>>32));
    dasm_put(Dst, 389);
}

static void jitOpGetUpvalue(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t slot = J->closure->function->chunk.code[*i];
    dasm_put(Dst, 406, Dt3(->closure), Dt5(->upvalues), DtC([slot]), DtC(->location), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpSetUpvalue(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t slot = J->closure->function->chunk.code[*i];
    dasm_put(Dst, 435, Dt1(->stackTop), sizeof(Value), Dt3(->closure), Dt5(->upvalues), DtC([slot]), DtC(->location));
}

static void jitOpGetProperty() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opGetProperty), (unsigned int)(((ptrdiff_t)opGetProperty)>>32));
}

static void jitOpSetProperty() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opSetProperty), (unsigned int)(((ptrdiff_t)opSetProperty)>>32));
}

static void jitOpGetSuper(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *name = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    dasm_put(Dst, 510, Dt1(->stackTop), sizeof(Value), Dt1(->stackTop), (unsigned int)((ptrdiff_t)name), (unsigned int)(((ptrdiff_t)name)>>32), (unsigned int)((ptrdiff_t)bindMethod), (unsigned int)(((ptrdiff_t)bindMethod)>>32));

}

static void jitOpEqual() {
    dasm_put(Dst, 563, Dt1(->stackTop), sizeof(Value), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value), Dt1(->stackTop), (unsigned int)((ptrdiff_t)valuesEqual), (unsigned int)(((ptrdiff_t)valuesEqual)>>32), Dt4(->valTrue), Dt4(->valFalse), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpGreater() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opGreater), (unsigned int)(((ptrdiff_t)opGreater)>>32));
}

static void jitOpLess() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opLess), (unsigned int)(((ptrdiff_t)opLess)>>32));
}

static void jitOpAdd() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opAdd), (unsigned int)(((ptrdiff_t)opAdd)>>32));
}

static void jitOpSubtract() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opSubtract), (unsigned int)(((ptrdiff_t)opSubtract)>>32));
}

static void jitOpMultiply() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opMultiply), (unsigned int)(((ptrdiff_t)opMultiply)>>32));
}

static void jitOpDivide() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opDivide), (unsigned int)(((ptrdiff_t)opDivide)>>32));
}

static void jitOpNot() {
    dasm_put(Dst, 646, Dt1(->stackTop), sizeof(Value), Dt1(->stackTop), (unsigned int)((ptrdiff_t)isFalsey), (unsigned int)(((ptrdiff_t)isFalsey)>>32), Dt4(->valTrue), Dt4(->valFalse), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpNegate() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opNegate), (unsigned int)(((ptrdiff_t)opNegate)>>32));
}

static void jitOpPrint(Dst_DECL) {
    dasm_put(Dst, 708, Dt1(->stackTop), sizeof(Value), Dt1(->stackTop), (unsigned int)((ptrdiff_t)printValue), (unsigned int)(((ptrdiff_t)printValue)>>32), '\n', (unsigned int)((ptrdiff_t)putchar), (unsigned int)(((ptrdiff_t)putchar)>>32));
}

static void jitOpJump(Dst_DECL, size_t* i) {
    // 跳转距离在后面两个字节里, 距离是opcode数，在dasc中要再做转化
    (*i)+=2;
    uint8_t *code = J->closure->function->chunk.code;
    uint16_t offset = (uint16_t)((code[*i-1] << 8) | code[*i]);
    dasm_put(Dst, 742, (*i+offset+1));
}

static void jitOpJumpIfFalse(Dst_DECL, size_t* i) {
    (*i)+=2;
    uint8_t *code = J->closure->function->chunk.code;
    uint16_t offset = (uint16_t)((code[*i-1] << 8) | code[*i]);
    dasm_put(Dst, 746, Dt1(->stackTop), sizeof(Value), (unsigned int)((ptrdiff_t)isFalsey), (unsigned int)(((ptrdiff_t)isFalsey)>>32), (*i+offset+1));
}

static void jitOpLoop(Dst_DECL, size_t* i) {
    (*i)+=2;
    uint8_t *code = J->closure->function->chunk.code;
    uint16_t offset = (uint16_t)((code[*i-1] << 8) | code[*i]);
    dasm_put(Dst, 742, (*i-offset+1));
}

static void jitOpCall(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t argCount = J->closure->function->chunk.code[*i];
    dasm_put(Dst, 796, argCount, Dt1(->stackTop), sizeof(Value), argCount, (unsigned int)((ptrdiff_t)callValue), (unsigned int)(((ptrdiff_t)callValue)>>32), Dt1(->frameCount), sizeof(CallFrame));
}

static void jitOpInvoke(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *method = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    (*i)++;
    uint8_t argCount = J->closure->function->chunk.code[*i];
    dasm_put(Dst, 878, (unsigned int)((ptrdiff_t)method), (unsigned int)(((ptrdiff_t)method)>>32), argCount, (unsigned int)((ptrdiff_t)invoke), (unsigned int)(((ptrdiff_t)invoke)>>32), Dt1(->frameCount), sizeof(CallFrame));
}

static void jitOpSuperInvoke(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *method = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    (*i)++;
    uint8_t argCount = J->closure->function->chunk.code[*i];
    dasm_put(Dst, 937, Dt1(->stackTop), sizeof(Value), Dt1(->stackTop), (unsigned int)((ptrdiff_t)method), (unsigned int)(((ptrdiff_t)method)>>32), argCount, (unsigned int)((ptrdiff_t)invokeFromClass), (unsigned int)(((ptrdiff_t)invokeFromClass)>>32), Dt1(->frameCount), sizeof(CallFrame));
}

static Value objVal(ObjClosure *closure) {
    return OBJ_VAL(closure);
}

static void jitOpClosure(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    Value constant = J->closure->function->chunk.constants.values[idx];
    ObjFunction *function = (ObjFunction*)AS_OBJ(constant);
    dasm_put(Dst, 1011, (unsigned int)((ptrdiff_t)function), (unsigned int)(((ptrdiff_t)function)>>32), (unsigned int)((ptrdiff_t)newClosure), (unsigned int)(((ptrdiff_t)newClosure)>>32), (unsigned int)((ptrdiff_t)objVal), (unsigned int)(((ptrdiff_t)objVal)>>32), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
    for (size_t j = 0; j < function->upvalueCount; j++) {
        uint8_t isLocal = ++(*i);
        uint8_t index = ++(*i);
        if (isLocal) {
            dasm_put(Dst, 1051, Dt3(->slots), Dt6([index]), (unsigned int)((ptrdiff_t)captureUpvalue), (unsigned int)(((ptrdiff_t)captureUpvalue)>>32), Dt5(->upvalues), DtC([j]));
        } else {
            dasm_put(Dst, 1075, Dt3(->closure), Dt5(->upvalues), DtC([index]), Dt5(->upvalues), DtC([j]));
        }
    }
}

static void jitOpCloseUpvalue() {
    dasm_put(Dst, 1096, Dt1(->stackTop), sizeof(Value), (unsigned int)((ptrdiff_t)closeUpvalues), (unsigned int)(((ptrdiff_t)closeUpvalues)>>32), Dt1(->stackTop), sizeof(Value), Dt1(->stackTop));
}

static void jitOpReutrn(Dst_DECL) {
    dasm_put(Dst, 1125, Dt1(->stackTop), sizeof(Value), Dt1(->stackTop), Dt4(->value), Dt3(->slots), (unsigned int)((ptrdiff_t)closeUpvalues), (unsigned int)(((ptrdiff_t)closeUpvalues)>>32), (unsigned int)((ptrdiff_t)(&vm.frameCount)), (unsigned int)(((ptrdiff_t)(&vm.frameCount))>>32), Dt1(->frameCount), Dt1(->stackTop), sizeof(Value), Dt1(->stackTop));
    dasm_put(Dst, 1203, Dt3(->slots), Dt1(->stackTop), Dt4(->value), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value), Dt1(->frameCount), sizeof(CallFrame));
}

static void jitOpClass(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *name = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    dasm_put(Dst, 1268, (unsigned int)((ptrdiff_t)name), (unsigned int)(((ptrdiff_t)name)>>32), (unsigned int)((ptrdiff_t)newClass), (unsigned int)(((ptrdiff_t)newClass)>>32), (unsigned int)((ptrdiff_t)objVal), (unsigned int)(((ptrdiff_t)objVal)>>32), Dt1(->stackTop), Dt1(->stackTop), sizeof(Value));
}

static void jitOpInherit() {
    dasm_put(Dst, 482, (unsigned int)((ptrdiff_t)opInherit), (unsigned int)(((ptrdiff_t)opInherit)>>32));
}

static void jitOpMethod(Dst_DECL, size_t* i) {
    (*i)++;
    uint8_t idx = J->closure->function->chunk.code[*i];
    ObjString *name = AS_STRING(J->closure->function->chunk.constants.values[idx]);
    dasm_put(Dst, 1305, (unsigned int)((ptrdiff_t)name), (unsigned int)(((ptrdiff_t)name)>>32), (unsigned int)((ptrdiff_t)defineMethod), (unsigned int)(((ptrdiff_t)defineMethod)>>32));
}
