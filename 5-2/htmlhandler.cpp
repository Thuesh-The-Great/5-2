#include "htmlhandler.h" 
#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
//#include <fstream>

using namespace std;
		
    HTML::HTML( )
    {

        stream.setFileName( "myHtml.html" );
        stream.open( QIODevice::WriteOnly );
        ifstart = false;
        numberOfOpenHeaders = 0;
	}
	
	HTML::~HTML()
	{
        stream.close();
	}

    void HTML::start()
    {
        QTextStream out( &stream );
        out << "<html>" << endl;
        ifstart = true;
    }

    void HTML::end()
    {
        QTextStream out( &stream );
        out << "</html>" << endl;
    }

    bool HTML::getStart()
    {
        return ifstart;
    }

    int HTML::getNumberOfHeaders()
    {
        return numberOfOpenHeaders;
    }

    int HTML::getHeaderType()
    {
        return headerType;
    }

    int HTML::getNumberOfParagraphs()
    {
        return numberOfParagraphs;
    }

	void HTML::makeParagraph()
	{
        QTextStream out( &stream );
        out << "<p>";
	}

	void HTML::endOfParagraph()
	{
        QTextStream out( &stream );
        out << "</p>" << endl;
	}
	
	void HTML::makeHeader( int a )
	{
        headerType = a;
        numberOfOpenHeaders++;
        QTextStream out( &stream );
        out << "<h" << a << ">";
	}
	
    void HTML::endOfHeader()
	{
        numberOfOpenHeaders--;
        QTextStream out( &stream );
        out << "</h" << headerType << ">" << endl;
	}
	
	void HTML::makeBreak()
	{
        QTextStream out( &stream );
        out << "<br>" << endl;
	}
	
	void HTML::makeThematicBreak()
	{
        QTextStream out( &stream );
        out << "<hr>" << endl;
	}
	
	void HTML::makeTitle()
	{
        QTextStream out( &stream );
        out << "<head>" << endl << "<title>";
	}
	
	void HTML::endOfTitle()
	{
        QTextStream out( &stream );
        out << "</title>" << endl << "<head>" << endl;
	}
	
    void HTML::makeFont( QString face, int size, QString color )
	{
        QTextStream out( &stream );
        out << "<font face = \"" << face << "\" size = \"" << size << "\" color = \"" << color << "\" >";
	}
	
	void HTML::endOfFont()
	{
        QTextStream out( &stream );
        out << "</font>" << endl;
	}
	
    void HTML::context(QString message )
	{
        QTextStream out( &stream );
        out << message;
	}
	
	void HTML::enter()
	{
        QTextStream out( &stream );
        out << endl;
	}

    void HTML::operator =( const HTML &ob  )
    {
        stream.setFileName( "myHtml.html" );
        stream.open( QIODevice::WriteOnly );
    }
	

