/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @header      CFPP-Number.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFNumberRef wrapper
 */

#ifndef __CFPP_NUMBER_H__
#define __CFPP_NUMBER_H__

#include <CF++/CFPP-PropertyListType.h>
#include <stdint.h>

namespace CF
{
    class Number: public PropertyListType< Number >
    {
        public:
            
            #ifdef _WIN32
            
            typedef          __int8   SInt8;
            typedef unsigned __int8   UInt8;
            typedef          __int16 SInt16;
            typedef unsigned __int16 UInt16;
            typedef          __int32 SInt32;
            typedef unsigned __int32 UInt32;
            typedef          __int64 SInt64;
            typedef unsigned __int64 UInt64;
            
            #else
            
            typedef int8_t   SInt8;
            typedef uint8_t  UInt8;
            typedef int16_t  SInt16;
            typedef uint16_t UInt16;
            typedef int32_t  SInt32;
            typedef uint32_t UInt32;
            typedef int64_t  SInt64;
            typedef uint64_t UInt64;
            
            #endif
            
            typedef float   Float32;
            typedef double  Float64;
            
            Number( void );
            Number( CFTypeRef cfObject );
            Number( CFNumberRef cfObject );
            Number( CFTypeRef cfObject, SInt8 defaultValueIfNULL );
            Number( CFTypeRef cfObject, SInt16 defaultValueIfNULL );
            Number( CFTypeRef cfObject, SInt32 defaultValueIfNULL );
            Number( CFTypeRef cfObject, SInt64 defaultValueIfNULL );
            Number( CFTypeRef cfObject, UInt8 defaultValueIfNULL );
            Number( CFTypeRef cfObject, UInt16 defaultValueIfNULL );
            Number( CFTypeRef cfObject, UInt32 defaultValueIfNULL );
            Number( CFTypeRef cfObject, UInt64 defaultValueIfNULL );
            Number( CFTypeRef cfObject, Float32 defaultValueIfNULL );
            Number( CFTypeRef cfObject, Float64 defaultValueIfNULL );
            Number( CFNumberRef cfObject, SInt8 defaultValueIfNULL );
            Number( CFNumberRef cfObject, SInt16 defaultValueIfNULL );
            Number( CFNumberRef cfObject, SInt32 defaultValueIfNULL );
            Number( CFNumberRef cfObject, SInt64 defaultValueIfNULL );
            Number( CFNumberRef cfObject, UInt8 defaultValueIfNULL );
            Number( CFNumberRef cfObject, UInt16 defaultValueIfNULL );
            Number( CFNumberRef cfObject, UInt32 defaultValueIfNULL );
            Number( CFNumberRef cfObject, UInt64 defaultValueIfNULL );
            Number( CFNumberRef cfObject, Float32 defaultValueIfNULL );
            Number( CFNumberRef cfObject, Float64 defaultValueIfNULL );
            Number( const Number & value );
            Number( SInt8 value );
            Number( SInt16 value );
            Number( SInt32 value );
            Number( SInt64 value );
            Number( UInt8 value );
            Number( UInt16 value );
            Number( UInt32 value );
            Number( UInt64 value );
            Number( Float32 value );
            Number( Float64 value );
            
            #ifdef CFPP_HAS_CPP11
            Number( Number && value );
            #endif
            
            virtual ~Number( void );
            
            Number & operator = ( Number value );
            Number & operator = ( CFTypeRef value );
            Number & operator = ( CFNumberRef value );
            Number & operator = ( SInt8 value );
            Number & operator = ( SInt16 value );
            Number & operator = ( SInt32 value );
            Number & operator = ( SInt64 value );
            Number & operator = ( UInt8 value );
            Number & operator = ( UInt16 value );
            Number & operator = ( UInt32 value );
            Number & operator = ( UInt64 value );
            Number & operator = ( Float32 value );
            Number & operator = ( Float64 value );
            
