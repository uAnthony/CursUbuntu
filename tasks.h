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
    void make_gaming_set(int,double);
};

#endif // TASKS_H
