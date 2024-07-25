#include<iostream>
#include<string>
using namespace std;
class Movie{
    string title,director;
    int duration;
    public:
    Movie(){}
    Movie(const string& tit,const string& dir,int dur):title(tit),director(dir),duration(dur) {}
    string getTitle() const{return title;}
    string getDirector() const{return director;}
    int getDuration() const{return duration;}
};
class Playlist{
    string name;
    Movie *movies;
    int numMovies;
    public:
    int resizeCount = 5;
    Playlist(){numMovies = 0; movies = new Movie[resizeCount];}
    Playlist(const string& name){
        this->name = name;
        numMovies = 0;
        movies = new Movie[resizeCount];
    }
    void addMovie(Movie *movie){
        //out<<"check1\n";
        if (numMovies==resizeCount)
        {
            resizeCount*=2;
            Movie *temp = new Movie[resizeCount];
            for (int i = 0; i <numMovies; i++)
            {
                
                temp[i] = movies[i];
            }
            
            delete [] movies;
            movies = temp;
        }
            movies[numMovies++] = *movie;
    cout << "Movie added to playlist: " << movie->getTitle() << endl;
    cout << "Number of movies in playlist: " << numMovies << endl;
            }
    void removeMovie(Movie *movie){
        Movie* temp = new Movie[numMovies - 1];
    int j = 0; // index for the temporary array
    for (int i = 0; i < numMovies; i++) {
        if (!(movies[i].getDirector() == movie->getDirector() && movies[i].getDuration() == movie->getDuration() && movies[i].getTitle() == movie->getTitle())) {
            temp[j++] = movies[i];
        }
    }
    delete[] movies;
    movies = temp;
    numMovies--;
        
    }
    void displayInfo(){
        
        for (int i = 0; i <numMovies; i++)
        {
            cout<<"Movie "<<i+1<<"details\n";
            cout<<"Title: "<<movies[i].getTitle()<<endl;
            cout<<"Director: "<<movies[i].getDirector()<<endl;
            cout<<"Duration: "<<movies[i].getDuration()<<endl<<endl;
        }
        
    }
    string getPlaylistName(){return name;}
};  
class User{
    string name;
    int numPlaylists;
    public:
    Playlist *playlists;
    User(){numPlaylists = 0;}
    int resizeCount = 5;
    User(const string& uName):name(uName){
        numPlaylists = 0;
        playlists = new Playlist[resizeCount];
    }
    void createPlaylist(Playlist *playlist){
        if (numPlaylists==resizeCount)
        {
            resizeCount*=2;
            Playlist *temp = new Playlist[resizeCount];
            for (int i = 0; i <numPlaylists; i++)
            {
                temp[i] = playlists[i];
            }
            delete [] playlists;
            playlists= temp;
        
        }
            
            playlists[numPlaylists]=Playlist(playlist->getPlaylistName());
            numPlaylists++;
    }
    void addMovieToPlaylist(Playlist *playlist,Movie *movie){
        playlist->addMovie(movie);
        //playlist->displayInfo();
        
    }
    
    void RemoveFromPlaylist(Playlist *playlist,Movie *movie){
        playlist->removeMovie(movie);
    }
    void displayUserPlaylists(){
        for (int i = 0; i < numPlaylists; i++)
        {
            playlists[i].displayInfo();
        }
        
    }
};
int main(){
     User mujeeb("Mujeeb Ur Rehman");

    // Create playlists
    Playlist pl1("Action Movies");
    Playlist pl2("Comedy Movies");

    // Add playlists to the user
    mujeeb.createPlaylist(&pl1);
    mujeeb.createPlaylist(&pl2);

    // Create movies
    Movie movie1("The Dark Knight", "Christopher Nolan", 152);
    Movie movie2("Inception", "Christopher Nolan", 148);
    Movie movie3("The Hangover", "Todd Phillips", 100);
    Movie movie4("Superbad", "Greg Mottola", 113);

    // Add movies to playlists
    mujeeb.addMovieToPlaylist(&mujeeb.playlists[0], &movie1);
    mujeeb.addMovieToPlaylist(&mujeeb.playlists[0], &movie2);
    mujeeb.addMovieToPlaylist(&mujeeb.playlists[1], &movie3);
    mujeeb.addMovieToPlaylist(&mujeeb.playlists[1], &movie4);

    // Display playlists with movies
    mujeeb.displayUserPlaylists();

    // mujeeb.RemoveFromPlaylist(&pl1,&movie2);
    // cout<<"After removing Inception\n\n";
    // mujeeb.displayUserPlaylists();

}