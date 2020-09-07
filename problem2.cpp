#include<bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
using namespace std;

class Node{
	public:
	Node *children[128];
	set<int>s;

	Node(){
		for(int i = 0;i<128;i++){
			children[i] = NULL;
		}
	}
};

Node *root = new Node();
int f = 1;

void insert(string word, int n){
	Node *node = root;
	for(auto c:word){
		int p = c;
		if(node->children[p]==NULL){
			node->children[p] = new Node();
		}
		
		node = node->children[p];
		node->s.insert(n);
		
	}
}

string search(int n){
	Node *node = root;
	string s = "";
	for(int i = 0;i<128;i++){
		if(node->children[i] && node->children[i]->s.count(n)){
			char p = i;
			s+=p;
			node = node->children[i];
			i=-1;
		}
		
	}
	return s;
}


void create(string t){
	string word = "";
	int count = 0;
	int n = t.length();
	int commaspace;
	for(int i = 0;i<n;i++){
		if(t[i]==','){
			t[i] = ' ';
		}
	}
	stringstream s(t);
	s>>word;
	s>>count;
	insert(word, f++);
}



int main(){
	fstream fin;
	fin.open("EnglishDictionary.csv",ios::in);
	if(fin){
		vector<string>row;
		string word;
		int count;
		string line,temp;
		
		while(getline(fin, line))
		{
		
			create(line);
   		}
	}
	else{
		cout << "Unable to Open the file.\n";
	}

	int w;
	cin >> w;
	cout << w << endl;
	string k = search(w);
	if(k!=""){
		cout << "YES, " << k << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}