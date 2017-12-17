#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasks.h"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    toggled_button = 0;

    QValidator *validator = new QIntValidator(10000, 999000, this);
    ui->MaxCost->setValidator(validator);

    connect(ui->pushButton_1, SIGNAL(toggled(bool)),this,SLOT(draw0()));
    connect(ui->pushButton_2, SIGNAL(toggled(bool)),this,SLOT(draw1()));
    connect(ui->pushButton_3, SIGNAL(toggled(bool)),this,SLOT(draw2()));
    connect(ui->pushButton_4, SIGNAL(toggled(bool)),this,SLOT(draw3()));
    connect(ui->show_cpu,SIGNAL(toggled(bool)),this,SLOT(send_index0()));
    connect(ui->show_graphic_cards,SIGNAL(toggled(bool)),this,SLOT(send_index1()));
    connect(ui->show_motherboards,SIGNAL(toggled(bool)),this,SLOT(send_index2()));
    connect(ui->show_power_supplies,SIGNAL(toggled(bool)),this,SLOT(send_index3()));
    connect(ui->show_rams,SIGNAL(toggled(bool)),this,SLOT(send_index4()));
    connect(ui->button_generate,SIGNAL(pressed()),this,SLOT(send_assignment()));
    ui->pushButton_4->toggle();
}


void MainWindow::draw0()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::draw1()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::draw2()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::draw3()
{
   ui->stackedWidget->setCurrentIndex(3);
}

QWidget* MainWindow::getwidget(int index)
{
     return ui->stackedWidget->widget(index);
}

QTableView* MainWindow:: getqtableview()
{
   return ui->StockView;
}



 QTableView* MainWindow::getqtableviewset()
 {
     return ui->tableViewSet;
 }



void MainWindow::send_index0()
{
  toggled_button = 0;
  emit draw(0);
}

void MainWindow::send_index1()
{
  toggled_button = 1;
  emit draw(1);
}

void MainWindow::send_index2()
{
  toggled_button = 2;
  emit draw(2);
}

void MainWindow::send_index3()
{
  toggled_button = 3;
  emit draw(3);
}

void MainWindow::send_index4()
{
  toggled_button = 4;
  emit draw(4);
}

void MainWindow::send_assignment()
{
    //if(ui->MaxCost->text().toDouble());
    emit assigment(ui->comboBox->currentIndex(),ui->MaxCost->text().toDouble());
}


MainWindow::~MainWindow()
{
    delete ui;
}
