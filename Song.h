#ifndef LAB_8_SONG_H
#define LAB_8_SONG_H

#include <string>

class Song
{
public:

    /******************
    *   CONSTRUCTOR   *
    ******************/
    explicit Song(std::string songName = "none", std::string firstLine = "none", int plays = 0);

    /****************************
    *   GET AND SET FUNCTIONS   *
    ****************************/
    //void SetSongName(std::string);
    std::string GetSongName();
    //void SetFirstLine(std::string);
    std::string GetFirstLine();
    void SetPlays(int);
    [[nodiscard]] int GetPlays() const;

    /************************
    *   Control FUNCTIONS   *
    ************************/

    /**********************
    *   Print FUNCTIONS   *
    **********************/

    /************************
    *   PRIVATE VARIABLES   *
    ************************/
private:
    std::string songName;
    std::string firstLine;
    int plays;
};


#endif //LAB_8_SONG_H
