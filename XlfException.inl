// Copyright (c) 1998-2001
// Jerome Lecomte
// 
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee,
// provided that the above copyright notice appear in all copies and
// that both that copyright notice and this permission notice appear
// in supporting documentation. This software is freely provided "as is" 
// without express or implied warranty.

/*!
\file XlfException.inl
\brief Implements inline methods of XlfException.
*/

#ifdef NDEBUG
#define INLINE inline
#else
#define INLINE
#endif

INLINE XlfException::XlfException(): std::exception()
{}

INLINE XlfException::XlfException(const std::string& what): std::exception(what.c_str())
{}