            bool operator == ( const Number & value ) const;
            bool operator == ( CFTypeRef value ) const;
            bool operator == ( CFNumberRef value ) const;
            bool operator == ( SInt8 value ) const;
            bool operator == ( SInt16 value ) const;
            bool operator == ( SInt32 value ) const;
            bool operator == ( SInt64 value ) const;
            bool operator == ( UInt8 value ) const;
            bool operator == ( UInt16 value ) const;
            bool operator == ( UInt32 value ) const;
            bool operator == ( UInt64 value ) const;
            bool operator == ( Float32 value ) const;
            bool operator == ( Float64 value ) const;
            
            bool operator != ( const Number & value ) const;
            bool operator != ( CFTypeRef value ) const;
            bool operator != ( CFNumberRef value ) const;
            bool operator != ( SInt8 value ) const;
            bool operator != ( SInt16 value ) const;
            bool operator != ( SInt32 value ) const;
            bool operator != ( SInt64 value ) const;
            bool operator != ( UInt8 value ) const;
            bool operator != ( UInt16 value ) const;
            bool operator != ( UInt32 value ) const;
            bool operator != ( UInt64 value ) const;
            bool operator != ( Float32 value ) const;
            bool operator != ( Float64 value ) const;
            
            bool operator >= ( const Number & value ) const;
            bool operator >= ( CFNumberRef value ) const;
            bool operator >= ( SInt8 value ) const;
            bool operator >= ( SInt16 value ) const;
            bool operator >= ( SInt32 value ) const;
            bool operator >= ( SInt64 value ) const;
            bool operator >= ( UInt8 value ) const;
            bool operator >= ( UInt16 value ) const;
            bool operator >= ( UInt32 value ) const;
            bool operator >= ( UInt64 value ) const;
            bool operator >= ( Float32 value ) const;
            bool operator >= ( Float64 value ) const;
            
            bool operator <= ( const Number & value ) const;
            bool operator <= ( CFNumberRef value ) const;
            bool operator <= ( SInt8 value ) const;
            bool operator <= ( SInt16 value ) const;
            bool operator <= ( SInt32 value ) const;
            bool operator <= ( SInt64 value ) const;
            bool operator <= ( UInt8 value ) const;
            bool operator <= ( UInt16 value ) const;
            bool operator <= ( UInt32 value ) const;
            bool operator <= ( UInt64 value ) const;
            bool operator <= ( Float32 value ) const;
            bool operator <= ( Float64 value ) const;
            
            bool operator > ( const Number & value ) const;
            bool operator > ( CFNumberRef value ) const;
            bool operator > ( SInt8 value ) const;
            bool operator > ( SInt16 value ) const;
            bool operator > ( SInt32 value ) const;
            bool operator > ( SInt64 value ) const;
            bool operator > ( UInt8 value ) const;
            bool operator > ( UInt16 value ) const;
            bool operator > ( UInt32 value ) const;
            bool operator > ( UInt64 value ) const;
            bool operator > ( Float32 value ) const;
            bool operator > ( Float64 value ) const;
            
            bool operator < ( const Number & value ) const;
            bool operator < ( CFNumberRef value ) const;
            bool operator < ( SInt8 value ) const;
            bool operator < ( SInt16 value ) const;
            bool operator < ( SInt32 value ) const;
            bool operator < ( SInt64 value ) const;
            bool operator < ( UInt8 value ) const;
            bool operator < ( UInt16 value ) const;
            bool operator < ( UInt32 value ) const;
            bool operator < ( UInt64 value ) const;
            bool operator < ( Float32 value ) const;
            bool operator < ( Float64 value ) const;
            
            bool operator && ( const Number & value );
            bool operator && ( CFNumberRef value );
            bool operator && ( SInt8 value );
            bool operator && ( SInt16 value );
            bool operator && ( SInt32 value );
            bool operator && ( SInt64 value );
            bool operator && ( UInt8 value );
            bool operator && ( UInt16 value );
            bool operator && ( UInt32 value );
            bool operator && ( UInt64 value );
            bool operator && ( Float32 value );
            bool operator && ( Float64 value );
            
            bool operator || ( const Number & value );
            bool operator || ( CFNumberRef value );
            bool operator || ( SInt8 value );
            bool operator || ( SInt16 value );
            bool operator || ( SInt32 value );
            bool operator || ( SInt64 value );
            bool operator || ( UInt8 value );
            bool operator || ( UInt16 value );
            bool operator || ( UInt32 value );
            bool operator || ( UInt64 value );
            bool operator || ( Float32 value );
            bool operator || ( Float64 value );
            
