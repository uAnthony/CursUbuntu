#ifndef TASKS_H
#define TASKS_H
#include "query1.h"
#include "mainwindow.h"


class tasks : public QObject
{
      Q_OBJECT
public:
    MainWindow* form;
    tasks();


private:
     Query1* A;
public slots:
    void draw_table(int);
    void make_lowprise_set(int,double,const QString&);
    void sql_save_set();
    void get_error();
    void draw_my_sets();
};

#endif // TASKS_H
