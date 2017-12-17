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

class Query1 : public QObject
{
     Q_OBJECT
public:
    Query1();
    void draw(int, QWidget *a, QTableView* table);
    void generate_lowprise_set(QWidget *window, QTableView* table);
private:
    bool ok;
    QSqlDatabase db;
    QSqlTableModel *tm;
    QTableView *table_all;
};

#endif // QUERY1_H
