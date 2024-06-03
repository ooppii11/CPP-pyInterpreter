#include "SyntaxException.h"

const char* SyntaxException::what() const
{
    return "SyntaxError: invalid syntax";
}
