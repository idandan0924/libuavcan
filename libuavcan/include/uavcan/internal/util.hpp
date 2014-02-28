/*
 * Copyright (C) 2014 Pavel Kirienko <pavel.kirienko@gmail.com>
 */

#pragma once

#include <cassert>

namespace uavcan
{
/**
 * Usage:
 *  StaticAssert<expression>::check();
 */
template <bool Value>
struct StaticAssert;

template <>
struct StaticAssert<true>
{
    static void check() { }
};

/**
 * Usage:
 *  ShowIntegerAsError<integer_expression>::foobar();
 */
template<long N> struct ShowIntegerAsError;

/**
 * Prevents copying when inherited
 */
class Noncopyable
{
    Noncopyable(const Noncopyable&);
    Noncopyable& operator=(const Noncopyable&);
protected:
    Noncopyable() { }
};

/**
 * Compile time conditions
 */
template<bool B, typename T = void>
struct EnableIf { };

template<typename T>
struct EnableIf<true, T> { typedef T Type; };


template<typename T, typename R = void>
struct EnableIfType { typedef R Type; };


template <bool Condition, typename TrueType, typename FalseType>
struct StaticIf;

template <typename TrueType, typename FalseType>
struct StaticIf<true, TrueType, FalseType>
{
    typedef TrueType Result;
};

template <typename TrueType, typename FalseType>
struct StaticIf<false, TrueType, FalseType>
{
    typedef FalseType Result;
};

/**
 * Value types
 */
template<bool> struct BooleanType { };
typedef BooleanType<true> TrueType;
typedef BooleanType<false> FalseType;

}

/// Ensure that conditional comilation macros are present
#include <uavcan/internal/impl_constants.hpp>
