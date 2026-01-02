#include<iostream>
#include<fstream>
using namespace std;

class temp{
   int i;

    string id,name,author,search;
    fstream file;
    public:
    void addBook();
    void showAll();
    void extractBook();

}obj;


int main(){

    char choice;
    cout<<"--------------------------"<<endl;

    cout<<"1-Show All Books"<<endl;
    cout<<"2-Extract Book"<<endl;
    cout<<"3-Add books(ADMIN)"<<endl;

    cout<<"4-Exit"<<endl;
    cout<<"---------------------------"<<endl;
    
    cout<<"Enter Your Choice :: ";
    cin>>choice;

    switch(choice){
        case '1' :
        cin.ignore(); //getline func use kiya hai toh koi aur cin na aa jaye //
        obj.showAll();

        break;

        case '2' :
        cin.ignore();
        obj.extractBook();

        break;
         case '3' :
         cin.ignore();
         obj.addBook();

        break;

         case '4' :
        return 0;


        break; 
        default:
        cout<<"Invalid Choice ... choose from given options ";
  
  
    }
    return 0;

}

void temp :: addBook(){
    cout<<"\nEnter Book ID ::";
    getline(cin,name);
    cout<<"Enter Book Name ::";
    getline(cin,name);
    cout<<"Enter Book's Author Name ::";
    getline(cin,author);

    file.open("bookData.txt",ios :: out |ios :: app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();

}

void temp :: showAll(){
    file.open("bookData.txt",ios :: in );
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

      cout<<"\n\n";
      cout<<"\t\t Book Id \t\t\t Author's Name"<<endl;


    while(!file.eof()){
        cout<<"\t\t"<<id<<" \t\t\t"<<name<<"\t\t\t"<<author<<endl;
      getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    }
    file.close();

}
void temp :: extractBook(){

    showAll();
    cout<<"Enter Book Id ::";
    getline(cin,search);
    
    
    
    file.open("bookData.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

    cout<<"\n\n";
    cout<<"\t\t Book Id \t\t\t Author's Name"<<endl;
    while(!file.eof()){

        if(search == id){

            cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
            cout<<"Book Extracted Successfully....";

        }
 getline(file,id,'*');
 getline(file,name,'*');
 getline(file,author,'\n');

        


    }
    file.close();
     cout<<" Enter any key to exit";
    cin>>i;

}
