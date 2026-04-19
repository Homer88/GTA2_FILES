// Module: S280
// Functions working with structure S280
// Generated from gta2.exe.c

#include "../../include/common.h"

void * __thiscall S280__S280(S280 *this,byte param_1)

{
  undefined1 *_Memory;
  
  if ((param_1 & 2) != 0) {
    _Memory = &this[-1].S281[0x52].field_0x28;
    _eh_vector_destructor_iterator_
              (this,44,*(int *)&this[-1].S281[0x52].field_0x28,
               (_func_void_void_ptr *)&DAT_00432cc0);
    if ((param_1 & 1) != 0) {
      _free(_Memory);
    }
    return _Memory;
  }
  if ((param_1 & 1) != 0) {
    _free(this);
  }
  return this;
}


