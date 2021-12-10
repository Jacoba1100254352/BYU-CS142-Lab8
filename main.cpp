#include <iostream>
#include <vector>

///   Class Includes   ///
#include "Song.h"
#include "Playlist.h"

///   User Input Function Declarations   ///
std::string GetUserString(const std::string&);
int GetUserInt(const std::string&);
void ListSongsMenu(Playlist&);

///   Control Function Declarations   ///
void AddSongsMenuOption(Playlist&);
void ListSongsMenuOption(Playlist&);
void AddPlaylistMenuOption(std::vector<Playlist*>&);
void AddSongToPlaylistMenuOption(std::vector<Playlist*>&, Playlist&);
void ListPlaylistsMenuOption(std::vector<Playlist*>&);
void PlayPlaylistMenuOption(std::vector<Playlist*>&);
void RemovePlaylistMenuOption(std::vector<Playlist*>&);
void RemoveSongFromPlaylistMenuOption(std::vector<Playlist*>&);
void RemoveSongFromLibraryMenuOption(std::vector<Playlist*>&, Playlist&);
void OptionsMenuOption();
void QuitMenuOption(std::vector<Playlist*>&, Playlist&);


/***********
*   Main   *
***********/

int main()
{
    ///   Vector Declarations   ///
    std::vector<Playlist*> playlists;
    Playlist songList;

    ///   Variable Initializations   ///
    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    ///   Welcome Message   ///
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    ///   Main While Loop   ///
    while (continueMenuLoop)
    {
        std::cout << std::endl;
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add")
        {
            AddSongsMenuOption(songList);
        }
        else if (userMenuChoice == "list")
        {
            ListSongsMenuOption(songList);
        }
        else if (userMenuChoice == "addp")
        {
            AddPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "addsp")
        {
            AddSongToPlaylistMenuOption(playlists, songList);
        }
        else if (userMenuChoice == "listp")
        {
            ListPlaylistsMenuOption(playlists);
        }
        else if (userMenuChoice == "play")
        {
            PlayPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remp")
        {
            RemovePlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remsp")
        {
            RemoveSongFromPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remsl")
        {
            RemoveSongFromLibraryMenuOption(playlists, songList);
        }
        else if (userMenuChoice == "quit")
        {
            QuitMenuOption(playlists, songList);
            continueMenuLoop = false;
        }
        else // Also, If userMenuChoice == "options"
        {
            OptionsMenuOption();
        }
    }

    return 0;
}


/***************************
*   User Input Funcitons   *
***************************/

std::string GetUserString(const std::string& prompt)
{

    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;

    return userAnswer;
}
int GetUserInt(const std::string& prompt)
{
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;

    return userAnswer;
}
void ListSongsMenu(Playlist& playlist)
{
    for (unsigned long i = 0; i < playlist.AmountOfSongs(); i++)
    {
        std::cout << "  " << i << ": " << playlist.SongName(i) << std::endl;
    }
}


/************************
*   Control Functions   *
************************/

void AddSongsMenuOption(Playlist& songList)
{
    ///   Variable Initializations   ///
    std::string songName = "none";
    std::string firstLine = "none";
    const std::string DONE_KEYWORD = "DONE";

    ///   Input Song Names and First Lines   ///
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    songName = GetUserString("Song Name: "); // Song Name
    while (songName != DONE_KEYWORD)
    {
        firstLine = GetUserString("Song's first line: "); // First Line

        songList.AddSong(new Song(songName, firstLine)); // Add Song

        songName = GetUserString("Song Name: "); // Song Name
    }
}
void ListSongsMenuOption(Playlist& songList)
{
    ///   Print Songs and Song Info   ///
    for (unsigned long i = 0; i < songList.AmountOfSongs(); i++)
    {
        std::cout << songList.GetSpecificSong(i)->GetSongName() << ": \""
                  << songList.GetSpecificSong(i)->GetFirstLine() << "\", "
                  << songList.GetSpecificSong(i)->GetPlays() << " play(s)."
                  << std::endl;
    }
}
void AddPlaylistMenuOption(std::vector<Playlist*>& playlists)
{
    ///   Variable Initializations   ///
    std::string playlistName = "none";

    ///   Input and Add Playlist   ///
    playlistName = GetUserString("Playlist name: ");
    playlists.push_back(new Playlist(playlistName));
}
void AddSongToPlaylistMenuOption(std::vector<Playlist*>& playlists, Playlist& songList)
{
    ///   Variable Initializations   ///
    int playlistIndex = 0;
    int songIndex = 0;

    ///    Print and Pick Playlist   ///
    ListPlaylistsMenuOption(playlists); // Print Playlists
    playlistIndex = GetUserInt("Pick a playlist index number: "); // Pick Playlist

    ///   Print and Pick Song   ///
    ListSongsMenu(songList); // Print Songs
    songIndex = GetUserInt("Pick a song index number: "); // Pick Song
    playlists.at(playlistIndex)->AddSong(songList.GetSpecificSong(songIndex)); // Add Song to Playlist
}
void ListPlaylistsMenuOption(std::vector<Playlist*>& playlists)
{
    ///   Print Playlists   ///
    for (unsigned long i = 0; i < playlists.size(); i++)
    {
        std::cout << "  " << i << ": " << playlists.at(i)->GetPlaylistName() << std::endl;
    }
}
void PlayPlaylistMenuOption(std::vector<Playlist*>& playlists)
{
    ///   Variable Initializations   ///
    int playlistIndex = 0;

    ///   Print and Pick Playlist   ///
    ListPlaylistsMenuOption(playlists);
    playlistIndex = GetUserInt("Pick a playlist index number: ");

    ///   Print and Play Songs from Playlist   ///
    std::cout << "Playing songs from playlist: " << playlists.at(playlistIndex)->GetPlaylistName() << std::endl;
    for(unsigned long i = 0; i < playlists.at(playlistIndex)->AmountOfSongs(); i++)
    {
        std::cout << playlists.at(playlistIndex)->GetSpecificSong(i)->GetFirstLine() << std::endl; // Print First Line
        playlists.at(playlistIndex)->GetSpecificSong(i)->SetPlays(1); // Increment Play Count
    }
}
void RemovePlaylistMenuOption(std::vector<Playlist*>& playlists)
{
    ///   Variable Initializations   ///
    int playlistIndex = 0;

    ///   Print and Pick Playlist   ///
    ListPlaylistsMenuOption(playlists);
    playlistIndex = GetUserInt("Pick a playlist index number to remove: ");

    ///   Delete Playlist and Free Playlist Memory   ///
    delete playlists.at(playlistIndex);
    playlists.erase(playlists.begin() + playlistIndex);
}
void RemoveSongFromPlaylistMenuOption(std::vector<Playlist*>& playlists)
{
    ///   Variable Initializations   ///
    int playlistIndex = 0;
    int songIndex = 0;

    ///   Print and Pick Playlist   ///
    ListPlaylistsMenuOption(playlists);
    playlistIndex = GetUserInt("Pick a playlist index number: ");

    ///   Print Songs in Playlist   ///
    for (unsigned long i = 0; i < playlists.at(playlistIndex)->AmountOfSongs(); i++)
    {
        std::cout << "  " << i << ": " << playlists.at(playlistIndex)->SongName(i) << std::endl;
    }
    songIndex = GetUserInt("Pick a song index number to remove: "); // Pick Song to Remove

    ///   Remove Song from Playlist   ///
    playlists.at(playlistIndex)->RemoveSong(songIndex);
}
void RemoveSongFromLibraryMenuOption(std::vector<Playlist*>& playlists, Playlist& songList)
{
    ///   Variable Initializations   ///
    int songIndex = 0;

    ///   Print and Pick Songs   ///
    ListSongsMenu(songList);
    songIndex = GetUserInt("Pick a song index number to remove: "); // Pick Song to Remove

    ///   Remove Song from each Playlist   ///
    for (auto & playlistIt : playlists) // PlaylistIt is playlistIterator
    {
        for (unsigned long j = 0; j < playlistIt->AmountOfSongs(); j++)
        {
            if (playlistIt->SongName(j) == songList.SongName(songIndex))
            {
                playlistIt->RemoveSong(j);
            }
        }
    }

    ///   Freeing Song Memory   ///
    delete songList.GetSpecificSong(songIndex);
    songList.RemoveSong(songIndex);
}
void OptionsMenuOption()
{
    ///   Print Menu Options   ///
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}
void QuitMenuOption(std::vector<Playlist*>& playlists, Playlist& songList)
{
    ///   Remove all Songs from each Playlist   ///
    for (auto & playlistIt : playlists) // PlaylistIt is playlistIterator
    {
        playlistIt->RemoveAllSongs();
    }

    ///   Free All Songs from Memory   ///
    for (unsigned long i = 0; i < songList.AmountOfSongs(); i++)
    {
        delete songList.GetSpecificSong(i);
        songList.RemoveSong(i);
    }

    ///   Delete all Playlists   ///
    for (unsigned long i = playlists.size() - 1; i > 0; --i)
    {
        delete playlists.at(i);
        playlists.erase(playlists.begin() + static_cast<long>(i));
    }

    ///   Send Goodbye Message   ///
    std::cout << "Goodbye!" << std::endl;
}
