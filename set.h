#ifndef SET_H
#define SET_H

#include <QObject>

class Set : public QObject
{
    Q_OBJECT
public:
    explicit Set(QObject *parent = 0);


private:
    struct CPU;
    struct graphic_card;
    struct memory;
    struct motherboard;
    struct power_supply;

signals:

public slots:
};

#endif // SET_H
