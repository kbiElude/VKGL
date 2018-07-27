#include "OpenGL/types.h"

VKGL::DispatchTable::DispatchTable()
{
    memset(this,
           0,
           sizeof(*this) );
}