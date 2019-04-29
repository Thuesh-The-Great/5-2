#ifndef FONTWINDOW_H
#define FONTWINDOW_H


#include <QMainWindow>

namespace Ui {
class fontWindow;
}


class fontWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit fontWindow( QWidget *parent = nullptr );
    ~fontWindow();
private:
    Ui::fontWindow *ui;

};

#endif // FONTWINDOW_H
