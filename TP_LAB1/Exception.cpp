#include "Exception.h"



VectorException::VectorException(const char* ex):exception(ex){

}

const char* VectorException::getException() const
{
	return exception;
}

NegativeDimException::NegativeDimException(const char* ex):VectorException(ex)
{
}

DifferentDimException::DifferentDimException(const char* ex):VectorException(ex){

}

MatrixException::MatrixException(const char* ex): exception(ex)
{
}

const char* MatrixException::getException() const
{
	return exception;
}

MatrixDimException::MatrixDimException(const char* ex) : MatrixException(ex)
{
}
