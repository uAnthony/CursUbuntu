#include "query1.h"

Query1::Query1()
{
    current_set.total_price = 0;
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
   my_table_view->resizeColumnsToContents();
   my_table_view->resizeRowsToContents();
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
    tm->select();
    table_all->show();
}


void Query1::generate_lowprise_set(QWidget *window, QTableView* table,const QString& name)
{   
    reset();
    table_model = new QSqlTableModel(window , db);
    table_configuration = table;
    QString boo;
    bool check = true;
    QSqlQuery query11(QString("SELECT \"Name\"FROM \"Set\" WHERE \"Name\" = \'%1\'").arg(name));
    while (query11.next()){
    boo = query11.value(0).toString();
    check = false;
    }
if (check == true)
    {
    table_model = new QSqlTableModel(window, db);
    table_model->setTable("\"Set\"");
    table_model->setHeaderData(2,Qt::Horizontal,QObject::tr("Graphic_card"));
    table_model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cards"));
    table_model->setHeaderData(5,Qt::Horizontal,QObject::tr("Motherboard"));
    table_model->setHeaderData(6,Qt::Horizontal,QObject::tr("Memory"));
    table_model->setHeaderData(7,Qt::Horizontal,QObject::tr("Mem_num"));
    table_model->setHeaderData(9,Qt::Horizontal,QObject::tr("Power_supply"));
    table_model->insertRow(0);
    table->setModel(table_model);
    table->resizeColumnsToContents();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);


    table_model->setData(table_model->index(0,0),name);
    //дата
    QDate date;
    date = date.currentDate();
    QString date_string = date.toString("yyyy-mm-dd");
    table_model->setData(table_model->index(0,1),date);


    QSqlQuery query1("SELECT \"Model\",\"Price\",\"Socket\",\"TDP\" FROM \"CPU\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"CPU\")");
    while (query1.next()){
        table_model->setData(table_model->index(0,4),query1.value(0).toString());
        table_model->setData(table_model->index(0,10),query1.value(1).toInt());
        cpu.price = query1.value(1).toInt();
        cpu.socket = query1.value(2).toString();
        cpu.power = query1.value(3).toInt();
        current_set.total_power = cpu.power ;
        table_model->setData(table_model->index(0,11),current_set.total_power);
        current_set.total_price = query1.value(1).toInt();
    }

    QSqlQuery query2(QString("SELECT \"Model\",\"Price\" FROM \"Motherboard\" WHERE \"Price\" = (SELECT Min(\"Price\")FROM (SELECT \"Model\", \"Price\", \"Socket\" FROM \"Motherboard\" WHERE \"Socket\" = \'%1\') as socket);").arg(cpu.socket));
    while (query2.next()){
        table_model->setData(table_model->index(0,5),query2.value(0).toString());
        table_model->setData(table_model->index(0,10),current_set.total_price + query2.value(1).toInt());
        motherboard.price =  query2.value(1).toInt();
        current_set.total_price = current_set.total_price + query2.value(1).toInt();
    }

    QSqlQuery query3("SELECT \"Model\",\"Price\",\"Power_consumption_loaded\", \"Hash_rate_bitcoin\", \"Hash_rate_ethereum\" FROM \"Graphic_card\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"Graphic_card\")");
    while (query3.next()){
        table_model->setData(table_model->index(0,2),query3.value(0).toString());
        table_model->setData(table_model->index(0,10),current_set.total_price + query3.value(1).toInt());
        card.price = query3.value(1).toInt();
        current_set.total_price =  current_set.total_price + query3.value(1).toInt();
        card.power = query3.value(2).toInt();
        current_set.total_power = current_set.total_power + query3.value(2).toInt();
        card.hash_bitcoin = query3.value(3).toInt();
        card.hash_ethereum = query3.value(4).toInt();


    }

    table_model->setData(table_model->index(0,3),1);

    QSqlQuery query4(QString("SELECT \"Model\",\"Price\",\"Type\" FROM \"Memory\"WHERE(\"Price\"=(SELECT min(\"Price\") FROM (SELECT \"Price\", \"Type\"  FROM \"Memory\"  WHERE \"Type\" = \'%1\' )AS Type))").arg(memory.type));
    while (query4.next()) {
        table_model->setData(table_model->index(0,6),query4.value(0).toString());
        table_model->setData(table_model->index(0,10),current_set.total_price+ query4.value(1).toInt());
        current_set.total_price = current_set.total_price + query4.value(1).toInt();
        memory.price = query4.value(1).toInt();
    }
    table_model->setData(table_model->index(0,7),1);

    QSqlQuery query5("SELECT \"Model\",\"Price\" FROM \"System_disk\" WHERE \"Price\" = (SELECT min(\"Price\") FROM \"System_disk\")");
    while (query5.next()) {
        table_model->setData(table_model->index(0,8),query5.value(0).toString());
        table_model->setData(table_model->index(0,10),current_set.total_price + query5.value(1).toInt());
        current_set.total_price = current_set.total_price + query5.value(1).toInt();
        disk.price = query5.value(1).toInt();
    }

    int set_power_limit = current_set.total_power*1.33;
    QString total_power1 = QString::number(set_power_limit);
    table_model->setData(table_model->index(0,11),set_power_limit);


    QSqlQuery query6(QString("SELECT \"Model\",\"Price\", \"Power_limit\" FROM \"Power_supply\" WHERE \"Price\" = (SELECT min(\"Price\") FROM (SELECT \"Model\",\"Price\" FROM \"Power_supply\" WHERE \"Power_limit\" > \'%1\') AS limit1);").arg(total_power1));
    while (query6.next()) {
        table_model->setData(table_model->index(0,9),query6.value(0).toString());
        table_model->setData(table_model->index(0,10),current_set.total_price + query6.value(1).toInt());
        current_set.total_price = current_set.total_price + query6.value(1).toInt();
        power_supply.price = query6.value(1).toInt();
        power_supply.power_limit = query6.value(2).toInt();
    }
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    table->show();
}
else emit error();
}