            Number & operator ~ ( void );
            Number & operator ! ( void );
            Number & operator ++ ( void );
            Number   operator ++ ( int );
            Number & operator -- ( void );
            Number   operator -- ( int );
            
            Number & operator += ( const Number & value );
            Number & operator += ( CFNumberRef value );
            Number & operator += ( SInt8 value );
            Number & operator += ( SInt16 value );
            Number & operator += ( SInt32 value );
            Number & operator += ( SInt64 value );
            Number & operator += ( UInt8 value );
            Number & operator += ( UInt16 value );
            Number & operator += ( UInt32 value );
            Number & operator += ( UInt64 value );
            Number & operator += ( Float32 value );
            Number & operator += ( Float64 value );
            
            Number & operator -= ( const Number & value );
            Number & operator -= ( CFNumberRef value );
            Number & operator -= ( SInt8 value );
            Number & operator -= ( SInt16 value );
            Number & operator -= ( SInt32 value );
            Number & operator -= ( SInt64 value );
            Number & operator -= ( UInt8 value );
            Number & operator -= ( UInt16 value );
            Number & operator -= ( UInt32 value );
            Number & operator -= ( UInt64 value );
            Number & operator -= ( Float32 value );
            Number & operator -= ( Float64 value );
            
            Number & operator *= ( const Number & value );
            Number & operator *= ( CFNumberRef value );
            Number & operator *= ( SInt8 value );
            Number & operator *= ( SInt16 value );
            Number & operator *= ( SInt32 value );
            Number & operator *= ( SInt64 value );
            Number & operator *= ( UInt8 value );
            Number & operator *= ( UInt16 value );
            Number & operator *= ( UInt32 value );
            Number & operator *= ( UInt64 value );
            Number & operator *= ( Float32 value );
            Number & operator *= ( Float64 value );
            
            Number & operator /= ( const Number & value );
            Number & operator /= ( CFNumberRef value );
            Number & operator /= ( SInt8 value );
            Number & operator /= ( SInt16 value );
            Number & operator /= ( SInt32 value );
            Number & operator /= ( SInt64 value );
            Number & operator /= ( UInt8 value );
            Number & operator /= ( UInt16 value );
            Number & operator /= ( UInt32 value );
            Number & operator /= ( UInt64 value );
            Number & operator /= ( Float32 value );
            Number & operator /= ( Float64 value );
            
            Number & operator |= ( const Number & value );
            Number & operator |= ( CFNumberRef value );
            Number & operator |= ( SInt8 value );
            Number & operator |= ( SInt16 value );
            Number & operator |= ( SInt32 value );
            Number & operator |= ( SInt64 value );
            Number & operator |= ( UInt8 value );
            Number & operator |= ( UInt16 value );
            Number & operator |= ( UInt32 value );
            Number & operator |= ( UInt64 value );
            Number & operator |= ( Float32 value );
            Number & operator |= ( Float64 value );
            
            Number & operator &= ( const Number & value );
            Number & operator &= ( CFNumberRef value );
            Number & operator &= ( SInt8 value );
            Number & operator &= ( SInt16 value );
            Number & operator &= ( SInt32 value );
            Number & operator &= ( SInt64 value );
            Number & operator &= ( UInt8 value );
            Number & operator &= ( UInt16 value );
            Number & operator &= ( UInt32 value );
            Number & operator &= ( UInt64 value );
            Number & operator &= ( Float32 value );
            Number & operator &= ( Float64 value );
            
            Number & operator %= ( const Number & value );
            Number & operator %= ( CFNumberRef value );
            Number & operator %= ( SInt8 value );
            Number & operator %= ( SInt16 value );
            Number & operator %= ( SInt32 value );
            Number & operator %= ( SInt64 value );
            Number & operator %= ( UInt8 value );
            Number & operator %= ( UInt16 value );
            Number & operator %= ( UInt32 value );
            Number & operator %= ( UInt64 value );
            Number & operator %= ( Float32 value );
            Number & operator %= ( Float64 value );
            
