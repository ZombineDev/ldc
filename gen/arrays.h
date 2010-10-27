#ifndef LLVMC_GEN_ARRAYS_H
#define LLVMC_GEN_ARRAYS_H

struct ArrayInitializer;

struct DSliceValue;

const llvm::StructType* DtoArrayType(Type* arrayTy);
const llvm::StructType* DtoArrayType(const LLType* elemTy);
const llvm::ArrayType* DtoStaticArrayType(Type* sarrayTy);

LLConstant* DtoConstArrayInitializer(ArrayInitializer* si);
LLConstant* DtoConstSlice(LLConstant* dim, LLConstant* ptr);

void DtoArrayCopySlices(DSliceValue* dst, DSliceValue* src);
void DtoArrayCopyToSlice(DSliceValue* dst, DValue* src);

void DtoArrayInit(Loc& loc, DValue* array, DValue* value);
void DtoArrayAssign(LLValue* l, LLValue* r);
void DtoSetArray(DValue* array, LLValue* dim, LLValue* ptr);
void DtoSetArrayToNull(LLValue* v);

DSliceValue* DtoNewDynArray(Loc& loc, Type* arrayType, DValue* dim, bool defaultInit=true);
DSliceValue* DtoNewMulDimDynArray(Loc& loc, Type* arrayType, DValue** dims, size_t ndims, bool defaultInit=true);
DSliceValue* DtoResizeDynArray(Type* arrayType, DValue* array, llvm::Value* newdim);

void DtoCatAssignElement(Loc& loc, Type* type, DValue* arr, Expression* exp);
DSliceValue* DtoCatAssignArray(DValue* arr, Expression* exp);
DSliceValue* DtoCatArrays(Type* type, Expression* e1, Expression* e2);
DSliceValue* DtoCatArrayElement(Type* type, Expression* exp1, Expression* exp2);
DSliceValue* DtoAppendDChar(DValue* arr, Expression* exp);

void DtoStaticArrayCopy(LLValue* dst, LLValue* src);

LLValue* DtoArrayEquals(Loc& loc, TOK op, DValue* l, DValue* r);
LLValue* DtoArrayCompare(Loc& loc, TOK op, DValue* l, DValue* r);

LLValue* DtoDynArrayIs(TOK op, DValue* l, DValue* r);

LLValue* DtoArrayCastLength(LLValue* len, const LLType* elemty, const LLType* newelemty);

LLValue* DtoArrayLen(DValue* v);
LLValue* DtoArrayPtr(DValue* v);

DValue* DtoCastArray(Loc& loc, DValue* val, Type* to);

// generates an array bounds check
void DtoArrayBoundsCheck(Loc& loc, DValue* arr, DValue* index, bool isslice);

#endif // LLVMC_GEN_ARRAYS_H
