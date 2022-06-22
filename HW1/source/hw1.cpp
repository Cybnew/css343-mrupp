
#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

void uiHelper(int i){
  map<int, string> shuffleOutputText {{ 1, "first"}, { 2, "second" }, { 3, "third" }, { 4, "fourth" }, { 5, "fifth" }, { 6, "sixth" }, { 7, "seventh" }, { 8, "eighth" }, { 9, "ninth" }, { 10, "tenth" }};
cout << "The " << shuffleOutputText[i] << " shuffled output is: " << endl;
}
int randomSeed(int i){
  return rand() % i;
}

void printShuffel(char arr[]){

  cout << "+-------+" << endl;
  printf("| %c %c %c |\n",arr[0],arr[1],arr[2]);
  printf("| %c %c %c |\n",arr[3],arr[4],arr[5]);
  printf("| %c %c %c |\n",arr[6],arr[7],arr[8]);
  cout << "+-------+" << endl;
}

void shuffelArray(char arr[]){
  randomSeed(unsigned(time(0)));
  random_shuffle(arr,arr+9,randomSeed);
  printShuffel(arr);
}

void getInput(char *arr){
  cout << "Please input 9 digits to be randomly shuffled:" << endl;
  cin >> arr;

}

int main(int argc, char* argv[]){

char* a = argv[1];

char userInput[10];
int sizeOfInput = sizeof(userInput) / sizeof(userInput[0]);
int numOut = atoi(a);

getInput(userInput);

for(int i = 0;i<numOut;i++){
  uiHelper(i+1);
  shuffelArray(userInput);
}

  return 0;
}
