#include "Favorites.h"
#include <iostream>

Favorites::Favorites(const std::string& title, int numTracks, int numAlbums) :
    Playlist::Playlist(title, numTracks, numAlbums) {};

void Favorites::AddTrack(Track& track) {
    tracks.push_back(track);
    std::cout << "Демонстрация перегрузки метода базового класса без вызова" << std::endl;
}

void Favorites::CallBaseAddTrack(Track& track) {
    Playlist::AddTrack(track);
    std::cout << "Демонстрация перегрузки метода базового класса с вызовом его из производного класса" << std::endl;
}

void Favorites::operator=(Playlist& obj) {
    this->numTracks = obj.GetNumTracks();
    this->numAlbums = obj.GetNumAlbums();
    this->tracks = obj.GetTracks();
    this->albums = obj.GetAlbums();
}

void Favorites::DeleteTrack() {
    int number;
    while (true) {
        try {
            std::cout << "Введите номер трека, который хотите удалить:" << std::endl;
            std::cin >> number;
            std::cin.ignore();
            if (number < 1 || number> tracks.size()) {
                throw std::out_of_range("Некорректный номер трека");
            }
            tracks.erase(tracks.begin() + number - 1);
            --numTracks;
            break;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Ошибка удаления трека: " << e.what() << std::endl;
        }
    }
}