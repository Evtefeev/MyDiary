#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "Note.hpp"

class Diary
{
public:
    Diary(std::string path)
    {
        filePath = path;
    }

    int addNote(std::string noteText)
    {
        notes.push_back(Note(noteText));
        return notes.size() - 1;
    }

    void saveNote(int noteID)
    {
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open())
        {
            file << notes[noteID].getText() << "\n"
                 << notes[noteID].getDate() << "\n";
        }
        else
        {
            throw std::runtime_error("error opening file for write");
        }
        notes[noteID].makeSaved();
        file.close();
    }

    void loadNotes()
    {
        notes.clear();
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string noteText;
            std::string noteDate;

            while (std::getline(file, noteText))
            {
                if (noteText != "")
                {
                    std::getline(file, noteDate);
                    notes.push_back(Note(noteText, noteDate));
                }
            }
        }
        else
        {
            throw std::runtime_error("error opening file for read");
        }
        file.close();
    }

    void saveNotes()
    {
        int id = 0;
        for (Note note : notes)
        {
            if (!note.isSaved())
                saveNote(id);
            id++;
        }
    }

    Note getNote(int noteID)
    {
        return notes[noteID];
    }

    int getCount()
    {
        return notes.size();
    }

private:
    std::string filePath;
    std::vector<Note> notes;
};