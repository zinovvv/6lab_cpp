#pragma once

#include <string>

//����� "����"
class Track{
private:

    std::string title;
    std::string artist;
    int duration;
    int year;
    std::string genre;
    int listens = 0;
    //����������� ����(����� ���-�� ������)
    static int trackCount;
public:
    //����������� � �����������
    Track(const std::string& title, const std::string& artist, int duration, int year, const std::string& genre);

    //����������� ����������� � ����� ����������
    Track(const Track& other);

    //������ �����������
    Track();

    //���� �����
    static Track InputTrack();

    //������� ������� �����
    static Track InputShortTrack();

    //����� ����� � ������� �������������� ��������� <<
    friend std::ostream& operator<<(std::ostream& os, const Track& obj);
    
    //�������� ����� �����
    void DisplayInfo() const;

    //���������� ��������� ++(����������)
    Track& operator++();

    //���������� ��������� ++(�����������)
    Track operator++(int);

    //����������
    ~Track() = default;
};
 