void Query1::make_gaming_set(QTableView* table, int money)
{
   budget = true;
    QString model;
    int price;
    QString type;

    //диск
    QSqlQuery query_disk("SELECT \"Model\", \"Price\", \"Type\" FROM \"System_disk\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM (SELECT \"Price\" FROM \"System_disk\"  WHERE \"Type\" = 'SSD' AND \"Speed_reading\" > 300 AND \"Speed_recording\" > 300)AS A)");
    while(query_disk.next()) {
        model = query_disk.value(0).toString();
        price = query_disk.value(1).toInt();
        type =  query_disk.value(2).toString();
    }

    if(money >= current_set.total_price - disk.price + price)
    {
        current_set.total_price = current_set.total_price - disk.price + price;
        disk.price = price;
        table->model()->setData(table->model()->index(0,8),model);
    }
    else budget = false;
    if(budget)
    {
        //минимальная сборка
        budget = make_gaming_level(table,money,4,4096,4096);
        if(budget) {
            //оптимальная сборка
            budget = make_gaming_level(table,money,8,6144,8192);
            if(budget) {
               upgrade_gaming_card(table,money);
            }
        }
    }
}


bool Query1::make_gaming_level(QTableView* table, int money,int cores,int card_memory,int memory_capacity)
{
    budget = true;
    QString model;
    int price;
    QString type;

    //диск
    QSqlQuery query_disk("SELECT \"Model\", \"Price\" FROM \"System_disk\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM (SELECT \"Price\" FROM \"System_disk\"  WHERE \"Type\" = 'SSD' AND \"Speed_reading\" > 300 AND \"Speed_recording\" > 300)AS A)");
    while(query_disk.next()) {
        model = query_disk.value(0).toString();
        price = query_disk.value(1).toInt();
    }

    if(money >= current_set.total_price - disk.price + price)
    {
        current_set.total_price = current_set.total_price - disk.price + price;
        disk.price = price;
        table->model()->setData(table->model()->index(0,8),model);
    }
    else budget = false;

    //процессор
    QString model_cpu;
    QString socket_cpu;
    int price_cpu;
    int power_cpu;

    QString str_cores = QString::number(cores);

    QSqlQuery query_cpu(QString("SELECT \"Price\", \"TDP\",\"Model\", \"Socket\"  FROM \"CPU\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM(SELECT \"Price\", \"TDP\" FROM \"CPU\" WHERE \"Number_of_cores\" >=\'%1\') AS Q)").arg(str_cores));
      while(query_cpu.next()) {
          price_cpu = query_cpu.value(0).toInt();
          power_cpu = query_cpu.value(1).toInt();
          model_cpu = query_cpu.value(2).toString();
          socket_cpu = query_cpu.value(3).toString();
      }


//материнская плата
      QString model_motherboard;
      int price_motherboard;

      QSqlQuery query_motherboard(QString("SELECT \"Model\", \"Price\" FROM \"Motherboard\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM \"Motherboard\" WHERE \"Memory_type\" = 'DDR4' AND \"Socket\" = \'%1\')").arg(socket_cpu));
            while(query_motherboard.next()) {
                model_motherboard = query_motherboard.value(0).toString();
                price_motherboard = query_motherboard.value(1).toInt();
            }
//память
         QString model_memory;
         int price_memory;
         QString capacity = QString::number(memory_capacity);
         QSqlQuery query_memory(QString("SELECT \"Model\", \"Price\" FROM \"Memory\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM \"Memory\" WHERE \"Type\" = 'DDR4' AND \"Capacity\" = \'%1\')").arg(capacity));
            while(query_memory.next()) {
                model_memory = query_memory.value(0).toString();
                price_memory = query_memory.value(1).toInt();
            }
        if ((current_set.total_power - cpu.power + power_cpu)*133/100 > power_supply.power_limit)
            upgrade_power_supply(table,money,(current_set.total_power - cpu.power + power_cpu)*133/100);

     if(money >= current_set.total_price - cpu.price - motherboard.price - memory.price + price_cpu + price_motherboard + price_memory*2 )
            {
                current_set.total_price = current_set.total_price - cpu.price - motherboard.price - memory.price + price_cpu + price_motherboard + price_memory*2;
                current_set.total_power = current_set.total_power - cpu.power + power_cpu;
                table->model()->setData(table->model()->index(0,4),model_cpu);
                cpu.price = price_cpu;
                cpu.power = power_cpu;
                cpu.socket = socket_cpu;
                table->model()->setData(table->model()->index(0,5),model_motherboard);
                motherboard.price = price_motherboard;
                table->model()->setData(table->model()->index(0,6),model_memory);
                memory.price = price_memory;
                table->model()->setData(table->model()->index(0,7),2);
                table->model()->setData(table->model()->index(0,10),current_set.total_price);
                table->model()->setData(table->model()->index(0,11),(current_set.total_power*133/100));
     } else budget = false;

//Видеокарта
         QString model_card;
         int price_card;
         int power_consumption_card;
         int bench_cloud;
         int bench_strike;
         int bench_lux;
         int bench_future;

     QString str_card_memory = QString::number(card_memory);
     QSqlQuery query_card(QString("SELECT \"Model\", \"Price\", \"Power_consumption_loaded\", CASE WHEN \"Score_3dMark_CloudGate\" IS NULL THEN '0' ELSE CAST (\"Score_3dMark_CloudGate\" AS INTEGER) END \"Score_3dMark_CloudGate\", CASE WHEN \"Score_3dMark_Strike\" IS NULL THEN '0' ELSE CAST (\"Score_3dMark_Strike\" AS INTEGER) END \"Score_3dMark_Strike\",  CASE WHEN \"Score_LuxMark\" IS NULL THEN '0' ELSE CAST (\"Score_LuxMark\" AS INTEGER) END \"Score_LuxMark\", CASE WHEN \"Score_futuremark\" IS NULL THEN '0' ELSE CAST (\"Score_futuremark\" AS INTEGER) END \"Score_futuremark\"  FROM \"Graphic_card\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM(SELECT \"Price\" FROM \"Graphic_card\"  WHERE \"Memory_capacity\" >= \'%1\')AS Q1)").arg(str_card_memory));
        while(query_card.next()) {
            model_card = query_card.value(0).toString();
            price_card = query_card.value(1).toInt();
            power_consumption_card = query_card.value(2).toInt();
            bench_cloud = query_card.value(3).toInt();
            bench_strike = query_card.value(4).toInt();
            bench_lux = query_card.value(5).toInt();
            bench_future = query_card.value(6).toInt();
          }


     if ((current_set.total_power - card.power +  power_consumption_card)*133/100 > power_supply.power_limit)
          upgrade_power_supply(table,money,(current_set.total_power - card.power +  power_consumption_card)*133/100);

     if(money >= current_set.total_price - card.price + price_card)
     {
         current_set.total_price = current_set.total_price - card.price + price_card;
         current_set.total_power = current_set.total_power - card.power + power_consumption_card;
         card.price = price_card;
         card.power = power_consumption_card;
         card.dmark_cloud_gate = bench_cloud;
         card.dmark_strike = bench_strike;
         card.luxmark = bench_lux;
         card.futuremark = bench_future;
         table->model()->setData(table->model()->index(0,2),model_card);
         table->model()->setData(table->model()->index(0,10), current_set.total_price);
         table->model()->setData(table->model()->index(0,11), current_set.total_power*133/100);
     } else budget = false;
return budget;
}


