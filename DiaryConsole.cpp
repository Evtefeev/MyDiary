#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <limits> // for numeric_limits

#include "Diary.hpp"

class DiaryConsole
{
public:
    DiaryConsole()
    {
        diary = new Diary(path);
        // try
        // {
        //     diary->loadNotes();
        // }
        // catch (const std::runtime_error &e)
        // {
        //     std::cout << "Warning: file " << path << " not opened\n";
        // }
    }

    void startShowNote()
    {
        diary->loadNotes();
        int count = diary->getCount();
        if (count > 0)
        {
            system("clear");

            std::cout << "Found " << count << " notes\n";
            std::cout << "Enter ID (0 - " << count - 1 << ") to show\n";
            int id;
            std::cin >> id;
            bool stop = false;
            while (!stop)
            {
                try
                {
                    Note note = diary->getNote(id);
                    std::cout << note.getText() << std::endl
                              << note.getDate() << std::endl;
                }
                catch (const std::runtime_error &e)
                {
                    std::cout << "Incorrect ID\n";
                }
                std::cout << "\nn - next\np - prew\ne - exit\n";
                char res;
                std::cin >> res;
                switch (res)
                {
                case 'n':
                    id++;
                    break;
                case 'p':
                    id--;
                    break;
                case 'e':;
                    stop = true;
                    break;

                default:
                    break;
                }
            }
        }
        else
        {
            std::cout << "No notes found \n";
        }
    }

    void startCreateNote()
    {
        system("clear");

        std::cout << "Enter text:\n";
        std::string text;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, text);

        int id = diary->addNote(text);
        std::cout << "Save to file? (y/n): ";
        char res;
        std::cin >> res;
        if (res == 'y')
        {
            diary->saveNote(id);
        }
    }
    void exit()
    {
        system("clear");

        std::cout << "Save notes to file? (y/n): ";
        char res;
        std::cin >> res;
        if (res == 'y')
        {
            diary->saveNotes();
        }
        working = false;
    }
    void startApp()
    {

        working = true;
        while (working)
        {
            system("clear");
            std::cout << "Welcome to DiaryConsole!\n\n";
            std::cout << path << " diary opened\n\n";
            std::cout << "Select action:\n 1 - show notes\n 2 - create note\n 3 - exit\n";
            char res;
            std::cin >> res;
            if (res == '1')
            {
                startShowNote();
            }
            else if (res == '2')
            {
                startCreateNote();
            }
            else if (res == '3')
            {
                exit();
            }
            else
            {
                std::cout << "Incorrect command\n";
            }
        }
    }

private:
    std::string path = "mydiary.txt";
    Diary *diary;
    bool working = false;
};

int main()
{
    DiaryConsole cl;

    cl.startApp();

    return 0;
}