#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "htmlhandler.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( HTML &html, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addHeadBtn_clicked();

    void on_startBtn_clicked();

    void on_endBtn_clicked();

    void on_contBtn_clicked();

    void on_endHeadBtn_clicked();

    void on_insBox_textChanged();

    void on_enterBtn_clicked();

    void on_addParBtn_clicked();

    void on_endParBtn_clicked();

    void on_addFntBtn_clicked();

    void on_addTitBtn_clicked();

    void on_endTitBtn_clicked();

    void on_addBrBtn_clicked();

    void on_addHrBtn_clicked();

private:
    Ui::MainWindow *ui;
    HTML html;
//    Ui::MainWindow *newForm;
};

#endif // MAINWINDOW_H