void Query1::upgrade_gaming_card(QTableView* table, int money)
{
     int n;
     QSqlQuery query_number("SELECT  COUNT(*) FROM (SELECT \"Model\", \"Price\" , \"Score_3dMark_CloudGate\", \"Score_3dMark_Strike\",  \"Score_LuxMark\", \"Score_futuremark\"FROM \"Graphic_card\" WHERE \"Memory_capacity\" >= '4096' ORDER BY \"Price\") AS number2 ");
          while(query_number.next()) {
             n = query_number.value(0).toInt();
          }

    for (int i = 1; i <= n; i++)
    {
        QString model_card;
        int price_card = 0;
        int power_consumption_card = 0;
        int bench_cloud = 0;
        int bench_strike = 0;
        int bench_lux = 0;
        int bench_future = 0;
        int number = 0;

        QString str_count = QString::number(i);

        QSqlQuery query_card1(QString("SELECT \"number1\", \"Model\", \"Price\",\"Power_consumption_loaded\" , CASE WHEN \"Score_3dMark_CloudGate\" IS NULL THEN '0' ELSE CAST (\"Score_3dMark_CloudGate\" AS INTEGER) END \"Score_3dMark_CloudGate\", CASE WHEN \"Score_3dMark_Strike\" IS NULL THEN '0' ELSE CAST (\"Score_3dMark_Strike\" AS INTEGER) END \"Score_3dMark_Strike\",  CASE WHEN \"Score_LuxMark\" IS NULL THEN '0' ELSE CAST (\"Score_LuxMark\" AS INTEGER) END \"Score_LuxMark\", CASE WHEN \"Score_futuremark\" IS NULL THEN '0' ELSE CAST (\"Score_futuremark\" AS INTEGER) END \"Score_futuremark\" FROM (SELECT row_number()  OVER (ORDER BY \"Price\") AS Number1, \"Model\", \"Price\" , \"Power_consumption_loaded\",\"Score_3dMark_CloudGate\", \"Score_3dMark_Strike\",  \"Score_LuxMark\", \"Score_futuremark\" FROM \"Graphic_card\" WHERE \"Memory_capacity\" >= '4096' ORDER BY \"Price\") AS number2 WHERE number1 = \'%1\'").arg(str_count));
        while(query_card1.next()) {
            number = query_card1.value(0).toInt();
            model_card = query_card1.value(1).toString();
            price_card = query_card1.value(2).toInt();
            power_consumption_card = query_card1.value(3).toInt();
            bench_cloud = query_card1.value(4).toInt();
            bench_strike = query_card1.value(5).toInt();
            bench_lux = query_card1.value(6).toInt();
            bench_future = query_card1.value(7).toInt();
        }

        if ((current_set.total_power - card.power +  power_consumption_card)*133/100 > power_supply.power_limit)
            upgrade_power_supply(table,money,(current_set.total_power - card.power +  power_consumption_card)*133/100);

        if(money >= current_set.total_price - card.price + price_card)
        {
            int counter = 0;
            if (bench_cloud > card.dmark_cloud_gate)
                ++counter;
            if ( bench_strike > card.dmark_strike)
                ++counter;
            if (bench_lux > card.luxmark)
                ++counter;
            if ( bench_future > card.futuremark)
                ++counter;
            if (counter >= 2){
                current_set.total_price = current_set.total_price - card.price + price_card;
                current_set.total_power = current_set.total_power - card.power + power_consumption_card;
                card.price = price_card;
                card.power = power_consumption_card;
                card.dmark_cloud_gate = bench_cloud;
                card.dmark_strike = bench_strike;
                card.luxmark = bench_lux;
                card.futuremark = bench_future;
                table->model()->setData(table->model()->index(0,2),model_card);
                table->model()->setData(table->model()->index(0,10), current_set.total_price);
                table->model()->setData(table->model()->index(0,11), current_set.total_power*133/100);
            }
        } else budget = false;
}
}


