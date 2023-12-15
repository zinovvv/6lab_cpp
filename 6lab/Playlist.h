#pragma once

#include "Album.h"
#include <string>
#include <vector>

//����� "��������", �������� ������ ������ � ������ ��������
class Playlist {
protected:
    std::string title;
    int numTracks;
    int numAlbums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    //������������
    Playlist(const std::string& title, int numTracks, int numAlbums);
    Playlist(const Playlist& other);
    Playlist();

    //���������� ����� � ��������
    void AddTrack(Track& track);

    void operator+(Track& track);

    //���������� ������� tracks
    void SetTracks(const std::vector<Track>& newTracks);

    //����� ������
    void PrintTracks() const;

    //����������� ����� �������� �����
    virtual void DeleteTrack();

    void CallVirtualDeleteTrack(Playlist& playlist);

    //���������� �������
    void AddAlbum(Album& album);

    //���������� ������� albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    //����� ��������
    void PrintAlbums() const;

    //�������� �������
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

    //����������
    ~Playlist() = default;
};