            Number & operator ^= ( const Number & value );
            Number & operator ^= ( CFNumberRef value );
            Number & operator ^= ( SInt8 value );
            Number & operator ^= ( SInt16 value );
            Number & operator ^= ( SInt32 value );
            Number & operator ^= ( SInt64 value );
            Number & operator ^= ( UInt8 value );
            Number & operator ^= ( UInt16 value );
            Number & operator ^= ( UInt32 value );
            Number & operator ^= ( UInt64 value );
            Number & operator ^= ( Float32 value );
            Number & operator ^= ( Float64 value );
            
            Number & operator <<= ( const Number & value );
            Number & operator <<= ( CFNumberRef value );
            Number & operator <<= ( SInt8 value );
            Number & operator <<= ( SInt16 value );
            Number & operator <<= ( SInt32 value );
            Number & operator <<= ( SInt64 value );
            Number & operator <<= ( UInt8 value );
            Number & operator <<= ( UInt16 value );
            Number & operator <<= ( UInt32 value );
            Number & operator <<= ( UInt64 value );
            Number & operator <<= ( Float32 value );
            Number & operator <<= ( Float64 value );
            
            Number & operator >>= ( const Number & value );
            Number & operator >>= ( CFNumberRef value );
            Number & operator >>= ( SInt8 value );
            Number & operator >>= ( SInt16 value );
            Number & operator >>= ( SInt32 value );
            Number & operator >>= ( SInt64 value );
            Number & operator >>= ( UInt8 value );
            Number & operator >>= ( UInt16 value );
            Number & operator >>= ( UInt32 value );
            Number & operator >>= ( UInt64 value );
            Number & operator >>= ( Float32 value );
            Number & operator >>= ( Float64 value );
            
            Number operator + ( const Number & value );
            Number operator + ( CFNumberRef value );
            Number operator + ( SInt8 value );
            Number operator + ( SInt16 value );
            Number operator + ( SInt32 value );
            Number operator + ( SInt64 value );
            Number operator + ( UInt8 value );
            Number operator + ( UInt16 value );
            Number operator + ( UInt32 value );
            Number operator + ( UInt64 value );
            Number operator + ( Float32 value );
            Number operator + ( Float64 value );
            
            Number operator - ( const Number & value );
            Number operator - ( CFNumberRef value );
            Number operator - ( SInt8 value );
            Number operator - ( SInt16 value );
            Number operator - ( SInt32 value );
            Number operator - ( SInt64 value );
            Number operator - ( UInt8 value );
            Number operator - ( UInt16 value );
            Number operator - ( UInt32 value );
            Number operator - ( UInt64 value );
            Number operator - ( Float32 value );
            Number operator - ( Float64 value );
            
            Number operator * ( const Number & value );
            Number operator * ( CFNumberRef value );
            Number operator * ( SInt8 value );
            Number operator * ( SInt16 value );
            Number operator * ( SInt32 value );
            Number operator * ( SInt64 value );
            Number operator * ( UInt8 value );
            Number operator * ( UInt16 value );
            Number operator * ( UInt32 value );
            Number operator * ( UInt64 value );
            Number operator * ( Float32 value );
            Number operator * ( Float64 value );
            
            Number operator / ( const Number & value );
            Number operator / ( CFNumberRef value );
            Number operator / ( SInt8 value );
            Number operator / ( SInt16 value );
            Number operator / ( SInt32 value );
            Number operator / ( SInt64 value );
            Number operator / ( UInt8 value );
            Number operator / ( UInt16 value );
            Number operator / ( UInt32 value );
            Number operator / ( UInt64 value );
            Number operator / ( Float32 value );
            Number operator / ( Float64 value );
            
            Number operator % ( const Number & value );
            Number operator % ( CFNumberRef value );
            Number operator % ( SInt8 value );
            Number operator % ( SInt16 value );
            Number operator % ( SInt32 value );
            Number operator % ( SInt64 value );
            Number operator % ( UInt8 value );
            Number operator % ( UInt16 value );
            Number operator % ( UInt32 value );
            Number operator % ( UInt64 value );
            Number operator % ( Float32 value );
            Number operator % ( Float64 value );
            
