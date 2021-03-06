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
 * @file        CFPP-URL.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFURLRef wrapper
 */

#include <CF++.h>

namespace CF
{
    URL URL::FileSystemURL( std::string path, bool isDir )
    {
        URL        url;
        CFURLRef   cfURL;
        CF::String str;
        
        str = path;
        
        cfURL = CFURLCreateWithFileSystemPath
        (
            static_cast< CFAllocatorRef >( NULL ),
            str,
            #ifdef _WIN32
            kCFURLWindowsPathStyle,
            #else
            kCFURLPOSIXPathStyle,
            #endif
            isDir
        );
        
        url = cfURL;
        
        if( cfURL != NULL )
        {
            CFRelease( cfURL );
        }
        
        return url;
    }
    
    URL URL::FileSystemURL( CFTypeRef path, bool isDir )
    {
        CF::String str;
        
        str = path;
        
        return URL::FileSystemURL( str.GetValue(), isDir );
    }
    
    URL URL::FileSystemURL( CFStringRef path, bool isDir )
    {
        CF::String str;
        
        str = path;
        
        return URL::FileSystemURL( str.GetValue(), isDir );
    }
    
    URL::URL( void )
    {
        this->_cfObject = NULL;
    }
    
    URL::URL( const URL & value )
    {
        if( value._cfObject != NULL )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value._cfObject ) );
        }
    }
    
    URL::URL( CFTypeRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value ) );
        }
    }
    
    URL::URL( CFURLRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value ) );
        }
    }
    
    URL::URL( CFStringRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == CFStringGetTypeID() )
        {
            this->_cfObject = CFURLCreateWithString( static_cast< CFAllocatorRef >( NULL ), value, NULL );
        }
    }
    
    URL::URL( std::string value )
    {
        CF::String s;
        
        s = value;
        
        this->_cfObject = CFURLCreateWithString( static_cast< CFAllocatorRef >( NULL ), static_cast< CFStringRef >( s ), NULL );
    }
    
    #ifdef CFPP_HAS_CPP11
    URL::URL( URL && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = NULL;
    }
    #endif
    
    URL::~URL( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = NULL;
        }
    }
    
    URL & URL::operator = ( URL value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    URL & URL::operator = ( CFTypeRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    URL & URL::operator = ( CFURLRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    URL & URL::operator = ( CFStringRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == CFStringGetTypeID() )
        {
            this->_cfObject = CFURLCreateWithString( static_cast< CFAllocatorRef >( NULL ), value, NULL );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    URL & URL::operator = ( std::string value )
    {
        CF::String s;
        
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        s = value;
        
        this->_cfObject = CFURLCreateWithString( static_cast< CFAllocatorRef >( NULL ), static_cast< CFStringRef >( s ), NULL );
        
        return *( this );
    }
    
    std::string URL::operator [] ( Part part )
    {
        CF::String s;
        
        switch( part )
        {
            case PartAll:               s = static_cast< std::string >( *( this ) );    break;
            case PartFileSystemPath:    s = this->GetFileSystemPath();                  break;
            case PartFragment:          s = this->GetFragment();                        break;
            case PartHostName:          s = this->GetHostName();                        break;
            case PartLastPathComponent: s = this->GetLastPathComponent();               break;
            case PartNetLocation:       s = this->GetNetLocation();                     break;
            case PartParameterString:   s = this->GetParameterString();                 break;
            case PartPassword:          s = this->GetPassword();                        break;
            case PartPath:              s = this->GetPath();                            break;
            case PartPathExtension:     s = this->GetPathExtension();                   break;
            case PartQueryString:       s = this->GetQueryString();                     break;
            case PartResourceSpecifier: s = this->GetResourceSpecifier();               break;
            case PartScheme:            s = this->GetScheme();                          break;
            case PartStrictPath:        s = this->GetStrictPath();                      break;
            case PartUserName:          s = this->GetUserName();                        break;
        }
        
        return s.GetValue();
    }
    
    bool URL::operator == ( const URL & value )
    {
        std::string url1;
        std::string url2;
        
        url1 = static_cast< std::string >( *( this ) );
        url2 = static_cast< std::string >( const_cast< CF::URL & >( value ) );
        
        return url1 == url2;
    }
    
    bool URL::operator == ( CFTypeRef value )
    {
        CF::URL url;
        
        url = value;
        
        return *( this ) == url;
    }
    
    bool URL::operator == ( CFURLRef value )
    {
        CF::URL url;
        
        url = value;
        
        return *( this ) == url;
    }
    
    bool URL::operator == ( CFStringRef value )
    {
        CF::URL url;
        
        url = value;
        
        return *( this ) == url;
    }
    
    bool URL::operator == ( std::string value )
    {
        CF::URL url;
        
        url = value;
        
        return *( this ) == url;
    }
    
    bool URL::operator != ( const URL & value )
    {
        return !( *( this ) == value );
    }
    
    bool URL::operator != ( CFTypeRef value )
    {
        return !( *( this ) == value );
    }
    
    bool URL::operator != ( CFURLRef value )
    {
        return !( *( this ) == value );
    }
    
    bool URL::operator != ( CFStringRef value )
    {
        return !( *( this ) == value );
    }
    
    bool URL::operator != ( std::string value )
    {
        return !( *( this ) == value );
    }
    
    CF::URL & URL::operator /= ( CFStringRef value )
    {
        this->AppendPathComponent( value );
        
        return *( this );
    }
    
    CF::URL & URL::operator /= ( std::string value )
    {
        this->AppendPathComponent( value );
        
        return *( this );
    }
    
    URL::operator std::string ()
    {
        CF::String str;
        
        if( this->_cfObject == NULL )
        {
            return str.GetValue();
        }
        
        str = CFURLGetString( this->_cfObject );
        
        return str.GetValue();
    }
    
    CFTypeID URL::GetTypeID( void ) const
    {
        return CFURLGetTypeID();
    }
    
    CFTypeRef URL::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    CF::String URL::GetFileSystemPath( PathStyle style )
    {
        CF::String      str;
        CFStringRef     cfStr;
        CFURLPathStyle  cfPathStyle;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfPathStyle = ( style == PathStyleWindows ) ? kCFURLWindowsPathStyle : kCFURLPOSIXPathStyle;
        cfStr       = CFURLCopyFileSystemPath( this->_cfObject, cfPathStyle );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetFragment( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyFragment( this->_cfObject, NULL );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetHostName( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyHostName( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetLastPathComponent( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyLastPathComponent( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetNetLocation( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyNetLocation( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetParameterString( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyParameterString( this->_cfObject, NULL );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetPassword( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyPassword( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetPath( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyPath( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetPathExtension( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyPathExtension( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetQueryString( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyQueryString( this->_cfObject, NULL );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetResourceSpecifier( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyResourceSpecifier( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetScheme( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyScheme( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetStrictPath( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyStrictPath( this->_cfObject, NULL );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::String URL::GetUserName( void )
    {
        CF::String  str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFURLCopyUserName( this->_cfObject );
        
        if( cfStr != NULL )
        {
            str = cfStr;
            
            CFRelease( cfStr );
        }
        
        return str;
    }
    
    CF::Number URL::GetPortNumber( void )
    {
        CF::Number n;
        
        if( this->_cfObject == NULL )
        {
            return 0;
        }
        
        n.SetSInt32Value( CFURLGetPortNumber( this->_cfObject ) );
        
        return n;
    }
    
    bool URL::HasDirectoryPath( void )
    {
        if( this->_cfObject == NULL )
        {
            return false;
        }
        
        return ( CFURLHasDirectoryPath( this->_cfObject ) ) ? true : false;
    }
    
    void URL::AppendPathComponent( CFStringRef component, bool isDirectory )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyAppendingPathComponent
        (
            static_cast< CFAllocatorRef >( NULL ),
            url,
            component,
            isDirectory
        );
        
        CFRelease( url );
    }
    
    void URL::AppendPathComponent( std::string component, bool isDirectory )
    {
        CF::String s;
        
        s = component;
        
        this->AppendPathComponent( static_cast< CFStringRef >( s ), isDirectory );
    }
    
    void URL::AppendPathExtension( CFStringRef extension )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyAppendingPathExtension
        (
            static_cast< CFAllocatorRef >( NULL ),
            url,
            extension
        );
        
        CFRelease( url );
    }
    
    void URL::AppendPathExtension( std::string extension )
    {
        CF::String s;
        
        s = extension;
        
        this->AppendPathExtension( static_cast< CFStringRef >( s ) );
    }
    
    void URL::DeleteLastPathComponent( void )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyDeletingLastPathComponent
        (
            static_cast< CFAllocatorRef >( NULL ),
            url
        );
        
        CFRelease( url );
    }
    
    void URL::DeletePathExtension( void )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyDeletingPathExtension
        (
            static_cast< CFAllocatorRef >( NULL ),
            url
        );
        
        CFRelease( url );
    }
    
    void swap( URL & v1, URL & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
