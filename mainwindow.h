#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QTableView>
#include <QIntValidator>
#include <QString>
#include <QPushButton>
#include <QLabel>
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
    QTableView* get_set_widget(int index);
    QTableView* getqtableview();
    QTableView* getqtableviewset();
    QTableView* get_my_sets();
    QPushButton* get_save_button();
    QLabel* get_error_label();
private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    int toggled_button;


signals:
    void draw(int index);
    void assigment(int index, double money, const QString& name);
    void ui_save_set();
    void set_view_pressed(QWidget*, QTableView*,QTableView*,QTableView*,QTableView*,QTableView*,QTableView*);
private slots:
    void draw0();
    void draw1();
    void draw2();
    void draw3();
    void draw4();
    void draw5();
    void send_index0();
    void send_index1();
    void send_index2();
    void send_index3();
    void send_index4();
     void send_index5();
    void send_assignment();
    void save_set();
};

#endif // MAINWINDOW_H
