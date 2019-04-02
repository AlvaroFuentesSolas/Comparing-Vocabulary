#include <fstream>
#include <iostream>
#include <string>
#include <ctime> 

using namespace std;

string ProveTheWord(string &word);
bool OpenTheFiles(ifstream &file1, ifstream &file2);
void NoRepeatWordList(ifstream &file2);

string listWordsFile[50000];
int wordCount = 0;

bool OpenTheFiles(ifstream &file1, ifstream &file2, string text1, string text2){

	bool open = false;
	file1.open(text1);
	file2.open(text2);
	if (file1.is_open() && file2.is_open()){
		open = true;
	}
	return open;
}

//THIS FUNCTION RETURNS THE WORD WITHOUT ANY EXTRANGE CHARACTER OR A EMPTY STRING IF THE WORD IN THE FILE IS FULL OF EXTRANGE CHARACTERES
string ProveTheWord(string &word){

	int sizeNewWord = 0;
	int size = word.size();
	char * fileWord = new char[size];
	fileWord[size] = 0;
	for (int i = 0; i < word.size(); i++){
		fileWord[i] = word[i];
	}
	char * NewWord = new char[70];
	int z = 0; // FILEWORD COUNT
	int a = 0; // NEWWORD COUNT
	int y = 0;
	while (z < word.size()){
		switch (fileWord[y])
		{
		case '(':
			z++;
			break;
		case 39:
			if (y == 0 || y == word.size() - 1){
				z++;
			}
			break;
		case ':':
			z++;
			break;
		case ';':
			z++;
			break;
		case '?':
			z++;
			break;
		case '-':
			z++;
			break;
		case '!':
			z++;
			break;
		case ')':
			z++;
			break;
		case '_':
			z++;
			break;
		case '"':
			z++;
			break;
		case '/':
			z++;
			break;
		case '*':
			z++;
			break;
		case '.':
			z++;
			break;
		case ',':
			z++;
			break;
		case '[':
			z++;
			break;
		case ']':
			z++;
			break;
		case '#':
			z++;
			break;
		case '0':
			z++;
			break;
		case '1':
			z++;
			break;
		case '2':
			z++;
			break;
		case '3':
			z++;
			break;
		case '4':
			z++;
			break;
		case '5':
			z++;
			break;
		case '6':
			z++;
			break;
		case '7':
			z++;
			break;
		case '8':
			z++;
			break;
		case '9':
			z++;
			break;

		default:
			NewWord[a] = toupper(fileWord[z]); // IF THERE IS NOT A EXTRANGE CARACTER, IT COPYS THE LETTER IN THE NEW CHAR ARRAY.
			z++;
			a++;
			break;
		}
		y++;
	}
	NewWord[a] = 0;
	string NewWordString(NewWord);
	return NewWordString;
}

//THIS FUNCTION RETURN A LIST OF THE SECOND FILE WITH ALL THE WORDS INSIDE
void NoRepeatWordList(ifstream &file2){

	string aux;
	string aux1;
	string NewWord1;

	while (file2.eof() == false){
		
		file2 >> aux;
		
		int a = 0;
		int b = 0;
		char * NewWord = new char;
		while (a < aux.size()){
			bool exit = false;
			if (aux[a] != *"-" && aux[a] != *"." && aux[a] != *"/"){
				NewWord[b] = aux[a];
				b++;
			}
			else{
				NewWord[b] = 0;
				string NewWord1(NewWord);
				NewWord1 = ProveTheWord(NewWord1);
				int i = 0;
				if (NewWord1 == ""){
					exit = true;
				}
				while ((i < wordCount) && (exit == false)){
					if (NewWord1 == listWordsFile[i]){
						exit = true;
					}
					i++;
				}
				if (exit == false){
					listWordsFile[wordCount] = NewWord1;
					wordCount++;
				}
				b = 0;
			}
			
			if (a + 1 == aux.size()){
				exit = false;
				NewWord[b] = 0;
				string NewWordA(NewWord);
				NewWordA = ProveTheWord(NewWordA);
				int i = 0;
				if (NewWordA == ""){
					exit = true;
				}
				while ((i < wordCount) && (exit == false)){
					if (NewWordA == listWordsFile[i]){
						exit = true;
					}
					i++;
				}
				if (exit == false){
					listWordsFile[wordCount] = NewWordA;
					wordCount++;
				}
			}
			a++;
		}
	}

}

//THIS FUNCTION RETURN IF THE FILES CAN BE OPENED.
bool ProveTheFile(string file){ //THIS FUNCTION FINDS IF THE INPUT WHIT THE FILE NAME WROTE BY THE USER IS CORRECT, IF NOT THE USER HAS TO WRITE AGAIN THE NAME
	
	bool rightFile = false;
	if (file != "MetaMorph.txt" && file != "Species.txt" && file != "TheGun.txt" && file != "Ulysses.txt" && file != "WarPeace.txt" && file != "MetaMorph.txt"){
		cout << "You have wroten uncorrectly the file, try again.\n";
	}
	else{
		rightFile = true;
	}
	return rightFile; 
}
	
