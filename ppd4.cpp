#include<bits/stdc++.h>
using namespace std;
class QuestionClass{
    private: 
        string question,answer;
        int difficuty;
    public: 
        QuestionClass(string qP,string aP,int dP){
            this->question = qP;
            this->answer = aP;
            this->difficuty = dP;
        }
        QuestionClass(){}
        string getQuestion(){
            return question;
        }
        string getAnswer(){
            return answer;
        }
        int getDifficulty(){
            return difficuty;
        }

};

class QuizzClass:public QuestionClass
{
private:
    QuestionClass  Questions[20];
    int noOfQuestions;
public:
   QuizzClass()  {
        // Initialize each element of the array explicitly
        for (int i = 0; i < 20; ++i) {
            Questions[i] = QuestionClass("", "", 0);
        }
        noOfQuestions = 0;


    }   
    //QuizzClass(){}

    int AddQuestion(QuestionClass obj){
        string currentQuestion = obj.getQuestion();
        if (noOfQuestions==20)
        {
            return 0;
        }
        Questions[noOfQuestions] = obj;
        noOfQuestions++;
        return 1;
    }
    string getQ(){
        Questions[noOfQuestions].getQuestion();
    }


};
int main(){
    QuizzClass FirstQuiz;
    QuestionClass Question1("What is 100/5?","20",1);
    
    FirstQuiz.AddQuestion(Question1);
    cout<<FirstQuiz.getQuestion();
}