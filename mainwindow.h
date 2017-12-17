#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QTableView>
#include <QIntValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QWidget* getwidget(int index);
    QTableView* getqtableview();
    QTableView* getqtableviewset();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    int toggled_button;

signals:
    void draw(int index);
    void assigment(int index, double money);

private slots:
    void draw0();
    void draw1();
    void draw2();
    void draw3();
    void send_index0();
    void send_index1();
    void send_index2();
    void send_index3();
    void send_index4();
    void send_assignment();
};

#endif // MAINWINDOW_H