int main(){
	
	unsigned ProgramBeginning, ProgramEnding;
	unsigned ListBeginning, ListEnding;
	

	ifstream file1, file2;
	string WordFirstFile, list[50], text1, text2;

	cout << "Write the two files of this list that you would like to compare. \n" <<
		"1. MetaMorph.txt\n" << "2. Species.txt\n" << "3. TheGun.txt\n" << "4. Ulysses.txt\n" << "5. WarPeace.txt\n";

	bool exit = false;
	
	while (exit == false){ //THIS LOOP IS REPEATED AS TIMES AS THE USER FAILS IN THE FILE NAME
		cout << "Text where you want to find the 50 first different words: "; cin >> text1;
		exit = ProveTheFile(text1);
	}
	exit = false;
	while (exit == false){
		cout << "Text with you want to compare: "; cin >> text2;
		exit = ProveTheFile(text2);
	}

	if (OpenTheFiles(file1, file2, text1, text2) == true){ //WE PROVE IF THERE ARE SOME PROBLEMS OPENING THE FILES

		ProgramBeginning = clock();

		file2.clear();
		file2.seekg(0, file2.beg);

		NoRepeatWordList(file2);
				
		int x = 0;
		bool out = false;
		while (x < 50){ //WE OPEN A LOOP WHICH IS CLOSED IF THE 50 FIRST DIFFERENT WORDS ARE FOUND
			ListBeginning = clock();
			int pos = 0;
			bool out = false;
			file1 >> WordFirstFile; // WE GET THE WORD OF OUR FIRST FILE
			bool a = true;
			char * correctWord = new char;
			if (WordFirstFile[WordFirstFile.size() - 1] == *"." || WordFirstFile[WordFirstFile.size() - 1] == *"-" && WordFirstFile[WordFirstFile.size() - 1] == *"/"){
				a = false;
			}
			for (int i = 0; i < WordFirstFile.size(); i++){
				if (WordFirstFile[i] != *"-" && WordFirstFile[i] != *"." && WordFirstFile[i] != *"/"){ //IF THERE ARE NOT THESE CHARACTERS WE COPY THE LETTER
					correctWord[pos] = WordFirstFile[i];
					pos++;
				}
				else{ //IF THE CHARACTERS ARE IN THE WORD IT FINISH THIS WORD AND COMPARE THE NEW WORD WITH THE WORDS IN THE LIST
					correctWord[pos] = 0; 
					string NewWord1(correctWord);
					NewWord1 = ProveTheWord(NewWord1);
					int b = 0;
					if (NewWord1 == ""){
						out = true;
					}
					while ((b < wordCount) && (out == false)){
						if (NewWord1 == listWordsFile[b]){
							out = true;
						}
						b++;
					}
					if (x == 0 && out == false){
						out = true;
						list[x] = NewWord1;
						cout << x + 1 << ". " << list[x] << "\n";
						x++;
					}
					int w = 0;
					while (w < x && out == false){
						if (NewWord1 == list[w] && out == false){ 
							out = true;
						}
						w++;
					}										
					if (out == false){
						list[x] = NewWord1;
						cout << x + 1 << ". " << list[x] << "\n";
						x++;
					}
					pos = 0;
					out = false;
				}
				if (i + 1 == WordFirstFile.size() && a == true){ 
					exit = false;
					correctWord[pos] = 0;
					string NewWordA(correctWord);
					NewWordA = ProveTheWord(NewWordA);
					int i = 0;
					if (NewWordA == ""){
						exit = true;
					}
					while ((i < wordCount) && (exit == false)){
						if (NewWordA == listWordsFile[i]){
							exit = true;
						}
						i++;
					}
					if (x == 0 && exit == false){
						exit = true;
						list[x] = NewWordA;
						cout << x + 1 << ". " << list[x] << "\n";
						x++;
					}
					int w = 0;
					while (w < x && exit == false){
						if (NewWordA == list[w] && out == false){
							exit = true;
						}
						w++;
					}
					if (exit == false){
						list[x] = NewWordA;
						cout << x + 1 << ". " << list[x] << "\n";
						x++;
					}
				}
				
			}	

		}
		ListEnding = clock();
		double time = (double(ListEnding - ListBeginning) / CLOCKS_PER_SEC);
		cout << "Execution second word: " << time << endl;

	}
	else{
		cout << "There is a problem with the files we will use";
	}
	file1.close();
	file2.close();

	ProgramEnding = clock();
	double time1 = (double(ProgramEnding - ProgramBeginning) / CLOCKS_PER_SEC);
	cout << "Execution Time: " << time1 << endl;

	system("pause");
	return 0;
}