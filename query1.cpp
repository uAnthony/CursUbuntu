#include "query1.h"

Query1::Query1()
{
    total = 0;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("123");
    db.setPort(5432);
    ok = db.open();

}



void Query1::my_sets(QWidget *window, QTableView* table)
{
   my_sets_model = new QSqlTableModel(window,db);
   my_table_view = table;
   my_table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
   my_sets_model->setTable("\"Set\"");
   my_table_view->setModel(my_sets_model);
   my_sets_model->select();
   my_table_view->show();

}


void Query1::my_sets_pressed(QWidget* window, QTableView* Widget0,QTableView* Widget1, QTableView* Widget2,QTableView* Widget3,QTableView* Widget4,QTableView* Widget5)
{
    set_one_part(window,my_set_part0,Widget0,"\"CPU\"",4);
    set_one_part(window,my_set_part1,Widget1,"\"Graphic_card\"",2);
    set_one_part(window,my_set_part2,Widget2,"\"Motherboard\"",5);
    set_one_part(window,my_set_part3,Widget3,"\"Memory\"",6);
    set_one_part(window,my_set_part4,Widget4,"\"System_disk\"",8);
    set_one_part(window,my_set_part5,Widget5,"\"Power_supply\"",9);
}

 void Query1::set_one_part(QWidget* window, QSqlTableModel* my_set_part,QTableView* table,QString table_name,int index)
 {
    my_set_part = new QSqlTableModel(window , db);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    my_set_part->setTable(table_name);
    my_set_part->insertRow(0);
    table->setModel(my_set_part);
    int y = my_table_view->currentIndex().row();
    QString key_model = my_table_view->model()->data(my_table_view->model()->index(y,index)).toString();
    QSqlQuery query(QString("SELECT * FROM %1 WHERE \"Model\" = \'%2\'").arg(table_name,key_model));
    while (query.next()){
     for(int i = 0; i < my_set_part->columnCount(); i++)
    my_set_part->setData(my_set_part->index(0,i),query.value(i));
    }
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    table->horizontalHeader()->setStretchLastSection(true);
    table->show();
 }


void Query1::draw(int button_index,QWidget *window, QTableView* table)
{
    tm = new QSqlTableModel(window , db);
    table_all = table;
    table_all->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
        table_all->resizeColumnsToContents();
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
        table_all->resizeColumnsToContents();
        break;
    }
    case 2 : {
        tm->setTable("\"Motherboard\"");
        tm->setHeaderData(5, Qt::Horizontal, QObject::tr("Mem_type"));
        tm->setHeaderData(6, Qt::Horizontal, QObject::tr("Mem_slots"));
        tm->setHeaderData(7, Qt::Horizontal, QObject::tr("Mem_amount"));
        tm->setHeaderData(8, Qt::Horizontal, QObject::tr("Channels"));
        table_all->setModel(tm);
        table_all->resizeColumnsToContents();
        break;
    }
    case 3 : {
        tm->setTable("\"Power_supply\"");
        table_all->setModel(tm);
        table_all->resizeColumnsToContents();
        break;
    }
    case 4 : {
        tm->setTable("\"Memory\"");
        table_all->setModel(tm);
        table_all->resizeColumnsToContents();
        break;
    }
   case 5 : {
        tm->setTable("\"System_disk\"");
        table_all->setModel(tm);
        table_all->resizeColumnsToContents();
    }
    }
    Q_ASSERT(tm->select());
    table_all->show();
}

void Query1::generate_lowprise_set(QWidget *window, QTableView* table,const QString& name)
{
    QString boo;
    bool check = true;
    QSqlQuery query11(QString("SELECT \"Name\"FROM \"Set\" WHERE \"Name\" = \'%1\'").arg(name));
    while (query11.next()){
    boo = query11.value(0).toString();
    check = false;
    }
if (check == true)
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
    table->resizeColumnsToContents();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);


    tm->setData(tm->index(0,0),name);
    //дата
    QDate date;
    date = date.currentDate();
    QString date_string = date.toString("yyyy-mm-dd");
    tm->setData(tm->index(0,1),date);


    QSqlQuery query1("SELECT \"Model\",\"Price\",\"Socket\",\"TDP\" FROM \"CPU\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"CPU\")");
    while (query1.next()){
        tm->setData(tm->index(0,4),query1.value(0).toString());
        tm->setData(tm->index(0,10),query1.value(1).toInt());
        socket = query1.value(2).toString();
        total_power = query1.value(3).toInt();
        tm->setData(tm->index(0,11),total_power);
        total = query1.value(1).toInt();
    }

    QSqlQuery query2(QString("SELECT \"Model\",\"Price\",\"Memory_type\" FROM \"Motherboard\" WHERE \"Price\" = (SELECT Min(\"Price\")FROM (SELECT \"Model\", \"Price\", \"Socket\" FROM \"Motherboard\" WHERE \"Socket\" = \'%1\') as socket);").arg(socket));
    while (query2.next()){
        tm->setData(tm->index(0,5),query2.value(0).toString());
        tm->setData(tm->index(0,10),total + query2.value(1).toInt());
        memory_type = query2.value(2).toString();
        total = total + query2.value(1).toInt();
    }

    QSqlQuery query3("SELECT \"Model\",\"Price\",\"Power_consumption_loaded\" FROM \"Graphic_card\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"Graphic_card\")");
    while (query3.next()){
        tm->setData(tm->index(0,2),query3.value(0).toString());
        tm->setData(tm->index(0,10),total + query3.value(1).toInt());
        total_power = total_power + query3.value(2).toInt();
        tm->setData(tm->index(0,11), total_power);
        total = total + query3.value(1).toInt();
    }

    tm->setData(tm->index(0,3),1);

    QSqlQuery query4(QString("SELECT \"Model\",\"Price\",\"Type\" FROM \"Memory\"WHERE(\"Price\"=(SELECT min(\"Price\") FROM (SELECT \"Price\", \"Type\"  FROM \"Memory\"  WHERE \"Type\" = \'%1\' )AS Type))").arg(memory_type));
    while (query4.next()) {
        tm->setData(tm->index(0,6),query4.value(0).toString());
        tm->setData(tm->index(0,10),total + query4.value(1).toInt());
        total = total + query4.value(1).toInt();
    }
    tm->setData(tm->index(0,7),1);

    QSqlQuery query5("SELECT \"Model\",\"Price\" FROM \"System_disk\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"System_disk\")");
    while (query5.next()) {
        tm->setData(tm->index(0,8),query5.value(0).toString());
        tm->setData(tm->index(0,10),total + query5.value(1).toInt());
        total = total + query5.value(1).toInt();
    }

    total_power = total_power*1.33;
    QString total_power1 = QString::number(total_power);

    QSqlQuery query6(QString("SELECT \"Model\",\"Price\" FROM \"Power_supply\" WHERE \"Price\" = (SELECT min(\"Price\") FROM (SELECT \"Model\",\"Price\" FROM \"Power_supply\" WHERE \"Power_limit\" > \'%1\') AS limit1);").arg(total_power1));
    while (query6.next()) {
        tm->setData(tm->index(0,9),query6.value(0).toString());
        tm->setData(tm->index(0,10),total + query6.value(1).toInt());
        total = total + query6.value(1).toInt();
    }
    table->show();
}
else emit error();
}


int Query1::get_total_cost()
{
    return total;
}

void Query1::save_new_set()
{
    tm->submit();
}




