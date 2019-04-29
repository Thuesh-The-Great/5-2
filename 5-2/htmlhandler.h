#ifndef HTML_H
#define HTML_H

#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>
//#include <fstream>

using namespace std;

class HTML
{
	
public:
		
    HTML();
	
	~HTML();

    void start();

    void end();

    bool getStart();

    int getNumberOfHeaders();

    int getHeaderType();

    int getNumberOfParagraphs();

	void makeParagraph();

	void endOfParagraph();
	
	void makeHeader( int a );
	
    void endOfHeader();

	void makeBreak();

	void makeThematicBreak();

	void makeTitle();
	
	void endOfTitle();
	
    void makeFont( QString face, int size, QString color );
	
	void endOfFont();
	
    void context( QString message );

	void enter();

    void operator =( const HTML & );
	
		
private:
    QFile stream;
    bool ifstart;
    int numberOfOpenHeaders;
    int headerType;
    int numberOfParagraphs;
};


#endif
