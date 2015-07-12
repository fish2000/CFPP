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

/*!
 * @file        Test-CFPP-URL.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::URL
 */

#include <CF++.hpp>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( CFPP_URL, FileSystemURL_STDString )
{
    CF::URL u1 = CF::URL::FileSystemURL( std::string( "/etc/hosts" ) );
    CF::URL u2 = CF::URL::FileSystemURL( std::string( "/foo/bar" ) );
    CF::URL u3 = CF::URL::FileSystemURL( std::string( "" ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_TRUE(  u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
}

TEST( CFPP_URL, FileSystemURL_CChar )
{
    CF::URL u1 = CF::URL::FileSystemURL( "/etc/hosts" );
    CF::URL u2 = CF::URL::FileSystemURL( "/foo/bar" );
    CF::URL u3 = CF::URL::FileSystemURL( "" );
    CF::URL u4 = CF::URL::FileSystemURL( static_cast< const char * >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_TRUE(  u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
    ASSERT_FALSE( u4.IsValid() );
}

TEST( CFPP_URL, FileSystemURL_CFType )
{
    CF::URL u1 = CF::URL::FileSystemURL( static_cast< CFTypeRef >( CF::String( "/etc/hosts" ) ) );
    CF::URL u2 = CF::URL::FileSystemURL( static_cast< CFTypeRef >( CF::String( "/foo/bar" ) ) );
    CF::URL u3 = CF::URL::FileSystemURL( static_cast< CFTypeRef >( CF::String( "" ) ) );
    CF::URL u4 = CF::URL::FileSystemURL( static_cast< CFTypeRef >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_TRUE(  u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
    ASSERT_FALSE( u4.IsValid() );
}

TEST( CFPP_URL, FileSystemURL_CFString )
{
    CF::URL u1 = CF::URL::FileSystemURL( static_cast< CFStringRef >( CF::String( "/etc/hosts" ) ) );
    CF::URL u2 = CF::URL::FileSystemURL( static_cast< CFStringRef >( CF::String( "/foo/bar" ) ) );
    CF::URL u3 = CF::URL::FileSystemURL( static_cast< CFStringRef >( CF::String( "" ) ) );
    CF::URL u4 = CF::URL::FileSystemURL( static_cast< CFStringRef >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_TRUE(  u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
    ASSERT_FALSE( u4.IsValid() );
}

TEST( CFPP_URL, CTOR )
{
    CF::URL u;
    
    ASSERT_FALSE( u.IsValid() );
}

TEST( CFPP_URL, CTOR_CFType )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2( static_cast< CFTypeRef >( u1.GetCFObject() ) );
    CF::URL u3( static_cast< CFTypeRef >( NULL ) );
    
    ASSERT_TRUE(  u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
}

TEST( CFPP_URL, CTOR_CFURL )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2( static_cast< CFURLRef >( u1.GetCFObject() ) );
    CF::URL u3( static_cast< CFURLRef >( NULL ) );
    
    ASSERT_TRUE(  u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
}

TEST( CFPP_URL, CTOR_CFString )
{
    CF::URL u1( static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) ) );
    CF::URL u2( static_cast< CFStringRef >( CF::String( "" ) ) );
    CF::URL u3( static_cast< CFStringRef >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_FALSE( u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
}

TEST( CFPP_URL, CTOR_STDString )
{
    CF::URL u1( std::string( "http://www.xs-labs.com/" ) );
    CF::URL u2( std::string( "" ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_FALSE( u2.IsValid() );
}

TEST( CFPP_URL, CTOR_CChar )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2( "" );
    CF::URL u3( static_cast< const char * >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_FALSE( u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
}

TEST( CFPP_URL, CCTOR )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2( u1 );
    CF::URL u3( static_cast< const char * >( NULL ) );
    CF::URL u4( u3 );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_TRUE(  u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
    ASSERT_FALSE( u4.IsValid() );
}

#ifdef CFPP_HAS_CPP11
TEST( CFPP_URL, MCTOR )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2( std::move( u1 ) );
    
    ASSERT_FALSE( u1.IsValid() );
    ASSERT_TRUE(  u2.IsValid() );
}
#endif

TEST( CFPP_URL, OperatorAssignURL )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2;
    CF::URL u3( static_cast< const char * >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_FALSE( u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
    
    u2 = u1;
    
    ASSERT_TRUE( u2.IsValid() );
    
    u2 = u3;
    
    ASSERT_FALSE( u2.IsValid() );
}

TEST( CFPP_URL, OperatorAssignCFType )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2;
    CF::URL u3( static_cast< const char * >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_FALSE( u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
    
    u2 = static_cast< CFTypeRef >( u1.GetCFObject() );
    
    ASSERT_TRUE( u2.IsValid() );
    
    u2 = static_cast< CFTypeRef >( u3.GetCFObject() );
    
    ASSERT_FALSE( u2.IsValid() );
}

TEST( CFPP_URL, OperatorAssignCFURL )
{
    CF::URL u1( "http://www.xs-labs.com/" );
    CF::URL u2;
    CF::URL u3( static_cast< const char * >( NULL ) );
    
    ASSERT_TRUE(  u1.IsValid() );
    ASSERT_FALSE( u2.IsValid() );
    ASSERT_FALSE( u3.IsValid() );
    
    u2 = static_cast< CFURLRef >( u1.GetCFObject() );
    
    ASSERT_TRUE( u2.IsValid() );
    
    u2 = static_cast< CFURLRef >( u3.GetCFObject() );
    
    ASSERT_FALSE( u2.IsValid() );
}

TEST( CFPP_URL, OperatorAssignCFString )
{
    CF::URL u;
    
    ASSERT_FALSE( u.IsValid() );
    
    u = static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) );
    
    ASSERT_TRUE( u.IsValid() );
    
    u = static_cast< CFStringRef >( CF::String( "" ) );
    
    ASSERT_FALSE( u.IsValid() );
    
    u = static_cast< CFStringRef >( NULL );
    
    ASSERT_FALSE( u.IsValid() );
}

TEST( CFPP_URL, OperatorAssignSTDString )
{
    CF::URL u;
    
    ASSERT_FALSE( u.IsValid() );
    
    u = std::string( "http://www.xs-labs.com/" );
    
    ASSERT_TRUE( u.IsValid() );
    
    u = std::string( "" );
    
    ASSERT_FALSE( u.IsValid() );
}

TEST( CFPP_URL, OperatorAssignCChar )
{
    CF::URL u;
    
    ASSERT_FALSE( u.IsValid() );
    
    u = "http://www.xs-labs.com/";
    
    ASSERT_TRUE( u.IsValid() );
    
    u = "";
    
    ASSERT_FALSE( u.IsValid() );
    
    u = static_cast< const char * >( NULL );
    
    ASSERT_FALSE( u.IsValid() );
}

TEST( CFPP_URL, OperatorEqualURL )
{
    CF::URL u1;
    CF::URL u2;
    CF::URL u3( "http://www.xs-labs.com/" );
    CF::URL u4( "http://www.xs-labs.com/" );
    CF::URL u5( "http://www.xs-labs.org/" );
    
    ASSERT_FALSE( u1 == u1 );
    ASSERT_FALSE( u1 == u2 );
    ASSERT_FALSE( u1 == u3 );
    ASSERT_FALSE( u1 == u4 );
    ASSERT_FALSE( u1 == u5 );
    
    ASSERT_FALSE( u3 == u1 );
    ASSERT_FALSE( u3 == u2 );
    ASSERT_TRUE(  u3 == u3 );
    ASSERT_TRUE(  u3 == u4 );
    ASSERT_FALSE( u3 == u5 );
    
    ASSERT_FALSE( u5 == u1 );
    ASSERT_FALSE( u5 == u2 );
    ASSERT_FALSE( u5 == u3 );
    ASSERT_FALSE( u5 == u4 );
    ASSERT_TRUE(  u5 == u5 );
}

TEST( CFPP_URL, OperatorEqualCFType )
{
    CF::URL u1;
    CF::URL u2;
    CF::URL u3( "http://www.xs-labs.com/" );
    CF::URL u4( "http://www.xs-labs.com/" );
    CF::URL u5( "http://www.xs-labs.org/" );
    
    ASSERT_FALSE( u1 == static_cast< CFTypeRef >( u1.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFTypeRef >( u2.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFTypeRef >( u3.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFTypeRef >( u4.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFTypeRef >( u5.GetCFObject() ) );
    
    ASSERT_FALSE( u3 == static_cast< CFTypeRef >( u1.GetCFObject() ) );
    ASSERT_FALSE( u3 == static_cast< CFTypeRef >( u2.GetCFObject() ) );
    ASSERT_TRUE(  u3 == static_cast< CFTypeRef >( u3.GetCFObject() ) );
    ASSERT_TRUE(  u3 == static_cast< CFTypeRef >( u4.GetCFObject() ) );
    ASSERT_FALSE( u3 == static_cast< CFTypeRef >( u5.GetCFObject() ) );
    
    ASSERT_FALSE( u5 == static_cast< CFTypeRef >( u1.GetCFObject() ) );
    ASSERT_FALSE( u5 == static_cast< CFTypeRef >( u2.GetCFObject() ) );
    ASSERT_FALSE( u5 == static_cast< CFTypeRef >( u3.GetCFObject() ) );
    ASSERT_FALSE( u5 == static_cast< CFTypeRef >( u4.GetCFObject() ) );
    ASSERT_TRUE(  u5 == static_cast< CFTypeRef >( u5.GetCFObject() ) );
}

TEST( CFPP_URL, OperatorEqualCFURL )
{
    CF::URL u1;
    CF::URL u2;
    CF::URL u3( "http://www.xs-labs.com/" );
    CF::URL u4( "http://www.xs-labs.com/" );
    CF::URL u5( "http://www.xs-labs.org/" );
    
    ASSERT_FALSE( u1 == static_cast< CFURLRef >( u1.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFURLRef >( u2.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFURLRef >( u3.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFURLRef >( u4.GetCFObject() ) );
    ASSERT_FALSE( u1 == static_cast< CFURLRef >( u5.GetCFObject() ) );
    
    ASSERT_FALSE( u3 == static_cast< CFURLRef >( u1.GetCFObject() ) );
    ASSERT_FALSE( u3 == static_cast< CFURLRef >( u2.GetCFObject() ) );
    ASSERT_TRUE(  u3 == static_cast< CFURLRef >( u3.GetCFObject() ) );
    ASSERT_TRUE(  u3 == static_cast< CFURLRef >( u4.GetCFObject() ) );
    ASSERT_FALSE( u3 == static_cast< CFURLRef >( u5.GetCFObject() ) );
    
    ASSERT_FALSE( u5 == static_cast< CFURLRef >( u1.GetCFObject() ) );
    ASSERT_FALSE( u5 == static_cast< CFURLRef >( u2.GetCFObject() ) );
    ASSERT_FALSE( u5 == static_cast< CFURLRef >( u3.GetCFObject() ) );
    ASSERT_FALSE( u5 == static_cast< CFURLRef >( u4.GetCFObject() ) );
    ASSERT_TRUE(  u5 == static_cast< CFURLRef >( u5.GetCFObject() ) );
}

TEST( CFPP_URL, OperatorEqualCFString )
{
    CF::URL u1;
    CF::URL u2( "http://www.xs-labs.com/" );
    CF::URL u3( "http://www.xs-labs.org/" );
    
    ASSERT_FALSE( u1 == static_cast< CFStringRef >( CF::String( "" ) ) );
    ASSERT_FALSE( u1 == static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) ) );
    ASSERT_FALSE( u1 == static_cast< CFStringRef >( CF::String( "http://www.xs-labs.org/" ) ) );
    
    ASSERT_FALSE( u2 == static_cast< CFStringRef >( CF::String( "" ) ) );
    ASSERT_TRUE(  u2 == static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) ) );
    ASSERT_FALSE( u2 == static_cast< CFStringRef >( CF::String( "http://www.xs-labs.org/" ) ) );
    
    ASSERT_FALSE( u3 == static_cast< CFStringRef >( CF::String( "" ) ) );
    ASSERT_FALSE( u3 == static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) ) );
    ASSERT_TRUE(  u3 == static_cast< CFStringRef >( CF::String( "http://www.xs-labs.org/" ) ) );
}

TEST( CFPP_URL, OperatorEqualSTDString )
{
    CF::URL u1;
    CF::URL u2( "http://www.xs-labs.com/" );
    CF::URL u3( "http://www.xs-labs.org/" );
    
    ASSERT_FALSE( u1 == std::string( "" ) );
    ASSERT_FALSE( u1 == std::string( "http://www.xs-labs.com/" ) );
    ASSERT_FALSE( u1 == std::string( "http://www.xs-labs.org/" ) );
    
    ASSERT_FALSE( u2 == std::string( "" ) );
    ASSERT_TRUE(  u2 == std::string( "http://www.xs-labs.com/" ) );
    ASSERT_FALSE( u2 == std::string( "http://www.xs-labs.org/" ) );
    
    ASSERT_FALSE( u3 == std::string( "" ) );
    ASSERT_FALSE( u3 == std::string( "http://www.xs-labs.com/" ) );
    ASSERT_TRUE(  u3 == std::string( "http://www.xs-labs.org/" ) );
}

TEST( CFPP_URL, OperatorNotEqualURL )
{
    CF::URL u1;
    CF::URL u2;
    CF::URL u3( "http://www.xs-labs.com/" );
    CF::URL u4( "http://www.xs-labs.com/" );
    CF::URL u5( "http://www.xs-labs.org/" );
    
    ASSERT_TRUE( u1 != u1 );
    ASSERT_TRUE( u1 != u2 );
    ASSERT_TRUE( u1 != u3 );
    ASSERT_TRUE( u1 != u4 );
    ASSERT_TRUE( u1 != u5 );
    
    ASSERT_TRUE(  u3 != u1 );
    ASSERT_TRUE(  u3 != u2 );
    ASSERT_FALSE( u3 != u3 );
    ASSERT_FALSE( u3 != u4 );
    ASSERT_TRUE(  u3 != u5 );
    
    ASSERT_TRUE(  u5 != u1 );
    ASSERT_TRUE(  u5 != u2 );
    ASSERT_TRUE(  u5 != u3 );
    ASSERT_TRUE(  u5 != u4 );
    ASSERT_FALSE( u5 != u5 );
}

TEST( CFPP_URL, OperatorNotEqualCFType )
{
    CF::URL u1;
    CF::URL u2;
    CF::URL u3( "http://www.xs-labs.com/" );
    CF::URL u4( "http://www.xs-labs.com/" );
    CF::URL u5( "http://www.xs-labs.org/" );
    
    ASSERT_TRUE( u1 != static_cast< CFTypeRef >( u1.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFTypeRef >( u2.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFTypeRef >( u3.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFTypeRef >( u4.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFTypeRef >( u5.GetCFObject() ) );
    
    ASSERT_TRUE(  u3 != static_cast< CFTypeRef >( u1.GetCFObject() ) );
    ASSERT_TRUE(  u3 != static_cast< CFTypeRef >( u2.GetCFObject() ) );
    ASSERT_FALSE( u3 != static_cast< CFTypeRef >( u3.GetCFObject() ) );
    ASSERT_FALSE( u3 != static_cast< CFTypeRef >( u4.GetCFObject() ) );
    ASSERT_TRUE(  u3 != static_cast< CFTypeRef >( u5.GetCFObject() ) );
    
    ASSERT_TRUE(  u5 != static_cast< CFTypeRef >( u1.GetCFObject() ) );
    ASSERT_TRUE(  u5 != static_cast< CFTypeRef >( u2.GetCFObject() ) );
    ASSERT_TRUE(  u5 != static_cast< CFTypeRef >( u3.GetCFObject() ) );
    ASSERT_TRUE(  u5 != static_cast< CFTypeRef >( u4.GetCFObject() ) );
    ASSERT_FALSE( u5 != static_cast< CFTypeRef >( u5.GetCFObject() ) );
}

TEST( CFPP_URL, OperatorNotEqualCFURL )
{
    CF::URL u1;
    CF::URL u2;
    CF::URL u3( "http://www.xs-labs.com/" );
    CF::URL u4( "http://www.xs-labs.com/" );
    CF::URL u5( "http://www.xs-labs.org/" );
    
    ASSERT_TRUE( u1 != static_cast< CFURLRef >( u1.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFURLRef >( u2.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFURLRef >( u3.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFURLRef >( u4.GetCFObject() ) );
    ASSERT_TRUE( u1 != static_cast< CFURLRef >( u5.GetCFObject() ) );
    
    ASSERT_TRUE(  u3 != static_cast< CFURLRef >( u1.GetCFObject() ) );
    ASSERT_TRUE(  u3 != static_cast< CFURLRef >( u2.GetCFObject() ) );
    ASSERT_FALSE( u3 != static_cast< CFURLRef >( u3.GetCFObject() ) );
    ASSERT_FALSE( u3 != static_cast< CFURLRef >( u4.GetCFObject() ) );
    ASSERT_TRUE(  u3 != static_cast< CFURLRef >( u5.GetCFObject() ) );
    
    ASSERT_TRUE(  u5 != static_cast< CFURLRef >( u1.GetCFObject() ) );
    ASSERT_TRUE(  u5 != static_cast< CFURLRef >( u2.GetCFObject() ) );
    ASSERT_TRUE(  u5 != static_cast< CFURLRef >( u3.GetCFObject() ) );
    ASSERT_TRUE(  u5 != static_cast< CFURLRef >( u4.GetCFObject() ) );
    ASSERT_FALSE( u5 != static_cast< CFURLRef >( u5.GetCFObject() ) );
}

TEST( CFPP_URL, OperatorNotEqualCFString )
{
    CF::URL u1;
    CF::URL u2( "http://www.xs-labs.com/" );
    CF::URL u3( "http://www.xs-labs.org/" );
    
    ASSERT_TRUE( u1 != static_cast< CFStringRef >( CF::String( "" ) ) );
    ASSERT_TRUE( u1 != static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) ) );
    ASSERT_TRUE( u1 != static_cast< CFStringRef >( CF::String( "http://www.xs-labs.org/" ) ) );
    
    ASSERT_TRUE(  u2 != static_cast< CFStringRef >( CF::String( "" ) ) );
    ASSERT_FALSE( u2 != static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) ) );
    ASSERT_TRUE(  u2 != static_cast< CFStringRef >( CF::String( "http://www.xs-labs.org/" ) ) );
    
    ASSERT_TRUE(  u3 != static_cast< CFStringRef >( CF::String( "" ) ) );
    ASSERT_TRUE(  u3 != static_cast< CFStringRef >( CF::String( "http://www.xs-labs.com/" ) ) );
    ASSERT_FALSE( u3 != static_cast< CFStringRef >( CF::String( "http://www.xs-labs.org/" ) ) );
}

TEST( CFPP_URL, OperatorNotEqualSTDString )
{
    CF::URL u1;
    CF::URL u2( "http://www.xs-labs.com/" );
    CF::URL u3( "http://www.xs-labs.org/" );
    
    ASSERT_TRUE( u1 != std::string( "" ) );
    ASSERT_TRUE( u1 != std::string( "http://www.xs-labs.com/" ) );
    ASSERT_TRUE( u1 != std::string( "http://www.xs-labs.org/" ) );
    
    ASSERT_TRUE(  u2 != std::string( "" ) );
    ASSERT_FALSE( u2 != std::string( "http://www.xs-labs.com/" ) );
    ASSERT_TRUE(  u2 != std::string( "http://www.xs-labs.org/" ) );
    
    ASSERT_TRUE(  u3 != std::string( "" ) );
    ASSERT_TRUE(  u3 != std::string( "http://www.xs-labs.com/" ) );
    ASSERT_FALSE( u3 != std::string( "http://www.xs-labs.org/" ) );
}

TEST( CFPP_URL, OperatorDivideCFString )
{}

TEST( CFPP_URL, OperatorDivideSTDString )
{}

TEST( CFPP_URL, OperatorSubscript )
{}

TEST( CFPP_URL, CastToString )
{}

TEST( CFPP_URL, GetTypeID )
{}

TEST( CFPP_URL, GetCFObject )
{}

TEST( CFPP_URL, GetFileSystemPath )
{}

TEST( CFPP_URL, GetFragment )
{}

TEST( CFPP_URL, GetHostName )
{}

TEST( CFPP_URL, GetLastPathComponent )
{}

TEST( CFPP_URL, GetNetLocation )
{}

TEST( CFPP_URL, GetParameterString )
{}

TEST( CFPP_URL, GetPassword )
{}

TEST( CFPP_URL, GetPath )
{}

TEST( CFPP_URL, GetPathExtension )
{}

TEST( CFPP_URL, GetQueryString )
{}

TEST( CFPP_URL, GetResourceSpecifier )
{}

TEST( CFPP_URL, GetScheme )
{}

TEST( CFPP_URL, GetStrictPath )
{}

TEST( CFPP_URL, GetUserName )
{}

TEST( CFPP_URL, GetPortNumber )
{}

TEST( CFPP_URL, HasDirectoryPath )
{}

TEST( CFPP_URL, AppendPathComponent_CFString )
{}

TEST( CFPP_URL, AppendPathComponent_STDString )
{}

TEST( CFPP_URL, AppendPathExtension_CFString )
{}

TEST( CFPP_URL, AppendPathExtension_STDString )
{}

TEST( CFPP_URL, DeleteLastPathComponent )
{}

TEST( CFPP_URL, DeletePathExtension )
{}

TEST( CFPP_URL, Swap )
{}
