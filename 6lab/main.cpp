#include "MusicLibrary.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");

    //Создание плейлиста(Базовый класс)
    Playlist myPlaylist("Любимые треки", 3, 2);
    //Вектор с треками для плейлиста
    std::vector<Track> tracks = {
    {"Кукушка", "Виктор Цой", 400, 1986, "рок"},
    {"Метель", "Би-2", 345, 1998, "рок"},
    {"Лето в городе", "Иван Дорн", 328, 2012, "поп"}
    };
    myPlaylist.SetTracks(tracks);
    Album** albumsArray = new Album * [1];
    //Первый альбом для плейлиста
    Album* album1 = new Album("Несчастные люди", "ЛСП", 2023, 12, {});
    std::vector<Track> tracks1 = {
        {"Карантин", "ЛСП", 180, 2023, "поп хип-хоп"},
        {"Троянский конь", "ЛСП", 200, 2023, "поп хип-хоп"},
        {"Монополия", "ЛСП", 198, 2023, "поп хип-хоп"},
        {"Золотой ключик", "ЛСП", 222, 2023, "поп хип-хоп"},
        {"Несчастные люди", "ЛСП", 210, 2023, "поп хип-хоп"},
        {"Вечная весна", "ЛСП", 195, 2023, "поп хип-хоп"},
        {"Ураганы", "ЛСП", 189, 2023, "поп хип-хоп"},
        {"Не убежал", "ЛСП", 240, 2023, "поп хип-хоп"},
        {"Боди", "ЛСП", 200, 2023, "поп хип-хоп"},
        {"Сектор Приз", "ЛСП", 192, 2023, "поп хип-хоп"},
        {"Сикрет Плейс", "ЛСП", 203, 2023, "поп хип-хоп"},
        {"Стоп Игра", "ЛСП", 240, 2023, "поп хип-хоп"}
    };
    album1->SetTracks(tracks1);
    //Заполняем массив указателей на альбомы
    albumsArray[0] = album1;
    //Создаем вектор albums, который будет содержать копии объектов Album
    std::vector<Album> albums;
    for (int i = 0; i < 1; i++) {
        // Добавляем копии альбомов в вектор
        albums.push_back(*albumsArray[i]);
    }
    //Заполняем плейлист альбомами
    myPlaylist.SetAlbums(albums);
    //Первый альбом для артиста и вектор треков для него
    Album albumLsp1("Magic City", "ЛСП", 2015, 9, {});
    std::vector<Track> tracksLsp1 =
    { {"Bullet", "ЛСП", 130, 2015, "рэп"},
    {"Что-то ещё", "ЛСП", 423, 2015, "рэп"},
    {"Шест", "ЛСП", 412, 2015, "рэп"},
    {"Безумие", "ЛСП", 258, 2015, "рэп"},
    {"Синее", "ЛСП", 258, 2015, "рэп"},
    {"Фокус", "ЛСП", 258, 2015, "рэп"},
    {"Бигги", "ЛСП", 258, 2015, "рэп"},
    {"ОК", "ЛСП", 258, 2015, "рэп"},
    {"Уровни", "ЛСП", 258, 2015, "рэп"} };
    //Заполнение альбома треками
    albumLsp1.SetTracks(tracksLsp1);
    //Второй альбом и вектор треков для него
    Album albumLsp2("Tragic City", "ЛСП", 2017, 10, {});
    std::vector<Track> tracksLsp2  =
    { {"Воскресение", "ЛСП", 130, 2015, "рэп"},
    {"Монетка", "ЛСП", 423, 2015, "рэп"},
    {"Тело", "ЛСП", 412, 2015, "рэп"},
    {"Лабиринт отражений", "ЛСП", 258, 2015, "рэп"},
    {"Конец света", "ЛСП", 258, 2015, "рэп"},
    {"Белый танец", "ЛСП", 258, 2015, "рэп"},
    {"Ещё один день", "ЛСП", 258, 2015, "рэп"},
    {"Канкан", "ЛСП", 258, 2015, "рэп"},
    {"Ползать", "ЛСП", 258, 2015, "рэп"},
    {"Деньги не проблема", "ЛСП", 258, 2015, "рэп"}};
    //Заполнение альбома треками
    albumLsp2.SetTracks(tracksLsp2);
    //Создаю вектор альбомов, который содержит созданные альбомы
    std::vector<Album> albumsLsp = { albumLsp1,albumLsp2 };
    //Выделяю память для Artist
    Artist* myArtist = new Artist("ЛСП", 2);
    //Обращаюсь к методу объекта через '->' (Заполнение артиста альбомами)
    myArtist->SetAlbums(albumsLsp);



    //ДЕМОНСТРАЦИЯ РАБОТЫ ПРОГРАММЫ


    //Создание плейлиста "Избранное"(Производный класс), в конструкторе вызывается конструктор базового класса
    Favorites favorites("Избранное", 3, 1);

    //Перегрузка метода базового класса 
    favorites.AddTrack(tracks[0]);

    //С вызовом метода базового
    favorites.CallBaseAddTrack(tracks[1]);

    //Вывод
    std::cout <<std::endl<< "Вывод плейлиста 'Избранное'" << std::endl;
    std::cout << favorites;

    //Демонстрация перегрузки оператора присваивания
    favorites = myPlaylist;
    
    //Вывод
    std::cout << std::endl << "Вывод плейлиста 'Избранное' после присваивания" << std::endl;
    std::cout << favorites;

    //Если внутри невиртуального метода CallVirtualDisplay находится виртуальный метод,
    //То вызовется перегруженный метод дочернего класса,
    //Если там невиртуальный метод, то будет вызываться метод базового класса
    Playlist* ptrPlaylist = &favorites;
    ptrPlaylist->CallVirtualDisplay();
    
    //Демонстрация работы абстрактного класса
    DeleteItem* itemPtr;

    itemPtr = &myPlaylist;
    itemPtr->DeleteAlbum();

    itemPtr = &favorites;
    itemPtr->DeleteAlbum();

    itemPtr = myArtist;
    itemPtr->DeleteAlbum();

    //Демонстрация работы шаблонного класса
    std::cout << std::endl << "Демонстрация работы шаблонного класса" << std::endl;
    ObjectList<Track> trackList;
    trackList.addObject(tracks[0]);
    trackList.addObject(tracks[2]);
    trackList.displayObjects();

    ObjectList<Album> albumList;
    albumList.addObject(albumLsp2);
    albumList.displayObjects();


    delete albumsArray[0];
    delete[] albumsArray;
    delete myArtist;

    return 0;
}