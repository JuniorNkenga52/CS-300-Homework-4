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
BST<UPC> bst;
readIntoBST(bst);
UPC* array=new UPC[3000000];
int size=readIntoArray(array);
cout<<"UPC Code: ";
cin>>code;
UPC except("-1","Not Found");
UPC entry(code);
clock_t t;
t=clock();
cout<<bst.search(entry,except)<<endl;
t=clock()-t;
cout<<"BST time: "<<t<<" milliseconds"<<endl;
t=clock();
search(array,entry,size);
t=clock()-t;
cout<<"Array time: "<<t<<" milliseconds"<<endl;

delete[] array;
return 0;
}
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



