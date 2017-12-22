#include "tasks.h"


tasks::tasks()
{
    form = new MainWindow();
    form->setGeometry(0,0,1100,700);
    form->setWindowTitle("Configuration builder");
    form->show();
    A = new Query1();
    draw_my_sets();
    connect(form,SIGNAL(draw(int)),this,SLOT(draw_table(int)));
    connect(form,SIGNAL(assigment(int,double,const QString&)),this,SLOT(make_lowprise_set(int,double, const QString&)));
    connect(form,SIGNAL(ui_save_set()),this,SLOT(sql_save_set()));
    connect(A,SIGNAL(error()),this,SLOT(get_error()));
    connect(form,SIGNAL(set_view_pressed(QWidget*,QTableView*,QTableView*,QTableView*,QTableView*,QTableView*,QTableView*)),A, SLOT(my_sets_pressed(QWidget*,QTableView*,QTableView*,QTableView*,QTableView*,QTableView*,QTableView*)));
}

void tasks::draw_table(int index)
{
  A->draw(index,form->getwidget(3),form->getqtableview());
}

void tasks::draw_my_sets()
{
    A->my_sets(form->getwidget(3),form->get_my_sets());
}

void tasks::make_lowprise_set(int index,double money,const QString& name)
{
    A->generate_lowprise_set(form->getwidget(1),form->getqtableviewset(),name);
    if(money >= A->get_total_cost())
    {
        switch (index) {
        case 0: {
           A->make_mining_set(form->getqtableviewset(),money);
            break;
        }
        case 1: {
            A->make_gaming_set(form->getqtableviewset(),money);
            break;
        }
        }
        form->get_save_button()->setEnabled(true);
    }
  else {
      form->get_save_button()->setEnabled(false);
      form->get_error_label()->setText("Not enough money for configuration");
  }
}

void tasks::sql_save_set()
{
  A->save_new_set();
  A->my_sets(form->getwidget(3),form->get_my_sets());
}

void tasks::get_error()
{
    form->get_error_label()->setText("Your name is already taken!");
}
