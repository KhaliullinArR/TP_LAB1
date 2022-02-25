#include "ListException.h"

ListException::ListException(const char* ex): exception(ex)
{
}
const char* ListException::getException() const
{
	return exception;
}

NoElemsExecpetion::NoElemsExecpetion(const char* ex):ListException(ex)
{
}
