#include "observer.h"

#include <chrono>
#include <thread>


int main()
{
    Concrete_File test_File("test.txt");//создаём и открываем файл
    File_Observer fist_Observer("test.txt", test_File.file_size());//создаём наблюдателя
    test_File.Attach(&fist_Observer);//привязываем наблюдателей к файлу
    for(int i = 0; i < 100; i++)//цикл, во время работы которого наблюдатель отслеживает изменения
    {
        std::this_thread::sleep_for( std::chrono::milliseconds(200));
        test_File.ChangeFile();//проверяем изменился ли файл
    }
    return 0;
}
