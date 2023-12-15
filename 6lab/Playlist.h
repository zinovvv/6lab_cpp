#pragma once

#include "Album.h"
#include <string>
#include <vector>

//Класс "Плейлист", содержит вектор треков и вектор альбомов
class Playlist {
protected:
    std::string title;
    int numTracks;
    int numAlbums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    //Конструкторы
    Playlist(const std::string& title, int numTracks, int numAlbums);
    Playlist(const Playlist& other);
    Playlist();

    //Добавление трека в плейлист
    void AddTrack(Track& track);

    void operator+(Track& track);

    //Заполнение вектора tracks
    void SetTracks(const std::vector<Track>& newTracks);

    //Вывод треков
    void PrintTracks() const;

    //Виртуальный метод удаления трека
    virtual void DeleteTrack();

    void CallVirtualDeleteTrack(Playlist& playlist);

    //Добавление альбома
    void AddAlbum(Album& album);

    //Заполнение вектора albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    //Вывод альбомов
    void PrintAlbums() const;

    //Удаление альбома
    void DeleteAlbum();

    std::string GetTitle() {
        return title;
    }

    int GetNumTracks() {
        return numTracks;
    }

    int GetNumAlbums() {
        return numAlbums;
    }

    std::vector<Track>& GetTracks() {
        return tracks;
    }

    std::vector<Album>& GetAlbums() {
        return albums;
    }

    //Деструктор
    ~Playlist() = default;
};