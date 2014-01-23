Name: Daniel Jordan
Titan username: cs351g13
Email: daniel_jordan@csu.fullerton.edu
Language: C++
Files: serial.cpp, parallel.cpp

Instructions: Populate urls.txt file with download links. Execute from terminal with ./serial and ./parallel. No error checks are conducted on input file. It is assumed that the file exists, and holds the URLs for download. 

Execution time for downloading two ~700mb Ubuntu images:
Parallel - 46m23.209s
Serial   - 93m58.698s

////////////////////////////////////////////////////////////
Parallel Output
////////////////////////////////////////////////////////////

dan@laptop:~/school/CPSC351/assignment1$ time ./parallel

Download Starting

Download Starting

Download Starting

Download Starting

Download Starting

Download Starting
--2012-09-21 14:47:04--  http://173.255.130.85/school/CPSC351/assignment1/file1.txt
--2012-09-21 14:47:04--  http://173.255.130.85/school/CPSC351/assignment1/file2.txt
Connecting to 173.255.130.85:80... --2012-09-21 14:47:04--  http://173.255.130.85/school/CPSC351/assignment1/file5.txt
Connecting to 173.255.130.85:80... Connecting to 173.255.130.85:80... --2012-09-21 14:47:04--  http://173.255.130.85/school/CPSC351/assignment1/file4.txt
--2012-09-21 14:47:04--  http://173.255.130.85/school/CPSC351/assignment1/file6.txt
--2012-09-21 14:47:04--  http://173.255.130.85/school/CPSC351/assignment1/file3.txt
Connecting to 173.255.130.85:80... Connecting to 173.255.130.85:80... Connecting to 173.255.130.85:80... connected.
HTTP request sent, awaiting response... connected.
HTTP request sent, awaiting response... connected.
HTTP request sent, awaiting response... connected.
HTTP request sent, awaiting response... connected.
HTTP request sent, awaiting response... connected.
HTTP request sent, awaiting response... 200 OK
Length: 7 [text/plain]
Saving to: `file2.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:47:04 (467 KB/s) - `file2.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------
200 OK
Length: 7 [text/plain]
Saving to: `file1.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:47:04 (473 KB/s) - `file1.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------
200 OK
Length: 7 [text/plain]
200 OK
Length: 7 [text/plain]
Saving to: `file6.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:47:04 (403 KB/s) - `file6.txt' saved [7/7]


Download Complete
Saving to: `file5.txt'

-----------------------------------------------------------------------------------------------------------

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:47:04 (337 KB/s) - `file5.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------
200 OK
Length: 7 [text/plain]
Saving to: `file3.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:47:04 (411 KB/s) - `file3.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------
200 OK
Length: 7 [text/plain]
Saving to: `file4.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:47:04 (526 KB/s) - `file4.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------

real	0m0.154s
user	0m0.012s
sys	0m0.016s


////////////////////////////////////////////////////////////
Serial Output
////////////////////////////////////////////////////////////

dan@laptop:~/school/CPSC351/assignment1$ time ./serial

Download Starting

Process ID: 7159

--2012-09-21 14:40:13--  http://173.255.130.85/school/CPSC351/assignment1/file1.txt
Connecting to 173.255.130.85:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 7 [text/plain]
Saving to: `file1.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:40:13 (365 KB/s) - `file1.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------

Download Starting

Process ID: 7160

--2012-09-21 14:40:13--  http://173.255.130.85/school/CPSC351/assignment1/file2.txt
Connecting to 173.255.130.85:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 7 [text/plain]
Saving to: `file2.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:40:13 (506 KB/s) - `file2.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------

Download Starting

Process ID: 7161

--2012-09-21 14:40:13--  http://173.255.130.85/school/CPSC351/assignment1/file3.txt
Connecting to 173.255.130.85:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 7 [text/plain]
Saving to: `file3.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:40:13 (384 KB/s) - `file3.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------

Download Starting

Process ID: 7162

--2012-09-21 14:40:13--  http://173.255.130.85/school/CPSC351/assignment1/file4.txt
Connecting to 173.255.130.85:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 7 [text/plain]
Saving to: `file4.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:40:14 (338 KB/s) - `file4.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------

Download Starting

Process ID: 7163

--2012-09-21 14:40:14--  http://173.255.130.85/school/CPSC351/assignment1/file5.txt
Connecting to 173.255.130.85:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 7 [text/plain]
Saving to: `file5.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:40:14 (478 KB/s) - `file5.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------

Download Starting

Process ID: 7164

--2012-09-21 14:40:14--  http://173.255.130.85/school/CPSC351/assignment1/file6.txt
Connecting to 173.255.130.85:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 7 [text/plain]
Saving to: `file6.txt'

100%[====================================================================================================>] 7           --.-K/s   in 0s      

2012-09-21 14:40:14 (422 KB/s) - `file6.txt' saved [7/7]


Download Complete

-----------------------------------------------------------------------------------------------------------

real	0m0.699s
user	0m0.004s
sys	0m0.024s



