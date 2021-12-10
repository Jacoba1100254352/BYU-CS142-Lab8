#include "Playlist.h"


/******************
*   CONSTRUCTOR   *
******************/
Playlist::Playlist(std::string playlistName)
{
    this->playlistName = std::move(playlistName);
}


/****************************
*   GET AND SET FUNCTIONS   *
****************************/
//void Playlist::SetPlaylistName(std::string playlistName)
//{
//    this->playlistName = std::move(playlistName);
//}
std::string Playlist::GetPlaylistName()
{
    return playlistName;
}
std::string Playlist::SongName(unsigned long index)
{
    return songs.at(index)->GetSongName();
}
Song* Playlist::GetSpecificSong(unsigned long desiredLocation)
{
    return this->songs.at(desiredLocation);
}
void Playlist::AddSong(Song* song)
{
    this->songs.push_back(song);
}
void Playlist::RemoveSong(unsigned long songIndex)
{
    this->songs.erase(this->songs.begin() + static_cast<long>(songIndex));
}
void Playlist::RemoveAllSongs()
{
    this->songs.erase(this->songs.begin(), this->songs.end());
}
unsigned long Playlist::AmountOfSongs()
{
    return songs.size();
}
