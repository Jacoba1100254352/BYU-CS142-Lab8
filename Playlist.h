#ifndef LAB_8_PLAYLIST_H
#define LAB_8_PLAYLIST_H

#include <string>
#include <vector>
#include "Song.h"

class Playlist
{
public:

    /******************
    *   CONSTRUCTOR   *
    ******************/
    explicit Playlist(std::string playlistName = "none");

    /****************************
    *   GET AND SET FUNCTIONS   *
    ****************************/
    //void SetPlaylistName(std::string);
    std::string GetPlaylistName();
    std::string SongName(unsigned long);
    Song* GetSpecificSong(unsigned long);
    void AddSong(Song*);
    void RemoveSong(unsigned long);
    void RemoveAllSongs();
    unsigned long AmountOfSongs();

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
    std::string playlistName;
    std::vector<Song*> songs;
};


#endif //LAB_8_PLAYLIST_H
