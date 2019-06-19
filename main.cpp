#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

#include <set>
using namespace std;
void RecPermute(string soFar, string rest);
void ListPermutations(string s);
void ShowWords();
set<string> uniqueSET;

int main()
{
    string word;
    cout << "your word is: ";
    cin >> word;

    ListPermutations(word);
    for(set<string > ::iterator it = uniqueSET.begin() ; it!=uniqueSET.end() ; ++it)cout<<*it<<endl;

//    for(string it : mset)cout<<it<<endl;
//    ShowWords();

}
void RecPermute(string soFar, string rest)
{
    if (rest == "")
    {
        uniqueSET.insert(soFar);
//        cout<<soFar<<endl;
//        string word;
//        ifstream infile;
//        infile.open("Check.txt");
////        infile >> word;
////        cout<<word<<endl;
//        while (infile.good()&& soFar!=word){
//            infile >> word;
//            cout<<"inside while "<<word<<endl;
//            if (infile.eof())
//            {
//                ofstream outfile;
//                outfile.open("Check.txt",ios::app);
//                outfile<<soFar;
//                outfile.close();
//                break;
//            }
//        }
//        infile.close();
    }
    else{
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i];
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
            }
    }
}

void ListPermutations(string s) {
RecPermute("", s);
}

void ShowWords()
{
    ifstream infile;
    infile.open("Check.txt");
    string word;
    do{
        infile >> word;
        cout << word << endl;
    }while (infile.good());
}
