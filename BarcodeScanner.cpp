#include<iostream>
#include"BST.h"
#include<time.h>
#include<fstream>
#include<string>
#include<sstream>
#include"UPC.h"
#include"arraySearch.h"

 using namespace std;

void readIntoBST(BST<UPC>&);
int readIntoArray(UPC*&);

int main(){
string code;
BST<UPC> bst;//creating bst
readIntoBST(bst);//reading file into bst
UPC* array=new UPC[1050000];//creating array
int size=readIntoArray(array);//reading file into array and returning the size
cout<<"UPC Code: ";
cin>>code;
UPC except("-1","Not Found");
UPC entry(code);
clock_t t;
t=clock();
cout<<bst.search(entry,except)<<endl;
t=clock()-t;
cout<<"BST time: "<<t<<" milliseconds"<<endl;
clock_t t1;
t1=clock();
search(array,entry,size);
t1=clock()-t1;
cout<<"Array time: "<<t1<<" milliseconds"<<endl;

delete[] array;
return 0;
}
//reading from the file
//and creating UPC objects into 
//the BST
void readIntoBST(BST<UPC>& bst){
	ifstream ff;
 ff.open("upc_corpus.txt");
 string line;
 while(getline(ff,line)){
         istringstream ss(line);
	 string code,name;
         getline(ss,code,',');
         getline(ss,name);
         UPC upc(code,name);
	 bst.add(upc);
 }
}
//reading from the file
//and creating UPC objects into 
//the BST

int readIntoArray(UPC*& array){
int size=0;
 ifstream ff;
 ff.open("upc_corpus.txt");
 string line;
 while(getline(ff,line)){
         istringstream ss(line);
	 string code,name;
         getline(ss,code,',');
	 getline(ss,name);      
         UPC upc(code,name);
         array[size]=upc;
         size++;
 }
 return size;
}



