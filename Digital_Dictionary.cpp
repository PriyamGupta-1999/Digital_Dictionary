#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    string meaning;
    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word,string meaning_of_word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            root->meaning=meaning_of_word;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1),meaning_of_word);
    }

    void insertWord(string word,string meaning_of_word) { 
        insertWord(root, word,meaning_of_word); 
    }
    
    
    bool search(TrieNode *root,string word){
        if(word.size()==0){
            if(root->isTerminal==true){
                cout<<root->meaning<<endl;
                return true;
            }else{
                return false;
            }
        }
        
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child = root->children[index];
            return search(child,word.substr(1));
        }else{
            return false;
        }
        
    }

    bool search(string word) {
        // Write your code here
       bool ans=search(root,word);
        return ans;
    }
};




int main() {
    int choice;
    //cin >> choice;
    Trie t;

  fstream newfile;
  
   newfile.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      string tp;
      int i=0;
      string word=" ";
      string meaning_word=" ";
      while(getline(newfile, tp)){ //read data from file object and put it into string.
        //cout<<i<<word<<meaning_word<<endl;
        if(tp==" "){
            continue;
        }
        if(i%2==0){
            word=tp;
        }else{
            meaning_word=tp;

           t.insertWord(word,meaning_word);
        }
        i++;
     }


     cout<<"Welcome to dictionary "<<endl;

     cout<<" Here are the choices "<<endl<<"1. Enter the new word in dictionary "<<endl<<"2. Search For word and dictionary"<<endl<<"3. To close please press -1"<<endl;

     int choice;
     cin>>choice;

     while(choice!=-1){
        if(choice==1){
            cout<<"Enter the new word: ";
            string word;
            string meaning_of_word;
            cin>>word;
            cout<<"Enter the meaning of word with '.' at the end: ";
            getline(cin,meaning_of_word,'.');
            ofstream score("input.txt", ios_base::app | ios_base::out);

            if(newfile.is_open()) //checking whether the file is open
             {
                score<<"\n"<<word;
                score<<meaning_of_word;   //inserting text
       //newfile.close();    //close the file object
            }

            t.insertWord(word,meaning_of_word);
            //cout<<endl;
        }else if(choice==2){
            string word;
            cout<<"Enter word to get its meaning"<<endl;
            cin>>word;
            if(!t.search(word)){
                cout<<"Word not present!"<<endl;
            }

        }
        cin>>choice;
     }






      newfile.close(); //close the file object.
   }

 

    

    return 0;
}
    

        /*string meaning_of_word;
        getline(cin,meaning_of_word);
        t.insertWord("hello",meaning_of_word);
        t.insertWord("hello1","priyam1");
        t.insertWord("hello2","priyam2");

        cin >> word;
        cout << (t.search(word) ? "true\n" : "false\n");

        cin >> word;
        cout << (t.search(word) ? "true\n" : "false\n");


    return 0;


1
hello 
meaning1. 
1
hello1
meaning2.
1
hello2 
meaning.



}*/