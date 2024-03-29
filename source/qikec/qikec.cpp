
/*
 * Copyright (c) 2007
 *      Shrew Soft Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Redistributions in any form must be accompanied by information on
 *    how to obtain complete source code for the software and any
 *    accompanying software that uses the software.  The source code
 *    must either be included in the distribution or be available for no
 *    more than the cost of distribution plus a nominal fee, and must be
 *    freely redistributable under reasonable conditions.  For an
 *    executable file, complete source code means the source code for all
 *    modules it contains.  It does not include source code for modules or
 *    files that typically accompany the major components of the operating
 *    system on which the executable file runs.
 *
 * THIS SOFTWARE IS PROVIDED BY SHREW SOFT INC ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
 * NON-INFRINGEMENT, ARE DISCLAIMED.  IN NO EVENT SHALL SHREW SOFT INC
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * AUTHOR : Matthew Grooms
 *          mgrooms@shrew.net
 *
 */

#include "qikec.h"

const char * _QIKEC::app_name()
{
	static const char name[] = "qikec";
	return name;
}

bool _QIKEC::init( int argc, char ** argv, qikecRoot * setRoot )
{
	// store our root window

	r = setRoot;

	// load our command line options

	if( qikec.read_opts( argc, argv ) != OPT_RESULT_SUCCESS )
	{
		r->lineEditUsername->setEnabled( false );
		r->lineEditPassword->setEnabled( false );
		r->pushButtonConnect->setEnabled( false );

		qikec.show_help();

		return false;
	}

	if( !qikec.config_load())
	{
		r->lineEditUsername->setEnabled( false );
		r->lineEditPassword->setEnabled( false );
		r->pushButtonConnect->setEnabled( false );

		return false;
	}


	// tiriamo su lo username dal file di conf
	// credo esista una maniera migliore piuttosto che
	// usare get_string ma... vedremo
	char un[256];
	config.get_string( "client-saved-username", un, sizeof(un), 0 );
	if(strlen(un)){
		// printf("un %s\n",un);
		r->lineEditUsername->setText( un );
		r->lineEditPassword->setFocus();
	}

	// se viene passato in cli lo sovrascriviamo
	if( username.size())
	{
		username.asciiz();
		r->lineEditUsername->setText( username.text());
		r->lineEditPassword->setFocus();
	}

	if( password.size())
	{
		password.asciiz();
		r->lineEditPassword->setText( password.text());
		r->pushButtonConnect->setFocus();
	}

	if( !user_credentials())
		r->groupBoxCredentials->hide();

	return true;
}

bool _QIKEC::get_username()
{
	TextData data;
	QApplication::postEvent( r, new UsernameEvent( &data ));
	while( data.result == -1 )
		msleep( 10 );

	if( !data.text.length())
		return false;

	username.del();
	username.set(
		( const char * ) data.text.toUtf8(), data.text.length());

	return true;
}

bool _QIKEC::get_password()
{
	TextData data;
	QApplication::postEvent( r, new PasswordEvent( &data ));
	while( data.result == -1 )
		msleep( 10 );

	if( !data.text.length())
		return false;

	password.del();
	password.set(
		( const char * ) data.text.toUtf8(), data.text.length());

	return true;
}

bool _QIKEC::get_filepass( BDATA & path )
{
	log( STATUS_INFO, "file password required for %s\n", path.text());

	FilePassData PassData;
	PassData.filepath = path.text();

	QApplication::postEvent( r, new FilePassEvent( &PassData ));
	while( PassData.result == -1 )
		msleep( 10 );

	if( PassData.result == QDialog::Rejected )
		return false;

	QString text = PassData.password;
	fpass.del();
	fpass.set(
		( const char * ) text.toUtf8(), text.length());

	return true;
}

bool _QIKEC::set_status( long status, BDATA * text )
{
	log( status, text->text());

	return true;
}

bool _QIKEC::set_stats()
{
	QApplication::postEvent( r, new StatsEvent( stats ));

	return true;
}

bool _QIKEC::log( long code, const char * format, ... )
{
	char buff[1024];
	va_list list;
	va_start( list, format );
	vsnprintf( buff, sizeof(buff), format, list );

	// 2022-08-31 14:39:52
	// aggiungiamo un timestamp al log in gui
	// scriverlo ad ogni messaggio lo trovo troppo ingombrante
	// quindi lo aggiungo solo quando cambia
	time_t t = time(NULL);
	static time_t prev_t = 0;
    if(prev_t!=t){
    	prev_t=t;
	    struct tm *lt = localtime(&t);
	    static char prev_tstamp[256]="";
	    char tstamp[256];
	    strftime(tstamp,sizeof(tstamp),"%F %T\n",lt);
		QApplication::postEvent( r, new StatusEvent( tstamp, code ));
    }

	QApplication::postEvent( r, new StatusEvent( buff, code ));

	return true;
}
