#include "HTMLTable.h"
#include "tinyxml2.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using namespace tinyxml2;

int main() {
  cout << "Parsing cd catalog...\n";
  XMLDocument doc;
  doc.LoadFile("cd_catalog.xml");
  // Get root Element
  XMLElement *pRootElement = doc.RootElement();
  // Print out the Table Header
  // Definition for table column headers
  vector<string> headers{"Title",   "Artist", "Country",
                         "Company", "Price",  "Year"};
  // Create the HTML table object and set its members
  HTMLTable hTable;
  hTable.setHeaders(headers);
  if (NULL != pRootElement) {
    // Get 'CD' Child
    XMLElement *cd = pRootElement->FirstChildElement("CD");
    while (cd) {
      // cdCat represents a row to be added to the table
      vector<string> cdCat;
      // Get 'Title' Child
      XMLElement *title = cd->FirstChildElement("TITLE");
      if (NULL != title) {
        cdCat.push_back(title->GetText()); // Add value of title to cdCat
      }
      // Get 'ARTIST' Child
      XMLElement *artist = cd->FirstChildElement("ARTIST");
      if (NULL != artist) {
        cdCat.push_back(artist->GetText()); // Add value of artist to cdCat
      }
      // Get 'COUNTRY' Child
      XMLElement *country = cd->FirstChildElement("COUNTRY");
      if (NULL != country) {
        cdCat.push_back(country->GetText()); // Add value of country to cdCat
      }
      // Get 'COMPANY' Child
      XMLElement *company = cd->FirstChildElement("COMPANY");
      if (NULL != company) {
        cdCat.push_back(company->GetText()); // Add value of company to cdCat
      }
      // Get 'PRICE' Child
      XMLElement *price = cd->FirstChildElement("PRICE");
      if (NULL != price) {
        cdCat.push_back(price->GetText()); // Add value of price to cdCat
      }
      // Get 'YEAR' Child
      XMLElement *year = cd->FirstChildElement("YEAR");
      if (NULL != year) {
        cdCat.push_back(year->GetText()); // Add value of year to cdCat
      }
      hTable.addRow(cdCat); // Add the row to table
      // Next Entry of CD
      cd = cd->NextSiblingElement("CD");
    }
  }
  // Open a file and write the HTML code to the file
  ofstream outFile("cd_catalog.html");
  if (outFile) {
    outFile << hTable;
    outFile.close();
    cout<<"Output file is created: cd_catalog.html"<<endl;
  // cout<<hTable;  // Print the HTML table to console
  }  else cout<<"Writing to file failed"<<endl;
  return 0;
}