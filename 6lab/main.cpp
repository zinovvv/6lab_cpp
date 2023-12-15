#include "MusicLibrary.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");

    //�������� ����������
    MusicLibrary myMusicLibrary(1, 1);

    //�������� ���������
    Playlist myPlaylist("������� �����", 3, 2);

    Favorites favorites("���������", 3, 1);

    //������ � ������� ��� ���������
    std::vector<Track> tracks = {
    {"�������", "������ ���", 400, 1986, "���"},
    {"������", "��-2", 345, 1998, "���"},
    {"���� � ������", "���� ����", 328, 2012, "���"}
    };
    
    favorites.AddTrack(tracks[0]);
    
    favorites.CallBaseAddTrack(tracks[1]);
    favorites.PrintTracks();

    //���������� ������� tracks ������ ������ Playlist
    myPlaylist.SetTracks(tracks);

    //������ � ������������ ������
    //������� ������ ��� ������� ���������� �� ������� ������ Album
    Album** albumsArray = new Album * [2];

    //������ ������ ��� ���������
    Album* album1 = new Album("���������� ����", "���", 2023, 12, {});
    std::vector<Track> tracks1 = {
        {"��������", "���", 180, 2023, "��� ���-���"},
        {"��������� ����", "���", 200, 2023, "��� ���-���"},
        {"���������", "���", 198, 2023, "��� ���-���"},
        {"������� ������", "���", 222, 2023, "��� ���-���"},
        {"���������� ����", "���", 210, 2023, "��� ���-���"},
        {"������ �����", "���", 195, 2023, "��� ���-���"},
        {"�������", "���", 189, 2023, "��� ���-���"},
        {"�� ������", "���", 240, 2023, "��� ���-���"},
        {"����", "���", 200, 2023, "��� ���-���"},
        {"������ ����", "���", 192, 2023, "��� ���-���"},
        {"������ �����", "���", 203, 2023, "��� ���-���"},
        {"���� ����", "���", 240, 2023, "��� ���-���"}
    };

    std::cout << tracks1[9];

    album1->SetTracks(tracks1);

    //������ ������ ��� ���������
    Album* album2 = new Album("��� ����", "������", 2023, 13, {});
    std::vector<Track> tracks2 = {
         {"� �������", "������", 171, 2023, "������������"},
        {"����� ���", "������", 224, 2023, "������������"},
        {"������", "������", 161, 2023, "������������"},
        {"���������", "������", 330, 2023, "������������"},
        {"�� �������", "������", 239, 2023, "������������"},
        {"���������", "������", 167, 2023, "������������"},
        {"���� ����", "������", 225, 2023, "������������"},
        {"��� ��� ��", "������", 258, 2023, "������������"},
        {"Spirit of the World", "������", 217, 2023, "������������"},
        {"������", "������", 266, 2023, "������������"},
        {"��������", "������", 100, 2023, "������������"},
        {"�������� � ����������", "������", 155, 2023, "������������"},
        {"������ �����", "������", 238, 2023, "������������"}
    };
    album2->SetTracks(tracks2);

    //��������� ������ ���������� �� �������
    albumsArray[0] = album1;
    albumsArray[1] = album2;

    //������� ������ albums, ������� ����� ��������� ����� �������� Album
    std::vector<Album> albums;
    for (int i = 0; i < 2; i++) {
        // ��������� ����� �������� � ������
        albums.push_back(*albumsArray[i]);
    }

    //��������� �������� ���������
    myPlaylist.SetAlbums(albums);

    //������ ������ ��� ������� � ������ ������ ��� ����
    Album albumLsp1("Magic City", "���", 2015, 9, {});
    std::vector<Track> tracksLsp1 =
    { {"Bullet", "���", 130, 2015, "���"},
    {"���-�� ���", "���", 423, 2015, "���"},
    {"����", "���", 412, 2015, "���"},
    {"�������", "���", 258, 2015, "���"},
    {"�����", "���", 258, 2015, "���"},
    {"�����", "���", 258, 2015, "���"},
    {"�����", "���", 258, 2015, "���"},
    {"��", "���", 258, 2015, "���"},
    {"������", "���", 258, 2015, "���"} };
    //���������� ������� �������
    albumLsp1.SetTracks(tracksLsp1);

    //������ ������ � ������ ������ ��� ����
    Album albumLsp2("Tragic City", "���", 2017, 10, {});
    std::vector<Track> tracksLsp2  =
    { {"�����������", "���", 130, 2015, "���"},
    {"�������", "���", 423, 2015, "���"},
    {"����", "���", 412, 2015, "���"},
    {"�������� ���������", "���", 258, 2015, "���"},
    {"����� �����", "���", 258, 2015, "���"},
    {"����� �����", "���", 258, 2015, "���"},
    {"��� ���� ����", "���", 258, 2015, "���"},
    {"������", "���", 258, 2015, "���"},
    {"�������", "���", 258, 2015, "���"},
    {"������ �� ��������", "���", 258, 2015, "���"}};
    //���������� ������� �������
    albumLsp2.SetTracks(tracksLsp2);

    //������ ������ ��������, ������� �������� ��������� �������
    std::vector<Album> albumsLsp = { albumLsp1,albumLsp2 };

    //������� ������ ��� Artist
    Artist* myArtist = new Artist("���", 2);

    //��������� � ������ ������� ����� '->' (���������� ������� ���������)
    myArtist->SetAlbums(albumsLsp);

    //�������� ��������� �������� � ����������� ����������
    myMusicLibrary.AddPlaylist(myPlaylist);

    //������ ����� ������ myPlaylist, ���������� �� ������������� ������� GetPlaylist
    myPlaylist = GetPlaylist(myMusicLibrary, 0);

    std::vector<LibraryItem*> library;
    library.push_back(&tracks[0]);
    library.push_back(&tracks[2]);
    library.push_back(album1);

    for (const auto& item : library) {
        item->DisplayInfo();
    }

    std::cout << "����� ������ �� ���������\n" << std::endl;
    //����� ������ �� ���������
    myPlaylist.PrintTracks();
    //�������� ����� �� �����
    myPlaylist.DeleteTrack();
    //����� ������
    myPlaylist.PrintTracks();

    //����������, ��� � �������
    std::cout << "\n����� �������� �� ���������\n" << std::endl;
    myPlaylist.PrintAlbums();
    std::cout << "\n�������� ������� �� ���������\n" << std::endl;
    myPlaylist.DeleteAlbum();
    std::cout << "\n����� �������� �� ���������\n" << std::endl;
    myPlaylist.PrintAlbums();

    favorites = myPlaylist;

    myPlaylist.CallVirtualDeleteTrack(favorites);

    favorites.PrintTracks();

    Playlist* ptr = nullptr;
    ptr = &favorites;
    ptr->DeleteTrack();
    favorites.PrintTracks();

    //���������� ����������� � ����������� ����������
    myMusicLibrary.AddArtist(*myArtist);

    //������ ����� ������ myArtist, ���������� �� ������ GetArtist
    myArtist = myMusicLibrary.GetArtist(0);
    std::cout << "\n����� �������� �������\n" << std::endl;
    myArtist->PrintAlbums();
    std::cout << "\n�������� ������� �������\n" << std::endl;
    myArtist->DeleteAlbum();
    std::cout << "\n����� �������� �������\n" << std::endl;
    myArtist->PrintAlbums();

    //������������ ������, ���������� ��� �������� ��������
    for (int i = 0; i < 2; i++) {
        delete albumsArray[i];
    }
    //������������ ������, ���������� ��� ������� ���������� �� �������
    delete[] albumsArray;

    return 0;
}