void Query1::upgrade_power_supply(QTableView* table, int money,int power)
{
    QString model;
    int price;
    int power_limit;
    QString my_power = QString::number(power);

    //SELECT "number1", "Model", "Price", CASE WHEN "Score_3dMark_CloudGate" IS NULL THEN '0' ELSE CAST ("Score_3dMark_CloudGate" AS INTEGER) END "Score_3dMark_CloudGate", CASE WHEN "Score_3dMark_Strike" IS NULL THEN '0' ELSE CAST ("Score_3dMark_Strike" AS INTEGER) END "Score_3dMark_Strike", CASE WHEN "Score_LuxMark" IS NULL THEN '0' ELSE CAST ("Score_LuxMark" AS INTEGER) END "Score_LuxMark", CASE WHEN "Score_futuremark" IS NULL THEN '0' ELSE CAST ("Score_futuremark" AS INTEGER) END "Score_futuremark" FROM (SELECT row_number()  OVER (ORDER BY "Price") AS Number1, "Model", "Price" , "Score_3dMark_CloudGate", "Score_3dMark_Strike",  "Score_LuxMark", "Score_futuremark" FROM "Graphic_card" WHERE "Memory_capacity" >= '4096' ORDER BY "Price") AS number2 WHERE number1 = '6'

    QSqlQuery query_power_supply(QString("SELECT \"Model\", \"Price\",\"Power_limit\"  FROM \"Power_supply\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM \"Power_supply\" WHERE \"Power_limit\" >= \'%1\')").arg(my_power));
    while(query_power_supply.next()) {
        model =  query_power_supply.value(0).toString();
        price =  query_power_supply.value(1).toInt();
        power_limit = query_power_supply.value(2).toInt();

    }
    if(money >= current_set.total_price - power_supply.price + price)
    {
        current_set.total_price = current_set.total_price - power_supply.price + price;
        power_supply.price = price;
        power_supply.power_limit = power_limit;
        table->model()->setData(table->model()->index(0,9),model);
    } else budget = false;
}


