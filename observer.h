#ifndef OBSERVER_H
#define OBSERVER_H


#include <QFile>
#include <QString>


#include <iostream>
#include <vector>
#include <algorithm>


class I_Observer//абстрактный класс для наблюдателя
{
public:
    virtual void Update(int size, bool exist) = 0;
};


class File_Observer : I_Observer
{
    QString name;//имя файла
    int size;//размер 
    bool exist = true;//существование фалйа
public:
    File_Observer(QString observer_name, int size);//конструктор наблюдателя
    void Update(int size, bool exist);//обновляет информацию о файле
};


class ASubject
{
    std::vector<File_Observer*> list;
public:
    void Attach(File_Observer* file_observer);//добавление наблюдателя
    void Detach(File_Observer* file_observer);//отключение наблюдателя
    void Notify(int size, bool exist);//обновление информации в наблюдателях  
};


class Concrete_File : public ASubject
{
    QFile file;
public:
    Concrete_File(QString file_name);//конструктор
    void ChangeFile();//проверяем изменился ли файл
    int file_size();//метод возвращающая размер файла
};



#endif // OBSERVER_H
