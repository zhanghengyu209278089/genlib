#ifndef GENLIB_H
#define GENLIB_H
#include <bits/stdc++.h>
using namespace std;
struct testpoint{
	string inputFile;//inputfile
	int timeLimit;//ms
	int memoryLimit;//kb
    int score;
	int subtaskId;//subtask
	testpoint(string _inputFile,int _timeLimit,int _memoryLimit,int _score,int _subtaskId):inputFile(_inputFile),timeLimit(_timeLimit),memoryLimit(_memoryLimit),score(_score),subtaskId(_subtaskId){}
	string to_string(){
		return inputFile+":\n  timeLimit: "+std::to_string(timeLimit)+"\n  memoryLimit: "+std::to_string(memoryLimit)+"\n  score: "+std::to_string(score)+"\n  subtaskId: "+std::to_string(subtaskId)+"\n";
	}
	void help(){
		printf("Help on class testpoint in module builtins:\n");
		printf("class testpoint(object)\n");
		printf(" |	testpoint(_inputFile,_timeLimit,_memoryLimit,_score,_subtaskId) -> testpoint\n");
		printf(" |	\n");
		printf(" |	A class for test points in a configuration.\n");
		printf(" |	\n");
		printf(" |	Methods defined here:\n");
		printf(" |	\n");
		printf(" |	to_string() -> string\n");
		printf(" |		Covert itself to a yaml config file.\n");
		return;
	}
};
struct config{
	vector<testpoint> pts;
	config(initializer_list<testpoint> lst={}){
		pts=vector<testpoint>(lst);
	}
	config& append(testpoint src){
		pts.push_back(src);
		return *this;
	}
	string to_string(){
		string str;
		for (testpoint tsp : pts)
		str+=tsp.to_string();
		return str;
	}
	void write(){
		ofstream fout("config.yml");
		fout<<to_string();
		fout.close();
		return;
	}
	void help(){
		printf("Help on class config in module builtins:\n");
		printf("class config(object)\n");
		printf(" |	config(initializer_list<testpoint>) -> config\n");
		printf(" |	\n");
		printf(" |	A class for configuration in a problem\n");
		printf(" |	\n");
		printf(" |	Methods defined here:\n");
		printf(" |	\n");
		printf(" |	append(src) -> config&\n");
		printf(" |		Append testpoint src to the back of the testpoints in this configuration.\n");
		printf(" |	\n");
		printf(" |	to_string() -> string\n");
		printf(" |		Covert itself to a string.\n");
		printf(" |	\n");
		printf(" |	write()\n");
		printf(" |		Write itself to config.yml.\n");
		return;
	}
};
struct problem{
	config cfg;
	problem(config _cfg):cfg(_cfg){}
	template<typename T>
	void generate(T g){
		cfg.write();
		for (testpoint t : cfg.pts){
			string inputFile=t.inputFile;
			string outputFile=inputFile.substr(0,inputFile.find(".in"))+".out";
			ofstream inF(inputFile.c_str());
			ofstream ouF(outputFile.c_str());
			g(inF,ouF,t.subtaskId);
			inF.close();
			ouF.close();
		}
	}
	void help(){
		printf("Help on class problem in module builtins:\n");
		printf("class problem(object)\n");
		printf(" |	problem(config) -> problem\n");
		printf(" |	\n");
		printf(" |	A class for problem.\n");
		printf(" |	\n");
		printf(" |	Methods defined here:\n");
		printf(" |	\n");
		printf(" |	generate(g(ofstream&,ofstream&,int)->void)\n");
		printf(" |		Generate all test data with generator g.\n");
		return;
	}
};
long long randint(long long l,long long r){
	return 1ll*rand()*rand()*rand()%(r-l+1)+l;
}
#endif
