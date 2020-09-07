#include<bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
using namespace std;
class Node{
	public:
	Node *children[128];
	int count;

	Node(){
		for(int i = 0;i<128;i++){
			children[i] = NULL;
		}
		count = 0;
	}
};

Node *root = new Node();

void insert(string word, int cnt){
	transform(all(word), word.begin(), ::tolower);
	Node *node = root;
	for(auto c:word){
		int p = c;
		if(node->children[p]==NULL){
			node->children[p] = new Node();
		}
		node = node->children[p];
		
	}
	node->count = cnt;
}

int search(string word){
	Node *node = root;
	for(auto c:word){
		int p = c;
		if(node->children[p]==NULL){
			return 0;
		}
		node = node->children[p];
	}
	return node->count;
}

void create(string t){
	string word = "";
	int count = 0;
	int n = t.length();
	for(int i = 0;i<n;i++){
		if(t[i]==','){
			t[i] = ' ';
		}
	}
	stringstream s(t);
	s>>word;
	s>>count;
	insert(word, count);
}



int main(){
	fstream fin;
	fin.open("EnglishDictionary.csv",ios::in);
	if(fin){
		string line;
		while(getline(fin, line)){
		
			create(line);
   		}
	}
	else{
		cout << "Unable to Open the file.\n";
	}
	string word;
	cin >> word;
	transform(all(word), word.begin(), ::tolower);
	int k = search(word);
	if(k){
		cout << "YES, " << k << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}