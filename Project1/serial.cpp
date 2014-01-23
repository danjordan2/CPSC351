//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 351
// Assignment: Project 1: Serial/Parallel Downloader
// File: serial.cpp 
//=========================================
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int main()
{
	pid_t pid;
	queue<string> fileQueue;
	string url;
	fstream urlFile("urls.txt",ios::in);
	while(getline(urlFile, url))
		fileQueue.push(url);
	urlFile.close();
	
	//Loop till each url is consumed. 
	while(!fileQueue.empty())
	{
		/* Fork and Wait are called once in each iteration
		to implement serial process execution */
		pid = fork();
		if(pid<0)
		{
			cout << "Fork Failed\n";
			exit(-1);
		}
		else if(pid == 0)
		{
			cout << "\nProcess ID: " << getpid() << endl;
			execlp("/usr/bin/wget", "wget", fileQueue.front().c_str(), NULL);
		}
		else
		{
			cout << "\nDownload Starting\n";
			fileQueue.pop(); //Pop URL queue after each download completes
			wait(NULL);
			cout << "\nDownload Complete\n"
				 << "\n----------------------------------------"
				 << "----------------------------------------\n";
		}
	}
	return 0;
}
