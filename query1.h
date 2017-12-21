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
# include <parameters.h>

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
    void make_gaming_set(QWidget *window, QTableView* table,int money);
    void make_mining_set(QWidget *window, QTableView* table);
    void make_graphic_set(QWidget *window, QTableView* table);

private:
    bool ok;
    bool budget;
    set current_set;
    set_cpu cpu;
    set_card card;
    set_motherboard motherboard;
    set_memory memory;
    set_disk disk;
    set_power_supply power_supply;
    QSqlDatabase db;
    QSqlTableModel *tm;
    QSqlTableModel *table_model;
    QSqlTableModel *my_set_part;
    QSqlTableModel *my_set_part0;
    QSqlTableModel *my_set_part1;
    QSqlTableModel *my_set_part2;
    QSqlTableModel *my_set_part3;
    QSqlTableModel *my_set_part4;
    QSqlTableModel *my_set_part5;
    QSqlTableModel *my_sets_model;
    QTableView *table_all;
    QTableView *table_configuration;
    QTableView *table0;
    QTableView *table1;
    QTableView *table2;
    QTableView *table3;
    QTableView *table4;
    QTableView *table5;
    QTableView *my_table_view;
    int get_price(QString type,QString model);
    void set_one_part(QWidget* window,QSqlTableModel*,QTableView*,QString table_name, int index);
    void upgrade_power_supply(QTableView* table, int money,int power);
    bool make_gaming_level(QWidget *window, QTableView* table, int money,int cores,int card_memory,int memory_capacity);
private slots:
        void my_sets_pressed(QWidget*, QTableView* Widget0,QTableView* Widget1, QTableView* Widget2,QTableView* Widget3,QTableView* Widget4, QTableView* Widget5);

signals:
   void error();
};

#endif // QUERY1_H
