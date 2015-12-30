#include <stdio.h>
#include <errno.h>

#include "../include/log.h"

#define LOG_STYLES_HELLO	( LOG_STYLE_DATETIMEMS | LOG_STYLE_LOGLEVEL | LOG_STYLE_PID | LOG_STYLE_TID | LOG_STYLE_SOURCE | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )

int test_hello()
{
	LOG		*g = NULL ;
	
	char		buffer[ 4096*10 + 1 ] = "" ;
	long		buflen = sizeof(buffer) - 1 ;
	
	g = CreateLogHandle() ;
	if( g == NULL )
	{
		printf( "������־���ʧ��errno[%d]\n" , errno );
		return -1;
	}
	
	SetLogOutput( g , LOG_OUTPUT_FILE , "./test_hello.log" , LOG_NO_OUTPUTFUNC );
	SetLogLevel( g , LOG_LEVEL_INFO );
	SetLogStyles( g , LOG_STYLES_HELLO , LOG_NO_STYLEFUNC );
	
	DebugLog( g , __FILE__ , __LINE__ , "hello DEBUG" );
	InfoLog( g , __FILE__ , __LINE__ , "hello INFO" );
	WarnLog( g , __FILE__ , __LINE__ , "hello WARN" );
	ErrorLog( g , __FILE__ , __LINE__ , "hello ERROR" );
	FatalLog( g , __FILE__ , __LINE__ , "hello FATAL" );
	
	InfoLog( g , __FILE__ , __LINE__ , "ok" );
	
	DestroyLogHandle( g );
	
	return 0;
}

int main()
{
	return -test_hello();
}
