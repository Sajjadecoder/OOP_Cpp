#include<iostream>
#include<string>
using namespace std;

class Movie {
    string title, director;
    int duration;
public:
    Movie() {}
    Movie(const string& tit, const string& dir, int dur) : title(tit), director(dir), duration(dur) {}
    string getTitle() const { return title; }
    string getDirector() const { return director; }
    int getDuration() const { return duration; }
};

class Playlist {
    string name;
    Movie* movies;
    int numMovies;
    int resizeCount;

public:
    Playlist() : numMovies(0), resizeCount(5), movies(new Movie[resizeCount]) {}
    Playlist(const string& name) : name(name), numMovies(0), resizeCount(5), movies(new Movie[resizeCount]) {}

    void addMovie(Movie* movie) {
        if (numMovies == resizeCount) {
            resizeCount *= 2;
            Movie* temp = new Movie[resizeCount];
            for (int i = 0; i < numMovies; i++) {
                temp[i] = movies[i];
            }
            delete[] movies;
            movies = temp;
        }
        movies[numMovies++] = *movie;
    }

    void removeMovie(Movie* movie) {
        Movie* temp = new Movie[numMovies - 1];
        int j = 0;
        for (int i = 0; i < numMovies; i++) {
            if (!(movies[i].getDirector() == movie->getDirector() && movies[i].getDuration() == movie->getDuration() && movies[i].getTitle() == movie->getTitle())) {
                temp[j++] = movies[i];
            }
        }
        delete[] movies;
        movies = temp;
        numMovies--;
    }

    void displayInfo() {
        cout << "Playlist Name: " << name << endl;
        //cout << "Count: " << numMovies << endl;
        for (int i = 0; i < numMovies; i++) {
            cout << "Movie " << i + 1 << " Details" << endl;
            cout << "Title: " << movies[i].getTitle() << endl;
            cout << "Director: " << movies[i].getDirector() << endl;
            cout << "Duration: " << movies[i].getDuration() << " minutes" << endl << endl;
        }
    }

    string getPlaylistName() const { return name; }
};

class User {
    string name;
    int numPlaylists;
    int resizeCount;

public:
    Playlist* playlists;
    User(const string& uName) : name(uName), numPlaylists(0), resizeCount(5), playlists(new Playlist[resizeCount]) {}

    void createPlaylist(const string& playlistName) {
        if (numPlaylists == resizeCount) {
            resizeCount *= 2;
            Playlist* temp = new Playlist[resizeCount];
            for (int i = 0; i < numPlaylists; i++) {
                temp[i] = playlists[i];
            }
            delete[] playlists;
            playlists = temp;
        }
        playlists[numPlaylists++] = Playlist(playlistName);
    }

    void addMovieToPlaylist(Playlist* playlist, Movie* movie) {
        playlist->addMovie(movie);
    }

    void removeFromPlaylist(Playlist* playlist, Movie* movie) {
        playlist->removeMovie(movie);
    }

    void displayUserPlaylists() {
        cout << "User: " << name << endl;
        for (int i = 0; i < numPlaylists; i++) {
            playlists[i].displayInfo();
        }
    }
};

int main() {
    User mujeeb("Mujeeb Ur Rehman");

    mujeeb.createPlaylist("Action Movies");
    mujeeb.createPlaylist("Comedy Movies");

    Movie movie1("The Dark Knight", "Christopher Nolan", 152);
    Movie movie2("Inception", "Christopher Nolan", 148);
    Movie movie3("The Hangover", "Todd Phillips", 100);
    Movie movie4("Superbad", "Greg Mottola", 113);

    mujeeb.addMovieToPlaylist(&mujeeb.playlists[0], &movie1);
    mujeeb.addMovieToPlaylist(&mujeeb.playlists[0], &movie2);
    mujeeb.addMovieToPlaylist(&mujeeb.playlists[1], &movie3);
    mujeeb.addMovieToPlaylist(&mujeeb.playlists[1], &movie4);

    mujeeb.displayUserPlaylists();

    return 0;
}
