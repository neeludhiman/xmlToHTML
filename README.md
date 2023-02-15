# xmlToHTML
Converts XML file to HTML table

Input is an XML file "cd_catalog.xml" which is included as part of the project.

Output is an HTML file with table element

This project uses tinyxml2 for parsing the xml file. tinyxml2 is chosen as an XML parser, since it is minimal, easier to install and use and it uses few memory allocations as compared to other popular xml parsers like PugiXML, RapidXML. Here performance and speed are not significant issues. 

For creating HTML table, a class is used which writes the generic table header (vector of strings) and the table rows (vector of vector of strings). This class can be reused to write any 2D table in HTML format.

Description of the source files:

HTMLTable.cpp - HTML table methods definition and implementation
HTMLTable.h - HTML Table class declaration
tinyxml2.h - XML parser class and methods declaration
tinyxml2.cpp - XML parser methods implementation
main.cpp - Driver code which reads the XML file, parses it and writes it to HTML file as output.
makefile - Makefile to build project.
cd_catalog.xml - Input file for main

Build platform: This project can be built on Linux/Windows platform.
Compiler: g++ (GCC) 11.3.0

Instructions to build:
make -f makefile 
Above command creates an executable binary named as "xmlHtml"

Clean build:
make clean
Above command removes the intermediate files, executable binary and output file.

Run the binary:
./xmlHtml
Above command creates an output file "cd_catalog.html" in the current directory.

References:

https://github.com/leethomason/tinyxml2

https://stackoverflow.com/questions/9387610/what-xml-parser-should-i-use-in-c

https://linuxhint.com/parse_xml_in_cpp/

https://www.codingpanel.com/a-complete-guide-to-tinyxml-using-cpp/

https://cplusplus.com/forum/general/276345/

The code was built on Replit and is hosted on below link:
https://replit.com/@NeeluDhiman/xmlHtml
