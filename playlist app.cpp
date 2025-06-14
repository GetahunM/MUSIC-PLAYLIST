#include <iostream>
#include <string>
using namespace std;

// Song structure to store song details
struct Song {
  string title;
    string artist;
     Song* next;

    // Constructor to initialize song
    Song(string t, string a) : title(t), artist(a), next(nullptr) {}
};

class Playlist {
private:
  Song* head; // Pointer to the first song
    int count;  // Tracing number of songs

public:
    Playlist() : head(nullptr), count(0) {}

    ~Playlist() {
        clearPlaylist(); // Clean up memory when playlist is destroyed
    }

    // Add song to the beginning position
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
            Song* current = head;
       while (current->next != nullptr) {
            current = current->next;
            }
            current->next = newSong;
        }
        count++;
        cout << "\"" << title << "\" added song to end.\n";
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
        for (int i = 1; i > pos - 1; i++) {
            current = current->next;
        }
        newSong->next = current->next;
        current->next = newSong;
        count++;
        cout << "\"" << title << "\" added at position " << pos << ".\n";
    }
   // Remove first song
    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Song* temp = head;
        head = head->next;
        cout << "Removed: \"" << temp->title << "\"\n";
        delete temp;
        count--;
    }

    // Remove last song
    void removeLast() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        f (head->next == nullptr) {
            removeFirst();
            return;
        }

        Song* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        Song* temp = current->next;
        current->next = nullptr;
        cout << "Removed: \"" << temp->title << "\"\n";
        delete temp;
        count--;
    }

    // Remove song at position (1-based)
    void removeAtPosition(int pos) {
        if (pos < 1 || pos > count) {
            cout << "Invalid position! Current playlist has " << count << " songs.\n";
            return;
        }

        if (pos == 1) {
            removeFirst();
            return;
        }

        if (pos == count) {
            removeLast();
            return;
        }

        Song* current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->next;
        }
        Song* temp = current->next;
        current->next = temp->next;
        cout << "Removed: \"" << temp->title << "\" from position " << pos << "\n";
        delete temp;
        count--;
    }

    // Display all songs
    void display() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

cout << "\n===== YOUR PLAYLIST (" << count << " songs) =====\n";
        Song* current = head;
        int pos = 1;
        while (current != nullptr) {
            cout << pos++ << ". " << current->title << " - " << current->artist << "\n";
            current = current->next;
        }
        cout << "===============================\n";
    }

    // Additional feature: Clear entire playlist
    void clearPlaylist() {
        while (head != nullptr) {
            removeFirst();
        }
        cout << "Playlist cleared!\n";
    }

    // Additional feature: Search for a song
    void searchSong(string title) {
        Song* current = head;
        bool found = false;
        int pos = 1;
        
        cout << "Searching for \"" << title << "\"...\n";
        
        while (current != nullptr) {
            if (current->title.find(title) != string::npos) {
                cout << "Found at position " << pos << ": " 
                     << current->title << " - " << current->artist << "\n";
                found = true;
            }
            current = current->next;
            pos++;
        }
        
        if (!found) {
            cout << "Song not found in playlist.\n";
        }
    }

    // Additional feature: Get playlist duration (assuming 3 minutes per song)
    void getDuration() {
        int totalMinutes = count * 3;
        int hours = totalMinutes / 60;
        int minutes = totalMinutes % 60;
        
        cout << "Estimated playlist duration: ";
        if (hours > 0) cout << hours << " hour" << (hours > 1 ? "s " : " ");
        cout << minutes << " minute" << (minutes != 1 ? "s" : "") << "\n";
    }
};