void Query1::make_mining_set(QTableView* table,int money)
{
    budget = true;

    QString model;
    int price;
    QString type;
    qDebug() << current_set.total_price;
    //диск
    QSqlQuery query_disk("SELECT \"Model\", \"Price\" FROM \"System_disk\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM \"System_disk\")");
    while(query_disk.next()) {
        model = query_disk.value(0).toString();
        price = query_disk.value(1).toInt();
    }
    if(money >= current_set.total_price - disk.price + price)
    {
        current_set.total_price = current_set.total_price - disk.price + price;
        disk.price = price;

        table->model()->setData(table->model()->index(0,8),model);
    }
    else budget = false;


    //материнская плата
    QString model_motherboard;
    int price_motherboard;
    int pci_motherboard;
    QString socket_motherboard;
    QString memory_type;
    int pci = 3;
    QString str_pci = QString::number(pci);

    QSqlQuery query_motherboard(QString("SELECT \"Model\", \"Price\", \"Pci\", \"Socket\", \"Memory_type\"  FROM \"Motherboard\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM \"Motherboard\" WHERE \"Pci\" >= '%1')").arg(str_pci));
    while(query_motherboard.next()) {
        model_motherboard = query_motherboard.value(0).toString();
        price_motherboard = query_motherboard.value(1).toInt();
        pci_motherboard = query_motherboard.value(2).toInt();
        socket_motherboard = query_motherboard.value(3).toString();
        memory_type = query_motherboard.value(4).toString();
    }

    //процессор
    QString model_cpu;
    int price_cpu;
    int power_cpu;

    QSqlQuery query_cpu(QString("SELECT \"Price\", \"TDP\",\"Model\"  FROM \"CPU\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM(SELECT \"Price\" FROM \"CPU\" WHERE \"Socket\" =\'%1\') AS Q)").arg(socket_motherboard));
    while(query_cpu.next()) {
        price_cpu = query_cpu.value(0).toInt();
        power_cpu = query_cpu.value(1).toInt();
        model_cpu = query_cpu.value(2).toString();
    }

    //память

    table->model()->setData(table->model()->index(0,7),1);
    QString model_memory;
    int price_memory;
    int memory_capacity = 4096;
    QString capacity = QString::number(memory_capacity);
    QSqlQuery query_memory(QString("SELECT \"Model\", \"Price\" FROM \"Memory\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM \"Memory\" WHERE \"Type\" = \'%1\' AND \"Capacity\" = \'%2\')").arg(memory_type,capacity));
    while(query_memory.next()) {
        model_memory = query_memory.value(0).toString();
        price_memory = query_memory.value(1).toInt();
    }
    if ((current_set.total_power - cpu.power + power_cpu)*133/100 > power_supply.power_limit)
        upgrade_power_supply(table,money,(current_set.total_power - cpu.power + power_cpu)*133/100);

    if(money >= current_set.total_price - cpu.price - motherboard.price - memory.price + price_cpu + price_motherboard + price_memory )
    {

        current_set.total_price = current_set.total_price - cpu.price - motherboard.price - memory.price + price_cpu + price_motherboard + price_memory;
        current_set.total_power = current_set.total_power - cpu.power + power_cpu;
        table->model()->setData(table->model()->index(0,4),model_cpu);
        cpu.price = price_cpu;
        cpu.power = power_cpu;
        cpu.socket = socket_motherboard;
        table->model()->setData(table->model()->index(0,5),model_motherboard);
        motherboard.price = price_motherboard;
        motherboard.pci = pci_motherboard;
        table->model()->setData(table->model()->index(0,6),model_memory);
        memory.price = price_memory;
        table->model()->setData(table->model()->index(0,10),current_set.total_price);
        table->model()->setData(table->model()->index(0,11),(current_set.total_power*133/100));
    } else budget = false;
    if(budget) {
      upgrade_mining_card(table,money);
    }
  reset();
}


