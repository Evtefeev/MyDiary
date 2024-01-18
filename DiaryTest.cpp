#include <iostream>
#include "Diary.hpp"
#include <cassert>

class DiaryTest
{
public:
    DiaryTest(std::string path)
    {
        this->path = path;
        this->diary = new Diary(path);
    }
    void testAddNote()
    {

        int noteID = diary->addNote("Test Note testAddNote");
        assert(noteID >= 0);
        std::cout << "Test AddNote Passed" << std::endl;
    }

    void testSaveNote()
    {

        int noteID = diary->addNote("Test Note testSaveNote");
        assert(noteID >= 0);

        try
        {
            diary->saveNote(noteID);
            std::cout << "Test SaveNote Passed" << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Test SaveNote Failed: " << e.what() << std::endl;
        }
    }

    void testLoadNotes()
    {

        try
        {
            diary->loadNotes();
            std::cout << "Test LoadNotes Passed" << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Test LoadNotes Failed: " << e.what() << std::endl;
        }
    }

    void testSaveNotes()
    {
        int noteID = diary->addNote("Test Note");
        assert(noteID >= 0);

        try
        {
            diary->saveNotes();
            std::cout << "Test SaveNotes Passed" << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Test SaveNotes Failed: " << e.what() << std::endl;
        }
    }
    void testGetNote()
    {
        int noteID = diary->addNote("Test Note testGetNote");
        assert(noteID >= 0);

        try
        {
            Note note = diary->getNote(noteID);
            if (note.getText() == "Test Note testGetNote")
                std::cout << "Test GetNote Passed" << std::endl;
            else
                throw std::runtime_error("note text not same");
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Test GetNote Failed: " << e.what() << std::endl;
        }
    }

    void testGetCount()
    {
        int noteID = diary->addNote("Test Note testGetCount");
        assert(noteID >= 0);

        try
        {
            int count = diary->getCount();
            if (count - 1 == noteID)
                std::cout << "Test GetCount Passed" << std::endl;
            else
                throw std::runtime_error("count not correct");
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Test GetCount Failed: " << e.what() << std::endl;
        }
    }

    void runAll()
    {
        testAddNote();
        testSaveNote();
        testLoadNotes();
        testSaveNotes();
        testGetNote();
        testGetCount();
    }

private:
    std::string path;
    Diary *diary;
};

int main()
{

    DiaryTest test("testdiary.txt");
    test.runAll();
    return 0;
}
