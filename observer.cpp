#include "observer.h"
#include <QDebug>

File_Observer::File_Observer(QString observer_name, int size) : name(observer_name), size(size) {}//конструктор

void File_Observer::Update(int size, bool exist)//обновляет информацию о файле
{
    this->exist = exist;//обновляем информацию о существовании файла
    if (this->exist)//если существует
    {
        if (size > 0)//смотрим пустой ли он
        {
            if (size != this->size)//смотрим был ли изменён размер файла
            {
                qDebug() << "File has been modified. Now file size is " << size << std::endl;
            }
            qDebug() << "File exists and size is " << size << std::endl;
        }
        else
            qDebug() << "File exists, but its empty "<<std::endl;
    }
    else
    {
        qDebug() << "File doesn't exist.\n";
    }
    this->size = size;//обновляем размер файла
}


void ASubject::Attach(File_Observer* file_observer)//добавление наблюдателя
{
    list.push_back(file_observer);
}

void ASubject::Detach(File_Observer* file_observer)//удалеление наблюдателя
{
    list.erase(std::remove(list.begin(), list.end(), file_observer), list.end());
}

void ASubject::Notify(int size, bool exist)//обновление информации в наблюдателях   
{
    for (int i = 0; i < list.size(); i++)  //идем по циклу и обновляем данные в наблюдателях
       if (list[i] != 0)
          list[i]->Update(size,exist);
}


Concrete_File::Concrete_File(QString file_name) :file(file_name)//открываем файл
{
}


void Concrete_File::ChangeFile()//проверка, изменился ли файл
{
    Notify(file.size(), file.exists());
}

int Concrete_File::file_size()//выводит размер файла
{
    return file.size();
}
