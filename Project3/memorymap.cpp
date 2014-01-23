//=====================================================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 351
// Assignment: Project 3 Part 2: File copier using memory mapped files
// File: memorymap.cpp
//=====================================================================
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
	struct stat sourceInfo;
	struct stat destinationInfo;

	//Holds system's page size
	int pagesize;
	//Size of data being written on each pass
	int blockSize = 0;
	//File offset position
	int offset = 0;
	//Track percentage of data copied
	int percentComplete=0;
	if(argc < 3)
	{
		cout << "\nIncorrect number of parameters\n"
			 << "Correct Usage: " << argv[0] << " <SOURCE FILE> <DESTINATION FILE>\n\n";
		exit(-1);
	}
	//Grab paramaters for input/output files
    const  char * source = argv[1];
    const  char * destination = argv[2]; 


	cout << "Source File: " << source << endl;
	cout << "Destination File: " << destination << endl;

    //Get source file size
	stat(source, &sourceInfo);

	//Open output file
	FILE* outputFile = fopen(destination, "w+");
	if(!outputFile)
	{
		cout << "Error opening destination file\n";
		exit(-1);
	}

	cout << "Source File Size: " << sourceInfo.st_size << " bytes\n";

	//Set destination file pointer to match size of input file 
	fseek(outputFile, sourceInfo.st_size - 1, SEEK_SET);

	// Write 1 byte to output file to match input file size
	fwrite("", 1,  sizeof(""), outputFile);

	//Close destination file
	fclose(outputFile);

	//Get size of destination file after writing to it
	stat(destination, &destinationInfo);
	
	cout << "Updated Destination File Size: " << sourceInfo.st_size << " bytes\n";
	
	//Open source file for mapping
	int sourceFile = open(source, O_RDONLY);	
	
	//Open destination file with updated size
	int destinationFile = open(destination, O_RDWR);	
	
	//Make sure files opened
	if(!sourceFile)
	{
		cout << "Error opening source file\n";
		exit(-1);
	}
	if(!destinationFile)
	{
		cout << "Error opening destination file\n";
		exit(-1);
	}
	
	//Get the system's page size
	pagesize = getpagesize();
	cout << "Pagesize: " << pagesize << " bytes\n";
	
	//Repeat until end of source file is reached
	while(offset < sourceInfo.st_size)
	{
		//If data to be written is larger than pagesize
		if((sourceInfo.st_size-offset) > pagesize)
			//Write to file in pagefile sized chunks 
			blockSize = pagesize;
		else
			//Write the rest of the file
			blockSize = (sourceInfo.st_size-offset);

		//Map source file
		char * sourceBuffer =  (char*)mmap(NULL, blockSize, PROT_READ, MAP_SHARED, sourceFile, offset);
		//Map destination file with write permission
		char * destinationBuffer =  (char*)mmap(NULL, blockSize, PROT_READ|PROT_WRITE, MAP_SHARED, destinationFile, offset);

		//Copy chunk of source data into destination file 
		memcpy(destinationBuffer, sourceBuffer, blockSize);

		//Unmap the buffers for next run
		munmap(sourceBuffer, blockSize);
		munmap(destinationBuffer, blockSize);

		//Advance offset to account for data just copied
		offset += blockSize;

		//Update total percentage copied
		percentComplete = ((double)offset/sourceInfo.st_size)*100;
		cout << percentComplete << " complete\n";
	}
	cout << "Total data copied: " << offset << " bytes\n";
	//Verify amount copied matches size of source file
	if(offset == sourceInfo.st_size)
		cout << "\n./" << source << " successfully copied to ./" << destination << endl << endl;
	else
		cout << "Copy only completed " << percentComplete << "\%\n"; 

	//Close both files after copy is completed
	close(sourceFile);
	close(destinationFile);
	return 0;
}