            Number operator & ( const Number & value );
            Number operator & ( CFNumberRef value );
            Number operator & ( SInt8 value );
            Number operator & ( SInt16 value );
            Number operator & ( SInt32 value );
            Number operator & ( SInt64 value );
            Number operator & ( UInt8 value );
            Number operator & ( UInt16 value );
            Number operator & ( UInt32 value );
            Number operator & ( UInt64 value );
            Number operator & ( Float32 value );
            Number operator & ( Float64 value );
            
            Number operator | ( const Number & value );
            Number operator | ( CFNumberRef value );
            Number operator | ( SInt8 value );
            Number operator | ( SInt16 value );
            Number operator | ( SInt32 value );
            Number operator | ( SInt64 value );
            Number operator | ( UInt8 value );
            Number operator | ( UInt16 value );
            Number operator | ( UInt32 value );
            Number operator | ( UInt64 value );
            Number operator | ( Float32 value );
            Number operator | ( Float64 value );
            
            Number operator ^ ( const Number & value );
            Number operator ^ ( CFNumberRef value );
            Number operator ^ ( SInt8 value );
            Number operator ^ ( SInt16 value );
            Number operator ^ ( SInt32 value );
            Number operator ^ ( SInt64 value );
            Number operator ^ ( UInt8 value );
            Number operator ^ ( UInt16 value );
            Number operator ^ ( UInt32 value );
            Number operator ^ ( UInt64 value );
            Number operator ^ ( Float32 value );
            Number operator ^ ( Float64 value );
            
            Number operator << ( const Number & value );
            Number operator << ( CFNumberRef value );
            Number operator << ( SInt8 value );
            Number operator << ( SInt16 value );
            Number operator << ( SInt32 value );
            Number operator << ( SInt64 value );
            Number operator << ( UInt8 value );
            Number operator << ( UInt16 value );
            Number operator << ( UInt32 value );
            Number operator << ( UInt64 value );
            Number operator << ( Float32 value );
            Number operator << ( Float64 value );
            
            Number operator >> ( const Number & value );
            Number operator >> ( CFNumberRef value );
            Number operator >> ( SInt8 value );
            Number operator >> ( SInt16 value );
            Number operator >> ( SInt32 value );
            Number operator >> ( SInt64 value );
            Number operator >> ( UInt8 value );
            Number operator >> ( UInt16 value );
            Number operator >> ( UInt32 value );
            Number operator >> ( UInt64 value );
            Number operator >> ( Float32 value );
            Number operator >> ( Float64 value );
            
            operator SInt8   ();
            operator SInt16  ();
            operator SInt32  ();
            operator SInt64  ();
            operator UInt8   ();
            operator UInt16  ();
            operator UInt32  ();
            operator UInt64  ();
            operator Float32 ();
            operator Float64 ();
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            bool IsFloatType( void ) const;
            
            SInt8   GetSInt8Value( void ) const;
            SInt16  GetSInt16Value( void ) const;
            SInt32  GetSInt32Value( void ) const;
            SInt64  GetSInt64Value( void ) const;
            UInt8   GetUInt8Value( void ) const;
            UInt16  GetUInt16Value( void ) const;
            UInt32  GetUInt32Value( void ) const;
            UInt64  GetUInt64Value( void ) const;
            Float32 GetFloat32Value( void ) const;
            Float64 GetFloat64Value( void ) const;
            void    SetSInt8Value( SInt8 value );
            void    SetSInt16Value( SInt16 value );
            void    SetSInt32Value( SInt32 value );
            void    SetSInt64Value( SInt64 value );
            void    SetUInt8Value( UInt8 value );
            void    SetUInt16Value( UInt16 value );
            void    SetUInt32Value( UInt32 value );
            void    SetUInt64Value( UInt64 value );
            void    SetFloat32Value( Float32 value );
            void    SetFloat64Value( Float64 value );
            
            friend void swap( Number & v1, Number & v2 );
            
        private:
            
            CFNumberRef _cfObject;
    };
}

#endif /* __CFPP_NUMBER_H__ */
