#include<iostream>
#include<map>
#include<string.h>
#include<fstream>
#include<omp.h>
#include<time.h>

using namespace std;

struct TrieNode
{
	map<char,TrieNode*> children;
	int occurance;
	bool endofword;

	TrieNode()
	{
		occurance=0;
		endofword=false;
	}
};
void insert(TrieNode *root,string word)
{
	TrieNode *current=root; 

	for(int i=0;i<word.size();i++)
	{
		char ch=word[i];
		TrieNode *node=current->children[ch];
		if(!node)
		{
			node=new TrieNode();
			current->children[word[i]]=node;
		}
		current=node; // like temp = temp -> next 	starting current will be at root then at next character
	}
	current->endofword=true;
	current->occurance++;
}

void printWords(TrieNode* crnt,string word)
{
    if(crnt->endofword==true)
    {
        cout<<word<<" occurs "<<crnt->occurance<<" times."<<endl;
    }
    map<char,TrieNode*>::iterator it;
    it=crnt->children.begin();
    while(it!=crnt->children.end())
    {
        word += it->first;
        printWords(it->second,word);
        word.erase(word.length()-1);  //erase last prefix character
        it++;
    }
}
void insertion(TrieNode* root,char* filename)
{
	FILE *ptr_readfile;
	
	string word; /* or some other suitable maximum line size */
	
	ifstream infile;
    infile.open(filename);
	while (infile >> word) 
    { 
        insert(root,word); 
    } 
	infile.close();	
}

int main()
{

    
	TrieNode *root=new TrieNode();
	char* file_names[5]={"file_part1","file_part2","file_part3","file_part4","file_part5"};//"file_part6","file_part7","file_part8","file_part9","file_part10"};
	clock_t t; 
    t = clock();
	#pragma omp parallel num_threads(5) shared(root)
	{
		#pragma omp sections
		{
			#pragma omp section
				insertion(root,file_names[0]);
			#pragma omp section
				insertion(root,file_names[1]);
			#pragma omp section
				insertion(root,file_names[2]);
			#pragma omp section
				insertion(root,file_names[3]);
			#pragma omp section
				insertion(root,file_names[4]);					
		}
	}
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	cout<<endl<<"Elapsed time = "<<time_taken<<" seconds"<<endl<<endl;
	//cout<<"HELLO:"<<endl;
	cout<<"\n PRINTING TRIE"<<endl;
	printWords(root , "");
	return 0;
}
