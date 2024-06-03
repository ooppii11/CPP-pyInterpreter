#include "IndentationException.h"


const char* IndentationException::what() const noexcept
{
	return "IndentationError: unexpected indent";
}