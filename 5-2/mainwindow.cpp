#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
//#include <QMessageBox>

MainWindow::MainWindow( HTML &htmlArg, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    html = htmlArg;
    ui->endBtn->setVisible( false );
    ui->addHeadBtn->setVisible( false );
    ui->endHeadBtn->setVisible( false );
    ui->spinBox->setVisible( false );
    ui->contBtn -> setEnabled( false );
    ui->endTitBtn->setEnabled( false );
    ui->addBrBtn->setVisible( false );
    ui->addHrBtn->setVisible( false );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addHeadBtn_clicked()
{

    if( html.getNumberOfHeaders() == 0 )
    {
        QString str = "<h" + QString::number( ui->spinBox->value() ) + ">";
        ui->txtbox->insertPlainText( str); // -> append
        //setPlainText -> write
        ui->endHeadBtn->setVisible( true );
        html.makeHeader( ui->spinBox->value() );
        ui->addHeadBtn->setVisible( false );
        ui->spinBox->setEnabled( false );
    }

    else
    {
        QLabel *lbl = new QLabel( "Press Start!" );
        lbl->show();
    }
}

void MainWindow::on_startBtn_clicked()
{
    ui->txtbox->insertPlainText( "<html>\n" );
    html.start();
    ui->spinBox->setVisible( true );
    ui->addHeadBtn->setVisible( true);;
    ui->startBtn->setVisible( false );
    ui->endBtn->setVisible( true );
    ui->addBrBtn->setVisible( true );
    ui->addHrBtn->setVisible( true );


}

void MainWindow::on_endBtn_clicked()
{
    while( html.getNumberOfHeaders() != 0 )
    {
        html.endOfHeader();
    }
    html.end();
    close();
}

void MainWindow::on_contBtn_clicked()
{
    QString str = ui->insBox->toPlainText();
    html.context( str );

    ui->txtbox->insertPlainText( str );

    ui->insBox->clear();
    ui->contBtn ->setEnabled( false );
}

void MainWindow::on_endHeadBtn_clicked()
{
    html.endOfHeader();
    QString str = "</h" + QString::number( html.getHeaderType() ) + ">\n";
    ui->txtbox->insertPlainText( str );

    if(  html.getNumberOfHeaders() == 0 )
    {
        ui->endHeadBtn->setVisible( false );
        ui->addHeadBtn->setVisible( true );
        ui->spinBox->setEnabled( true );
    }
}

void MainWindow::on_insBox_textChanged()
{
    ui->contBtn->setEnabled( true );
}


void MainWindow::on_enterBtn_clicked()
{
    html.enter();
    ui->txtbox->insertPlainText( "\n" );
}

void MainWindow::on_addParBtn_clicked()
{
    if( html.getStart() )
    {
        if( html.getNumberOfParagraphs() == 0 )
        {
            html.makeParagraph();
            ui->txtbox->insertPlainText( "<p>" );
            ui->addParBtn->setEnabled( false );
            ui->endParBtn->setEnabled( true );
        }
    }

    else
    {
        QLabel *lbl = new QLabel( "Press Start !" );
        lbl->show();
    }
}

void MainWindow::on_endParBtn_clicked()
{
    html.endOfParagraph();
    ui->txtbox->insertPlainText( "</p>\n" );
    ui->endParBtn->setEnabled( false );
    ui->addParBtn->setEnabled( true );
}

void MainWindow::on_addFntBtn_clicked()
{
    if( html.getStart() )
    {

//        html.makeFont( "a", 3 )
    }

    else
    {
        QLabel *lbl = new QLabel( "Press Start !" );
        lbl->show();
    }
}

void MainWindow::on_addTitBtn_clicked()
{
    if( html.getStart() )
    {
        html.makeTitle();
        ui->txtbox->insertPlainText( "<head>\n<title>" );
        ui->addTitBtn->setEnabled( false );
        ui->endTitBtn->setEnabled( true );
    }

    else
    {
        QLabel *lbl = new QLabel( "Press Start" );
        lbl->show();
    }
}

void MainWindow::on_endTitBtn_clicked()
{
    html.endOfTitle();
    ui->txtbox->insertPlainText( "</title>\n<head>\n" );
    ui->addTitBtn->setEnabled( true );
    ui->endTitBtn->setEnabled( false );
}

void MainWindow::on_addBrBtn_clicked()
{
    html.makeBreak();
    ui->txtbox->insertPlainText( "<br>\n" );
}

void MainWindow::on_addHrBtn_clicked()
{
    html.makeThematicBreak();
    ui->txtbox->insertPlainText( "<hr>\n" );
}
