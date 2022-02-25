#ifndef LISTEXCEPTION_H
#define LISTEXCEPTION_H

class ListException {
protected:
	const char* exception;

public:
	ListException(const char* ex = "ListException");
	const char* getException() const;
};

class NoElemsExecpetion : public ListException {
public:
	NoElemsExecpetion(const char* ex = "NoElemsExcpetion");

};




#endif