void Query1::upgrade_mining_card(QTableView* table, int money)
{
   qDebug() << 0 << card.price;
   qDebug() << 0 << card.power;
   qDebug() << 0 <<  current_set.total_power;
    int n;
    QSqlQuery query_number("SELECT  COUNT(*) FROM (SELECT * FROM \"Graphic_card\") AS q1");
    while(query_number.next()) {
        n = query_number.value(0).toInt();
    }
    for (int i = 2; i <= n; i++)
    {
        QString model_card;
        int price_card = 0;
        int power_consumption_card = 0;
        int hash_bit = 0;
        int hash_eth = 0;
        int number = 0;

        QString str_count = QString::number(i);

        QSqlQuery query_card2(QString("SELECT \"number1\", \"Model\", \"Price\", \"Power_consumption_loaded\", CASE WHEN \"Hash_rate_bitcoin\" IS NULL THEN '0' ELSE CAST (\"Hash_rate_bitcoin\" AS INTEGER) END \"Hash_rate_bitcoin\", CASE WHEN \"Hash_rate_ethereum\" IS NULL THEN '0' ELSE CAST (\"Hash_rate_ethereum\" AS INTEGER) END \"Hash_rate_ethereum\" FROM (SELECT row_number()  OVER (ORDER BY \"Price\") AS Number1, \"Model\", \"Price\", \"Power_consumption_loaded\", \"Hash_rate_bitcoin\", \"Hash_rate_ethereum\" FROM \"Graphic_card\" ORDER BY \"Price\") AS number2 WHERE number1 = \'%1\'").arg(str_count));
        while(query_card2.next()) {
            number = query_card2.value(0).toInt();
            model_card = query_card2.value(1).toString();
            price_card = query_card2.value(2).toInt();
            power_consumption_card = query_card2.value(3).toInt();
            hash_bit = query_card2.value(4).toInt();
            hash_eth = query_card2.value(5).toInt();
        }


        if ((current_set.total_power - card.power +  power_consumption_card)*133/100 > power_supply.power_limit)
            upgrade_power_supply(table,money,(current_set.total_power - card.power +  power_consumption_card)*133/100);


        if(money >= current_set.total_price - card.price + price_card)
        {
           if (hash_eth > card.hash_ethereum){
               current_set.total_price = current_set.total_price - card.price + price_card;
               current_set.total_power = current_set.total_power - card.power + power_consumption_card;
               card.price = price_card;
               card.power =  power_consumption_card;
               card.hash_bitcoin = hash_bit;
               card.hash_ethereum = hash_eth;
               table->model()->setData(table->model()->index(0,2),model_card);
               table->model()->setData(table->model()->index(0,10), current_set.total_price);
               table->model()->setData(table->model()->index(0,11), current_set.total_power*133/100);
            }
    }
}
    int total_bitcoin = card.hash_bitcoin;
    int total_ethereum = card.hash_ethereum;

    for(int i = 2; i <= motherboard.pci; i++)
    {
        qDebug() << card.price;
        qDebug() << card.power;
        qDebug() << current_set.total_power;
        if (money > current_set.total_price + card.price)
        {
            if(power_supply.power_limit < current_set.total_power + card.power)
            {
                upgrade_power_supply(table,money,(current_set.total_power + card.power)*133/100);
                if ((money > current_set.total_price + card.price) && (power_supply.power_limit > current_set.total_power + card.power))
                {
                    current_set.amount_of_cards = i;
                    table->model()->setData(table->model()->index(0,3),i);
                    current_set.total_price = current_set.total_price + card.price;
                    table->model()->setData(table->model()->index(0,10), current_set.total_price);
                    current_set.total_power = current_set.total_power + card.power;
                    table->model()->setData(table->model()->index(0,11), current_set.total_power*133/100);
                    total_bitcoin = card.hash_bitcoin*i;
                    total_ethereum = card.hash_ethereum*i;;
                }
            }
        }
    }


/*
    int n;
    QSqlQuery query_number("SELECT  COUNT(*) FROM (SELECT * FROM \"Graphic_card\") AS q1");
    while(query_number.next()) {
        n = query_number.value(0).toInt();
    }
    for (int i = 1; i <= n; i++)
    {
        QString model_card;
        int price_card = 0;
        int power_consumption_card = 0;
        int hash_bit = 0;
        int hash_eth = 0;
        int number = 0;

        QString str_count = QString::number(i);

        QSqlQuery query_card2(QString("SELECT \"number1\", \"Model\", \"Price\", \"Power_consumption_loaded\", CASE WHEN \"Hash_rate_bitcoin\" IS NULL THEN '0' ELSE CAST (\"Hash_rate_bitcoin\" AS INTEGER) END \"Hash_rate_bitcoin\", CASE WHEN \"Hash_rate_ethereum\" IS NULL THEN '0' ELSE CAST (\"Hash_rate_ethereum\" AS INTEGER) END \"Hash_rate_ethereum\" FROM (SELECT row_number()  OVER (ORDER BY \"Price\") AS Number1, \"Model\", \"Price\", \"Power_consumption_loaded\", \"Hash_rate_bitcoin\", \"Hash_rate_ethereum\" FROM \"Graphic_card\" ORDER BY \"Price\") AS number2 WHERE number1 = \'%1\'").arg(str_count));
        while(query_card2.next()) {
            number = query_card2.value(0).toInt();
            model_card = query_card2.value(1).toString();
            price_card = query_card2.value(2).toInt();
            power_consumption_card = query_card2.value(3).toInt();
            hash_bit = query_card2.value(4).toInt();
            hash_eth = query_card2.value(5).toInt();
        }
       for(int j = 1; j <= motherboard.pci; j++)
        {
            if ((hash_bit*j > total_bitcoin) || (hash_eth*j > total_ethereum))
            {
                int power = (current_set.total_power - current_set.amount_of_cards*card.power + j*power_consumption_card)*1.33;
                int total_price = current_set.total_price - current_set.amount_of_cards*card.price + j*price_card;
                if((money > total_price) && (power < 1500))
                {
                    QString ps_model;
                    int ps_price;
                    int ps_power_limit;

                    qDebug()<< power <<  power_supply.power_limit;

                    if(power_supply.power_limit < power)
                    {
                        QString my_power = QString::number(power);
                        query_power_supply = new QSqlQuery(QString("SELECT \"Model\", \"Price\",\"Power_limit\"  FROM \"Power_supply\" WHERE \"Price\" = (SELECT MIN(\"Price\") FROM \"Power_supply\" WHERE \"Power_limit\" >= \'%1\')").arg(my_power));
                            while(query_power_supply->next()) {
                            ps_model =  query_power_supply->value(0).toString();
                            ps_price =  query_power_supply->value(1).toInt();
                            ps_power_limit = query_power_supply->value(2).toInt();
                        }
                        //qDebug() << ps_model << ps_power_limit;

                        if((money > total_price - power_supply.price + ps_price)&& (ps_power_limit > power))
                        {

                            current_set.total_power = power;
                            power_supply.price = ps_price;
                            power_supply.power_limit = ps_power_limit;
                            table->model()->setData(table->model()->index(0,9),ps_model);
                            current_set.amount_of_cards = j;
                            table->model()->setData(table->model()->index(0,3),j);
                            current_set.total_price = total_price - power_supply.price + ps_price;
                            table->model()->setData(table->model()->index(0,10), total_price - power_supply.price + ps_price);
                            total_bitcoin  = hash_bit*j;
                            total_ethereum = hash_eth*j;
                            card.price = price_card;
                            card.power = power_consumption_card;
                            table->model()->setData(table->model()->index(0,2), model_card);
                            table->model()->setData(table->model()->index(0,10), current_set.total_price);
                            table->model()->setData(table->model()->index(0,11), current_set.total_power*133/100);
                        }
                    } else {
                        current_set.total_price = current_set.total_price - power_supply.price + ps_price;
                        current_set.total_power = power;
                        power_supply.price = ps_price;
                        power_supply.power_limit = ps_power_limit;
                        table->model()->setData(table->model()->index(0,9),ps_model);
                        current_set.amount_of_cards = j;
                        table->model()->setData(table->model()->index(0,3),j);
                        current_set.total_price = total_price;
                        table->model()->setData(table->model()->index(0,10), total_price);
                        total_bitcoin  = hash_bit*j;
                        total_ethereum = hash_eth*j;
                        card.price = price_card;
                        card.power = power_consumption_card;
                        table->model()->setData(table->model()->index(0,2), model_card);
                        table->model()->setData(table->model()->index(0,10), current_set.total_price);
                        table->model()->setData(table->model()->index(0,11), current_set.total_power*133/100);
                    }
                }
            }
        }
    }*/
}


void Query1::reset()
{
   current_set.total_power = 0;
   current_set.total_price = 0;
   current_set.amount_of_cards = 0;
   card.dmark_cloud_gate = 0;
   card.dmark_strike = 0;
   card.futuremark = 0;
   card.luxmark = 0;
   card.power = 0;
   card.price = 0;
   card.hash_bitcoin = 0;
   card.hash_ethereum = 0;
   disk.price = 0;
   memory.price = 0;
   motherboard.price = 0;
   power_supply.power_limit = 0;
   power_supply.price = 0;

}

int Query1::get_price(QString type,QString model)
{
  QSqlQuery query_1(QString("SELECT \"Price\" FROM '%1' WHERE \"Model\"= '%2'").arg(type,model));
  return query_1.value(0).toInt();
}

int Query1::get_total_cost()
{
    return current_set.total_price;
}

void Query1::save_new_set()
{
    table_model->submit();
}




