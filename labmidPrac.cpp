#include<iostream>
#include<string>
using namespace std;
class User{};
class Comment{
    int commentID;
    string content;
    User *author;
    public:
    Comment(){}
    Comment(int id,string cont):commentID(id),content(cont){}
    int getCommentID(){return commentID;}
    string getContent(){return content;}

};

class Post{
    int postID;
    string content;
    Comment *comments = nullptr;
    public:
    int index =0;
    Post(){}

    Post(int id,string cont):postID(id),content(cont){}
    void addComment(){
        Comment *temp = new Comment[index+1];
        for (int i = 0; i < index; i++)
        {
            temp[i] =comments[i];
        }
        delete [] comments;
        comments= temp;
        comments[index] =Comment(index+1,"Comment " + index+1);
        index++;
    
    }
    int getPostID(){
        return postID;
    }
    string getContent(){return content;}

};
class User{
    int userID;
    string userName;
    public:
    Post *posts = new Post[0];
    int index = 0;
    User(){}
    User(int id,string name){
        userID  =id;
        userName= name;  
    }
    void addPost(){
        Post *temp = new Post[index+1];
        for (int i = 0; i < index; i++)
        {
            temp[i] =posts[i];
        }
        delete [] posts;
        posts= temp;
        posts[index] = Post(index+5,"Post " + index+1);
        index++;
    
    }
    int getUserID(){return userID;}
    string getUsername(){return userName;}

};
class SocialMediaPlatform{
    User *users = new User[0];
    
    public:
    int index = 0;
    SocialMediaPlatform(){
    
    }
    void addUser(){
        User *temp = new User[index+1];
        for (int i = 0; i < index; i++)
        {
            temp[i] =users[i];
        }
        delete [] users;
        users = temp;
        users[index] = User(index+1,"Name " + index+1);
        index++;
        
    }
    void display(){
        for (int i = 0; i < index; i++)
        {
            
            cout<<"User ID: "<<users[i].getUserID()<<endl;
            cout<<"UserName: "<<users[i].getUsername()<<endl;
            users[i].addPost();
            users[i]. addPost();
            cout<<"Post ID: "<<users[i].getUserID()<<endl;
            cout<<"UserName: "<<users[i].getUsername()<<endl;
            //users[i].posts[i].addComment        
        }
        
    }


};
int main(){
    SocialMediaPlatform obj;
    obj.addUser();
    obj.addUser();
    obj.display();
}