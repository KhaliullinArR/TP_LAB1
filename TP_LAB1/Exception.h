#ifndef EXCEPTION_H
#define EXCEPTION_H


class MatrixException {

protected:
	const char* exception;

public:
	MatrixException(const char* ex = "MatrixException");
	const char* getException() const;
};

class MatrixDimException :public MatrixException {

public:

	MatrixDimException(const char* ex = "MatrixDimException");
};


class VectorException {
protected:
	const char* exception;

public:
	VectorException(const char* ex = "VectorException");
	const char* getException() const;
};

class NegativeDimException : public VectorException {
public:
	NegativeDimException(const char* ex = "NegativeDimException");

};

class DifferentDimException : public VectorException {
public:
	DifferentDimException(const char* ex = "DifferentDimException");

};



#endif
