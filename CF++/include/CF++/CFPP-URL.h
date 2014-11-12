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
 * @header      CFPP-URL.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFURLRef wrapper
 */

#ifndef __CFPP_URL_H__
#define __CFPP_URL_H__

#include <CF++/CFPP-Type.h>

namespace CF
{
    class URL: public Type
    {
        public:
            
            typedef enum
            {
                PartAll                 = 0x00,
                PartFileSystemPath      = 0x01,
                PartFragment            = 0x02,
                PartHostName            = 0x03,
                PartLastPathComponent   = 0x04,
                PartNetLocation         = 0x05,
                PartParameterString     = 0x06,
                PartPassword            = 0x07,
                PartPath                = 0x08,
                PartPathExtension       = 0x09,
                PartQueryString         = 0x0A,
                PartResourceSpecifier   = 0x0B,
                PartScheme              = 0x0C,
                PartStrictPath          = 0x0D,
                PartUserName            = 0x0E
            }
            Part;
            
            static URL FileSystemURL( std::string path, bool isDir = false );
            static URL FileSystemURL( CFTypeRef path, bool isDir = false );
            static URL FileSystemURL( CFStringRef path, bool isDir = false );
            
            URL( void );
            URL( const URL & value );
            URL( CFTypeRef value );
            URL( CFURLRef value );
            URL( CFStringRef value );
            URL( std::string value );
            
            virtual ~URL( void );
            
            URL & operator = ( const URL value );
            URL & operator = ( CFTypeRef value );
            URL & operator = ( CFURLRef value );
            URL & operator = ( CFStringRef value );
            URL & operator = ( std::string value );
            
            bool operator == ( const URL & value );
            bool operator == ( CFTypeRef value );
            bool operator == ( CFURLRef value );
            bool operator == ( CFStringRef value );
            bool operator == ( std::string value );
            
            bool operator != ( const URL & value );
            bool operator != ( CFTypeRef value );
            bool operator != ( CFURLRef value );
            bool operator != ( CFStringRef value );
            bool operator != ( std::string value );
            
            CF::URL & operator /= ( CFStringRef value );
            CF::URL & operator /= ( std::string value );
            
            std::string operator [] ( Part part );
            
            operator std::string ();
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            CF::String GetFileSystemPath( CFURLPathStyle style = kCFURLPOSIXPathStyle );
            CF::String GetFragment( void );
            CF::String GetHostName( void );
            CF::String GetLastPathComponent( void );
            CF::String GetNetLocation( void );
            CF::String GetParameterString( void );
            CF::String GetPassword( void );
            CF::String GetPath( void );
            CF::String GetPathExtension( void );
            CF::String GetQueryString( void );
            CF::String GetResourceSpecifier( void );
            CF::String GetScheme( void );
            CF::String GetStrictPath( void );
            CF::String GetUserName( void );
            CF::Number GetPortNumber( void );
            bool       HasDirectoryPath( void );
            void       AppendPathComponent( CFStringRef component, bool isDirectory = false );
            void       AppendPathComponent( std::string component, bool isDirectory = false );
            void       AppendPathExtension( CFStringRef extension );
            void       AppendPathExtension( std::string extension );
            void       DeleteLastPathComponent( void );
            void       DeletePathExtension( void );
            
        private:
            
            CFURLRef _cfObject;
    };
}

#endif /* __CFPP_URL_H__ */
