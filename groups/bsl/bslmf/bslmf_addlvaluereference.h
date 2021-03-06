// bslmf_addlvaluereference.h                                         -*-C++-*-
#ifndef INCLUDED_BSLMF_ADDLVALUEREFERENCE
#define INCLUDED_BSLMF_ADDLVALUEREFERENCE

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide a compile-time type transformation to lvalue reference.
//
//@CLASSES:
//  bsl::add_lvalue_reference: standard meta-function for type transformation
//
//@SEE_ALSO: bslmf_addrvaluereference, bslmf_removereference
//
//@DESCRIPTION: This component defines a meta-function,
// 'bsl::add_lvalue_reference', that may be used to transform a type to its
// lvalue reference type.  An lvalue, as defined in C++11 standard
// [basic.lval], is an expression that designates a function or an object.
//
// 'bsl::add_lvalue_reference' meets the requirements of the
// 'add_lvalue_reference' template defined in the C++11 standard
// [meta.trans.ref].
//
///Usage
///-----
// In this section we show intended use of this component.
//
///Example 1: Transforming Types to Lvalue Reference Types
///- - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Suppose that we want to transform a set of types to their lvalue reference
// types.
//
// Now, we instantiate the 'bsl::add_lvalue_reference' template for each of
// these types, and use the 'bsl::is_same' meta-function to assert the 'type'
// static data member of each instantiation:
//..
//  assert(true ==
//        (bsl::is_same<bsl::add_lvalue_reference<int>::type,   int&>::value));
//  assert(false ==
//        (bsl::is_same<bsl::add_lvalue_reference<int>::type,   int >::value));
//  assert(true ==
//        (bsl::is_same<bsl::add_lvalue_reference<int&>::type,  int&>::value));
//#if defined(BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES)
//  assert(true ==
//        (bsl::is_same<bsl::add_lvalue_reference<int&&>::type, int&>::value));
//#endif
//..
// Notice that the rvalue reference used above is a feature introduced in the
// C++11 standard and may not be supported by all compilers.

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

#ifndef INCLUDED_BSLS_COMPILERFEATURES
#include <bsls_compilerfeatures.h>
#endif

namespace bsl {
                         // ===========================
                         // struct add_lvalue_reference
                         // ===========================

template <class TYPE>
struct add_lvalue_reference {
    // This 'struct' template implements a meta-function to transform the
    // the (template parameter) 'TYPE' to its lvalue reference type.

    typedef TYPE& type;
        // This 'typedef' defines the return type of this meta function.
};

#if !defined(BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES)

template <class TYPE>
struct add_lvalue_reference<TYPE&> {
    // This partial specialization of 'add_lvalue_reference' defines a return
    // type when it is instantiated with an lvalue reference type.

    typedef TYPE& type;
        // This 'typedef' defines the return type of this meta function.
};

#endif

template <>
struct add_lvalue_reference<void> {
    // This partial specialization of 'add_lvalue_reference' defines the return
    // type when it is instantiated with 'void' type.

    typedef void type;
        // This 'typedef' defines the return type of this meta function.
};

template <>
struct add_lvalue_reference<void const> {
    // This partial specialization of 'add_lvalue_reference' defines the return
    // type when it is instantiated with 'void const' type.

    typedef void const type;
        // This 'typedef' defines the return type of this meta function.
};

template <>
struct add_lvalue_reference<void volatile> {
    // This partial specialization of 'add_lvalue_reference' defines the return
    // type when it is instantiated with 'void volatile' type.

    typedef void volatile type;
        // This 'typedef' defines the return type of this meta function.
};

template <>
struct add_lvalue_reference<void const volatile> {
    // This partial specialization of 'add_lvalue_reference' defines the return
    // type when it is instantiated with 'void const volatile' type.

    typedef void const volatile type;
        // This 'typedef' defines the return type of this meta function.
};

}  // close namespace bsl

#endif

// ----------------------------------------------------------------------------
// Copyright (C) 2013 Bloomberg Finance L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------
