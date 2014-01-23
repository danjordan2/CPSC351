//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 351
// Assignment: Project 1: Serial/Parallel Downloader
// File: parallel.cpp 
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
	int count = 0;
	queue<string> fileQueue;
	string url;
	fstream urlFile("urls.txt",ios::in);
	while(getline(urlFile, url))
	{
		fileQueue.push(url);
		count++; //Count number of urls in file
	}
	urlFile.close();

	//Loop till each url is consumed. 
	while(!fileQueue.empty())
	{
		//Fork() called N times
		pid = fork();

		if(pid ==-1)
		{
			cout << "Fork Failed\n";
			exit(-1);
		}
		else if(pid == 0)
		{
			execlp("/usr/bin/wget", "wget", fileQueue.front().c_str(), NULL);
		}
		else
		{
			cout << "\nDownload Starting\n";
			fileQueue.pop(); //Pop URL queue after download begins
		}
	}	
	//Wait() called N times, implementing parallel process execution
	for(int i=0; i<count; i++)
	{
		wait(NULL);
			cout << "\nDownload Complete\n"
				 << "\n----------------------------------------"
				 << "----------------------------------------\n";
	}
	return 0;
}
