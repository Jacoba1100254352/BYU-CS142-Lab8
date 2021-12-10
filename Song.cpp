#include "Song.h"


/******************
*   CONSTRUCTOR   *
******************/
Song::Song(std::string songName, std::string firstLine, int plays )
{
    this->songName = std::move(songName);
    this->firstLine = std::move(firstLine);
    this->plays = plays;
}


/****************************
*   GET AND SET FUNCTIONS   *
****************************/
//void Song::SetSongName(std::string songName)
//{
//    this->songName = std::move(songName);
//}
std::string Song::GetSongName()
{
    return songName;
}
//void Song::SetFirstLine(std::string firstLine)
//{
//    this->firstLine = std::move(firstLine);
//}
std::string Song::GetFirstLine()
{
    return firstLine;
}
void Song::SetPlays(int play)
{
    this->plays = this->plays + play;
}
int Song::GetPlays() const
{
    return plays;
}