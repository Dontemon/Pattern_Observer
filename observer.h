#ifndef OBSERVER_H
#define OBSERVER_H


#include <QFile>
#include <QString>


#include <iostream>
#include <vector>
#include <algorithm>


class I_Observer
{
public:
    virtual void Update(int size, bool exist) = 0;
};


class File_Observer : I_Observer
{
    QString name;
    int size;
    bool exist = true;
public:
    File_Observer(QString observer_name, int size);
    void Update(int size, bool exist);
};


class ASubject
{
    std::vector<File_Observer*> list;
public:
    void Attach(File_Observer* file_observer);
    void Detach(File_Observer* file_observer);
    void Notify(int size, bool exist);
};


class Concrete_File : public ASubject
{
    QFile file;
public:
    Concrete_File(QString file_name);
    void ChangeFile();
    int file_size();
};



#endif // OBSERVER_H
