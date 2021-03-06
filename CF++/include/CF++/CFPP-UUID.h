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
 * @header      CFPP-UUID.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFUUIDRef wrapper
 */

#ifndef __CFPP_UUID_H__
#define __CFPP_UUID_H__

#include <CF++/CFPP-Type.h>

namespace CF
{
    class UUID: public Type
    {
        public:
            
            UUID( void );
            UUID( const UUID & value );
            UUID( CFTypeRef value );
            UUID( CFUUIDRef value );
            
            #ifdef CFPP_HAS_CPP11
            UUID( UUID && value );
            #endif
            
            virtual ~UUID( void );
            
            UUID & operator = ( UUID value );
            UUID & operator = ( CFTypeRef value );
            UUID & operator = ( CFUUIDRef value );
            
            bool operator == ( const UUID & value ) const;
            bool operator == ( CFTypeRef value ) const;
            bool operator == ( CFUUIDRef value ) const;
            bool operator == ( std::string value ) const;
            
            bool operator != ( const UUID & value ) const;
            bool operator != ( CFTypeRef value ) const;
            bool operator != ( CFUUIDRef value ) const;
            bool operator != ( std::string value ) const;
            
            operator std::string ();
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            CF::String GetString( void ) const;
            
            friend void swap( UUID & v1, UUID & v2 );
            
        private:
            
            CFUUIDRef _cfObject;
    };
}

#endif /* __CFPP_UUID_H__ */
