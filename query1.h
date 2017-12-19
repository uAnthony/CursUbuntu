#ifndef QUERY1_H
#define QUERY1_H

#include <qwidget.h>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "mainwindow.h"
#include <QTableView>
#include <QSqlQueryModel>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlField>
#include <QDate>
#include <QSqlRecord>
#include <QHeaderView>

class Query1 : public QObject
{
     Q_OBJECT
public:
    Query1();
    void draw(int, QWidget *a, QTableView* table);
    //void draw_my_set(QWidget*,QWidget*,QWidget*,QWidget*,QWidget*);
    void my_sets(QWidget *window, QTableView* table);
    void generate_lowprise_set(QWidget *window, QTableView* table, const QString& name);
    void save_new_set();
   int get_total_cost();
private:
    bool ok;
    int total;
    QString memory_type;
    QString socket;
    int total_power;
    QSqlDatabase db;
    QSqlTableModel *tm;
    QSqlTableModel *my_set_part;
    QSqlTableModel *my_set_part0;
    QSqlTableModel *my_set_part1;
    QSqlTableModel *my_set_part2;
    QSqlTableModel *my_set_part3;
    QSqlTableModel *my_set_part4;
    QSqlTableModel *my_set_part5;

    QSqlTableModel *my_sets_model;
    QTableView *table_all;
    QTableView *table0;
    QTableView *table1;
    QTableView *table2;
    QTableView *table3;
    QTableView *table4;
    QTableView *table5;
    QTableView *my_table_view;
    void set_one_part(QWidget* window,QSqlTableModel*,QTableView*,QString table_name, int index);

private slots:
        void my_sets_pressed(QWidget*, QTableView* Widget0,QTableView* Widget1, QTableView* Widget2,QTableView* Widget3,QTableView* Widget4, QTableView* Widget5);

signals:
   void error();
};

#endif // QUERY1_H
