#include <sys/mman.h>
#include <assert.h>

#include "jit.h"
#include "dynasm/dasm_proto.h"
#include "dynasm/dasm_x86.h"
#include "vm.h"
#include "object.h"

static void initJit(Dst_DECL, const void *actionList);
static void *jitCode(Dst_DECL);


#include "jit_x64.h"

static void initJit(Dst_DECL, const void *actionList) {
    dasm_init(Dst, DASM_MAXSECTION);
    dasm_setup(Dst, actionList);
}

void* jitCompile(ObjClosure *closure) {
    vm.J->closure = closure;
    dasm_State *state;
    initJit(Dst, actionList);
    // once
    vm.J->jgbl = malloc(sizeof(void *) * jitGlobal__MAX);
    dasm_setupglobal(Dst, vm.J->jgbl, jitGlobal__MAX);

    uint8_t *codes = closure->function->chunk.code;
    int codeCount = closure->function->chunk.count;

    dasm_growpc(Dst, codeCount + 3);

    preCall(Dst);
    for (size_t i = 0; i < codeCount; i++) {
        uint8_t opcode = codes[i];
        switch (opcode) {
        case OP_CONSTANT:
            jitOpConstant(state, closure, &i);
            break;
        case OP_NIL:
            jitOpNil(state);
            break;
        case OP_TRUE:
            jitOpTrue();
            break;
        case OP_FALSE:
            jitOpFalse();
            break;
        case OP_POP:
            jitOpPop();
            break;
        case OP_GET_LOCAL: {
            jitOpGetLocal();
            break;
        }
        case OP_SET_LOCAL: {
            jitOpSetLocal();
            break;
        }
        case OP_GET_GLOBAL: {
            jitOpGetGlobal();
            break;
        }
        case OP_DEFINE_GLOBAL: {
            jitOpDefineGlobal();
            break;
        }
        case OP_SET_GLOBAL: {
            jitOpSetGlobal();
            break;
        }
        case OP_GET_UPVALUE: {
            jitOpGetUpvalue();
            break;
        }
        case OP_SET_UPVALUE: {
            jitOpSetUpvalue();
            break;
        }
        case OP_GET_PROPERTY: {
            jitOpGetProperty();
            break;
        }
        case OP_SET_PROPERTY: {
            jitOpSetProperty();
            break;
        }
        case OP_GET_SUPER: {
            jitOpGetSuper();
            break;
        }
        case OP_EQUAL: {
            jitOpEqual();
            break;
        }
        case OP_GREATER:
            jitOpGreater();
            break;
        case OP_LESS:
            jitOpLess();
            break;
        case OP_ADD: {
            jitOpAdd();
            break;
        }
        case OP_SUBTRACT:
            jitOpSubtract();
            break;
        case OP_MULTIPLY:
            jitOpMultiply();
            break;
        case OP_DIVIDE:
            jitOpDivide();
            break;
        case OP_NOT:
            jitOpNot();
            break;
        case OP_NEGATE:
            jitOpNegate();
            break;
        case OP_PRINT: {
            jitOpPrint(state);
            break;
        }
        case OP_JUMP: {
            jitOpJump();
            break;
        }
        case OP_JUMP_IF_FALSE: {
            jitOpJumpIfFalse();
            break;
        }
        case OP_LOOP: {
            jitOpLoop();
            break;
        }
        case OP_CALL: {
            jitOpCall();
            break;
        }
        case OP_INVOKE: {
            jitOpInvoke();
            break;
        }
        case OP_SUPER_INVOKE: {
            jitOpSuperInvoke();
            break;
        }
        case OP_CLOSURE: {
            jitOpClosure();
            break;
        }
        case OP_CLOSE_UPVALUE:
            jitOpCloseUpvalue();
            break;
        case OP_RETURN: {
            jitOpReutrn(state);
            break;
        }
        case OP_CLASS:
            jitOpClass();
            break;
        case OP_INHERIT: {
            jitOpInherit();
            break;
        }
        case OP_METHOD:
            jitOpMethod();
            break;
        }
    }

    
    return jitCode(Dst);
}

static void *jitCode(Dst_DECL) {
    dasm_State *D = Dst_REF;

    size_t size;

    int dasm_status = dasm_link(Dst, &size);
    assert(dasm_status == DASM_S_OK);

    char *mem = mmap(NULL, size + sizeof(size_t), PROT_READ | PROT_WRITE,
                     MAP_ANON | MAP_PRIVATE, -1, 0);
    assert(mem != MAP_FAILED);

    *(size_t *)mem = size;
    void *ret = mem + sizeof(size_t);

    dasm_encode(Dst, ret);
    dasm_free(Dst);

    int success = mprotect(mem, size, PROT_EXEC | PROT_READ);
    assert(success == 0);

    return ret;
}

void freeJitCode(void *code) {
    void *mem = (char *)code - sizeof(size_t);
    int status = munmap(mem, *(size_t *)mem);
    assert(status == 0);
}