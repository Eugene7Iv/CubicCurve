#include "Function.h"

Function::Function(size_t nParams)
{
	m_params.reserve(nParams);
	m_params.resize(nParams);
}

Function::~Function()
{
}
