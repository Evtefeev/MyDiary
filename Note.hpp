#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

class Note
{
    std::string text;
    std::string date;
    bool saved = false;

public:
    Note(std::string noteText)
    {
        this->text = noteText;
        time_t now = time(0);
        this->date = ctime(&now);
    }
    Note(std::string noteText, std::string date)
    {
        this->text = noteText;
        this->date = date;
        this->saved = true;
    }
    std::string getText()
    {
        return text;
    }
    std::string getDate()
    {
        return date;
    }
    void makeSaved()
    {
        saved = true;
    }

    bool isSaved()
    {
        return saved;
    }
};
