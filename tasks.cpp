#include "tasks.h"


tasks::tasks()
{
    form = new MainWindow();
    form->setGeometry(0,0,1100,700);
    form->setWindowTitle("Configuration builder");
    form->show();
    A = new Query1();
    connect(form,SIGNAL(draw(int)),this,SLOT(draw_table(int)));
    connect(form,SIGNAL(assigment(int,double,const QString&)),this,SLOT(make_gaming_set(int,double, const QString&)));

}

void tasks::draw_table(int index)
{
  //form->getqtableview()
  A->draw(index,form->getwidget(3),form->getqtableview());

}

void tasks::make_gaming_set(int index,double money,const QString& name)
{
  A->generate_lowprise_set(form->getwidget(1),form->getqtableviewset(),name);

}
