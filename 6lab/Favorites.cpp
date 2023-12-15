#include "Favorites.h"
#include <iostream>

Favorites::Favorites(const std::string& title, int numTracks, int numAlbums) :
    Playlist::Playlist(title, numTracks, numAlbums) {};

void Favorites::AddTrack(Track& track) {
    tracks.push_back(track);
    std::cout << "������������ ���������� ������ �������� ������ ��� ������" << std::endl;
}

void Favorites::CallBaseAddTrack(Track& track) {
    Playlist::AddTrack(track);
    std::cout << "������������ ���������� ������ �������� ������ � ������� ��� �� ������������ ������" << std::endl;
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
            std::cout << "������� ����� �����, ������� ������ �������:" << std::endl;
            std::cin >> number;
            std::cin.ignore();
            if (number < 1 || number> tracks.size()) {
                throw std::out_of_range("������������ ����� �����");
            }
            tracks.erase(tracks.begin() + number - 1);
            --numTracks;
            break;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "������ �������� �����: " << e.what() << std::endl;
        }
    }
}