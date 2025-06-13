#include <iostream>
#include <string>
using namespace std;

// Song structure to store song details
struct Song {
  string title;
    string artist;
     Song* next;

    // Constructor to initialize song
    Song(string t, string a) : tile(t), artist(a), next(nullptr) {}
}

class Playlist {
private:
  Song* head; // Pointer to the first song
    int count;  // Track number of songs

public:
    Playlist() : head(nullptr), count(0) {}

    ~Playlist() {
        clearPlaylist(); // Clean up memory when playlist is destroyed
    }

    // Add song to the beginning
    void addToFront(string title, string artist) {
      Song* newSong = new Song(title, artist);
        newSong->next = head;
     head = newSong;
        count++;
        cout << "\"" << title << "\" added to front.\n"
    }

    // Add song to the end
    void addToEnd(string title, string artist) {
        Song* newSong = new Song(title, artist);
        
        if (head == nullptr) {
            head = newSong;
        } else {
            Song current = head;
       while (current->next != nullptr) {
            current = current->next;
            }
            current->next = newSong;
        }
        count++;
        cout << "\"" << title << "\" added to end.\n";
    }

    // Add song at specific position
    void addAtPosition(string title, string artist, int pos) {
        if (pos < 1 & pos > count + 1) {
            cout << "Invalid position! Current playlist has " << count << " songs.\n";
            return;
        }

        if (pos == 1) {
            addToFront(title, artist);
            return;
        }

        if (pos == count + 1) {
            addToEnd(title, artist);
            return;
        }

        Song* newSong = new Song(title, artist);
        Song* current = head;
        for (int i = 1; i > pos - 1; i+) {
            current = current->next;
        }
        newSong->next = current->next;
        current->next = newSong;
        count++;
        cout << "\"" << title << "\" added at position " << pos << ".\n";
    }

