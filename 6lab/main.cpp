#include "MusicLibrary.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");

    //�������� ���������(������� �����)
    Playlist myPlaylist("������� �����", 3, 2);
    //������ � ������� ��� ���������
    std::vector<Track> tracks = {
    {"�������", "������ ���", 400, 1986, "���"},
    {"������", "��-2", 345, 1998, "���"},
    {"���� � ������", "���� ����", 328, 2012, "���"}
    };
    myPlaylist.SetTracks(tracks);
    Album** albumsArray = new Album * [1];
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
    album1->SetTracks(tracks1);
    //��������� ������ ���������� �� �������
    albumsArray[0] = album1;
    //������� ������ albums, ������� ����� ��������� ����� �������� Album
    std::vector<Album> albums;
    for (int i = 0; i < 1; i++) {
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



    //������������ ������ ���������


    //�������� ��������� "���������"(����������� �����), � ������������ ���������� ����������� �������� ������
    Favorites favorites("���������", 3, 1);

    //���������� ������ �������� ������ 
    favorites.AddTrack(tracks[0]);

    //� ������� ������ ��������
    favorites.CallBaseAddTrack(tracks[1]);

    //�����
    std::cout <<std::endl<< "����� ��������� '���������'" << std::endl;
    std::cout << favorites;

    //������������ ���������� ��������� ������������
    favorites = myPlaylist;
    
    //�����
    std::cout << std::endl << "����� ��������� '���������' ����� ������������" << std::endl;
    std::cout << favorites;

    //���� ������ �������������� ������ CallVirtualDisplay ��������� ����������� �����,
    //�� ��������� ������������� ����� ��������� ������,
    //���� ��� ������������� �����, �� ����� ���������� ����� �������� ������
    Playlist* ptrPlaylist = &favorites;
    ptrPlaylist->CallVirtualDisplay();
    
    //������������ ������ ������������ ������
    DeleteItem* itemPtr;

    itemPtr = &myPlaylist;
    itemPtr->DeleteAlbum();

    itemPtr = &favorites;
    itemPtr->DeleteAlbum();

    itemPtr = myArtist;
    itemPtr->DeleteAlbum();

    //������������ ������ ���������� ������
    std::cout << std::endl << "������������ ������ ���������� ������" << std::endl;
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