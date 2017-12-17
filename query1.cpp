#include "query1.h"

Query1::Query1()
{

        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("localhost");
        db.setDatabaseName("postgres");
        db.setUserName("postgres");
        db.setPassword("123");
        db.setPort(5432);
        ok = db.open();

}



void Query1::draw(int button_index,QWidget *window, QTableView* table)
{
    tm = new QSqlTableModel(window , db);
    table_all = table;

    switch(button_index) {

    case 0 : {
        tm->setTable("\"CPU\"");
        tm->setHeaderData(3, Qt::Horizontal, QObject::tr("Cores"));
        tm->setHeaderData(4, Qt::Horizontal, QObject::tr("Threads"));
        tm->setHeaderData(5, Qt::Horizontal, QObject::tr("Freq_base"));
        tm->setHeaderData(6, Qt::Horizontal, QObject::tr("Freq_max"));
        tm->setHeaderData(9, Qt::Horizontal, QObject::tr("3dMark"));
        tm->setHeaderData(10, Qt::Horizontal, QObject::tr("Cinebench"));
        tm->setHeaderData(11, Qt::Horizontal, QObject::tr("PassMark"));
        table_all->setModel(tm);
        table_all->resizeColumnToContents(12);
        break;
    }
    case 1 : {
        tm->setTable("\"Graphic_card\"");
        tm->setHeaderData(3, Qt::Horizontal, QObject::tr("Mem_amount"));
        tm->setHeaderData(5, Qt::Horizontal, QObject::tr("Shader_units"));
        tm->setHeaderData(6, Qt::Horizontal, QObject::tr("Power"));
        tm->setHeaderData(7, Qt::Horizontal, QObject::tr("Max_hit"));
        tm->setHeaderData(8, Qt::Horizontal, QObject::tr("Noise_lvl"));
        tm->setHeaderData(9, Qt::Horizontal, QObject::tr("3dMark_CG"));
        tm->setHeaderData(10, Qt::Horizontal, QObject::tr("3dMark_strike"));
        tm->setHeaderData(11, Qt::Horizontal, QObject::tr("LuxMark"));
        tm->setHeaderData(12, Qt::Horizontal, QObject::tr("FutureMark"));
        table_all->setModel(tm);
        table_all->resizeColumnToContents(13);
        break;
    }
    case 2 : {
        tm->setTable("\"Motherboard\"");
        tm->setHeaderData(5, Qt::Horizontal, QObject::tr("Mem_type"));
        tm->setHeaderData(6, Qt::Horizontal, QObject::tr("Mem_slots"));
        tm->setHeaderData(7, Qt::Horizontal, QObject::tr("Mem_amount"));
        tm->setHeaderData(8, Qt::Horizontal, QObject::tr("Channels"));
        table_all->setModel(tm);
        table_all->resizeColumnToContents(11);
        break;
    }
    case 3 : {
        tm->setTable("\"Power_supply\"");
        table_all->setModel(tm);
        table_all->resizeColumnToContents(6);
       // table_all->resizeColumnsToContents();
        break;
    }
    case 4 : {
        tm->setTable("\"Memory\"");
        table_all->setModel(tm);
        table_all->resizeColumnToContents(7);
        break;
    }
    }

   // tm = new QSqlTableModel(window , db);
   // tm->setTable("\"Memory\"");
   Q_ASSERT(tm->select());
  //  table_all = new QTableView(window);
   // table_all->setGeometry(200,40,800,500);
    table_all->show();
}

void Query1::generate_lowprise_set(QWidget *window, QTableView* table)
{
     tm = new QSqlTableModel(window, db);
     tm->setTable("\"Set\"");
     tm->setHeaderData(2,Qt::Horizontal,QObject::tr("Graphic_card"));
     tm->setHeaderData(3,Qt::Horizontal,QObject::tr("Cards"));
     tm->setHeaderData(5,Qt::Horizontal,QObject::tr("Motherboard"));
     tm->setHeaderData(6,Qt::Horizontal,QObject::tr("Memory"));
     tm->setHeaderData(7,Qt::Horizontal,QObject::tr("Mem_num"));
     tm->setHeaderData(9,Qt::Horizontal,QObject::tr("Power_supply"));
     tm->insertRow(0);

     table->setModel(tm);
     table->resizeColumnToContents(11);
     table->show();

     QSqlQuery query("SELECT \"Model\",\"Price\" FROM \"CPU\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"CPU\")");
     while (query.next()) {
     tm->setData(tm->index(0,6),query.value(0).toString());
    }


   /*ПАМЯТЬ
    QSqlQuery query("SELECT \"Model\",\"Price\" FROM \"Memory\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"Memory\")");
    while (query.next()) {
    tm->setData(tm->index(0,6),query.value(0).toString());
    }

    */


    //QSqlQueryModel model;
   /* model.setQuery("SELECT * FROM \"CPU\"");
    if (model.lastError().isValid())
        qDebug() << model.lastError();
  //  SELECT \"Model\",\"Price\" FROM \"Memory\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"Memory\"
    table->setModel(&model);
    table->hide();
    table->show();*/
}




    /*

   // tm = new QSqlTableModel(window , db);
    QSqlQueryModel model;
    model.setQuery("select * from CPU");
    table_all = table;
    table_all->setEditTriggers(QAbstractItemView::NoEditTriggers);

   // tm->setTable("CPU");
   // bool check = tm->select();
    table_all->setGeometry(50,50,200,200);
    table_all->setModel(&model);
    table_all->show();


    //table_all->show();

    //tm->setTable();*/



