#pragma once

class LibraryItem {
public:
    virtual void DisplayInfo() const = 0;
    virtual ~LibraryItem() = default;
};