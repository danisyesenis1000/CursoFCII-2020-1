#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

//AFTER TRIAL AND ERROR, USING THE REFFERENCE SYMBOL & WORKED.
//I DON'T FULLY UNDERSTAND WHY IT WAS NEEDED.

//Function prototypes
//open file to read; if boolean is true, file content is printed
void readFromFile(std::ifstream &, std::string, bool);

//open file to write
void writeToFile(std::ofstream &, std::string);

//close read file
void closeReadFile(std::ifstream &, std::string);

//close written file
void closeWrittenFile(std::ofstream &, std::string);

int main()
{
  
  /* PART a): WRITING STAGE */
  std::cout << "\nPART a): WRITING STAGE" << std::endl;
  
  std::ofstream writePayroll;
  std::string payrollFileName = "payroll.dat";
  
  //call function to open the file for writing
  writeToFile(writePayroll, payrollFileName);
  
  //objects to be written fo file
  std::vector<std::string> name{"B Caldwell", "D Memcheck", 
                                "R Potter", "W Rosen "};
  
  std::vector<std::string> socSecNum{"555-88-2222", "555-77-4444", 
                                     "555-77-6666", "555-99-8888"};
  
  std::vector<float> hourlyRate{7.32, 8.32, 6.54, 9.80};
  
  std::vector<unsigned short int> hoursWorked{37, 40, 40, 35};
  
  std::cout << "\nWriting information to '" << payrollFileName 
            <<"' ...\n";
            
  //show on screen and write to file: 
  //name, social sec. #, hourly rate, hours worked
  for (unsigned short int i = 0; i < name.size(); i++)
  {
  std::cout << name[i] << " \t"
            << socSecNum[i] << "\t" << std::fixed 
            << std::setprecision(2) << hourlyRate[i] << "\t"
            << hoursWorked[i] << std::endl;
  
    writePayroll << name[i] << "\t"
                 << socSecNum[i] << "\t" << std::fixed 
                 << std::setprecision(2) << hourlyRate[i] << "\t"
                 << hoursWorked[i] << std::endl;
  }
  
  //close file after writing the table into it
  closeWrittenFile(writePayroll, payrollFileName);
  
  std::cout << "\nPress enter to continue to part b): ";
  std::cin.get();
  
  
  /* PART b): READ DATA FROM FILE, PROCESS, AND WRITE ANOTHER FILE*/
  std::cout << "\nPART b): READ DATA FROM FILE, PROCESS, "
               "AND WRITE ANOTHER FILE" << std::endl;
               
  std::ifstream readPayroll;
  readFromFile(readPayroll, payrollFileName, false);
  
  //vectors in which information is to be stored: initialized to
  //the same size as that of vectors from part a).
  //Name of variables will be the same, with "Vec" added at the end.
  std::vector<std::string> nameVec( name.size() );
  std::vector<std::string> socSecNumVec( name.size() );
  std::vector<float> hourlyRateVec( name.size() );
  std::vector<unsigned short int> hoursWorkedVec( name.size() );
  
  //read from file and store the information on the vectors
  std::cout << "\nReading information from '" << payrollFileName
            << "' ...\n";
  unsigned short int i = 0; //counts the i-th line read
  std::string line; //stores the entire line read
  while ( std::getline(readPayroll, line) )
  {
    std::istringstream strStream(line); //put line into stringstream
    
    //I don't like to create a ton of variables, but this worked:
    //take each line and split into columns: name, surname, soc.sec.n,
    //hourly rate, and hours worked, and assign those to the vector.
    std::string lineName, lineSurname, lineSocSecNum;
    float lineHourlyRate;
    unsigned short int lineHoursWorked;
    
    //take the values from the string stream to the defined variables
    strStream >> lineName >> lineSurname >> lineSocSecNum 
              >> lineHourlyRate >> lineHoursWorked;
    
    //save to the corresponding vector
    nameVec[i] = lineName + " " + lineSurname; //name was splitted
    socSecNumVec[i] = lineSocSecNum;
    hourlyRateVec[i] = lineHourlyRate;
    hoursWorkedVec[i] = lineHoursWorked;
    
    //go to next vector component when this iteration ends
    i += 1;
  }
  
  //close file after reading the information from it
  closeReadFile(readPayroll, payrollFileName);
  
  //open another file to write the paysheet
  std::ofstream writepaysheet;
  std::string paysheetFileName = "paysheet.dat";
  
  //call function to open the file for writing
  writeToFile(writepaysheet, paysheetFileName);
  
  //objects to be written fo file
  std::vector<float> grossPay( nameVec.size() );
  
  //gross pay calculation
  for (unsigned int j = 0; j < grossPay.size(); j++)
  {
    grossPay[j] = hourlyRateVec[j] * hoursWorkedVec[j];
  }
  
  std::cout << "\nWriting information to '" 
            << paysheetFileName << "' ...\n";
            
  //show on screen and write to file: social sec. #, name, gross pay
  for (unsigned short int i = 0; i < name.size(); i++)
  {
   std::cout << socSecNumVec[i] << "\t"
             << nameVec[i] << " \t" << std::fixed 
             << std::setprecision(2) << grossPay[i] << std::endl;
  
    writepaysheet << socSecNumVec[i] << "\t"
                  << nameVec[i] << "\t" << std::fixed 
                  << std::setprecision(2) << grossPay[i] << std::endl;
  }
  
  //close file after writing the table into it
  closeWrittenFile(writepaysheet, paysheetFileName);
  
  return 0;
} //end main

//Function definitions

/*READ FUNCTION*/
void readFromFile(std::ifstream &readFile, std::string existingFile, bool showContent)
{
  readFile.open( existingFile.c_str() ); //information to be read from data.dat
  
  if ( readFile.fail() ) //check successful connection
  {
    std::cout << "\nFile '" << existingFile 
              << "'could not be opened." << std::endl;
    exit(1);
  }
  
  std::cout << "\nFile '" << existingFile 
            << "' successfully opened to read from it." << std::endl;
  
  //read the file line per line if showContent is True
  if (showContent == true)
  {
    std::string line;
    while ( std::getline(readFile, line) )
      std::cout << line << std::endl;
  }
}


/*WRITE FUNCTION*/
void writeToFile(std::ofstream &writeFile, std::string newFile)
{
  std::ifstream readFile; //in case file already exists
  
  readFile.open( newFile.c_str() ); //trying to open the file for input
  
  char userAns;
  if ( !readFile.fail() ) //don't fail: data file exists
  {
    std::cout << "\nA file named '"<< newFile 
              << "' already exists.\n" 
              << "Continue and overwrite? [y/n]: ";
    std::cin >> userAns;
    std::cin.ignore(); //empties buffer
    
    //if user chooses not to overwrite
    if (std::tolower(userAns) == 'n')
    {
      std::cout << "\nFile '" << newFile << "' won't be overwritten,"
                   " process finished." << std::endl;
      exit(1); //finish program execution
    }
  }
  
  readFile.close(); //finish reading process
  
  writeFile.open( newFile.c_str() ); //open file to write on it
  
  if ( writeFile.fail() ) //check successfull opening
  {
    std::cout << "\nFile '" << newFile 
              << "' could not be opened." << std::endl;
    exit(1);
  }
  
  std::cout << "\nFile '" << newFile 
            << "' successfully opened to write on it." << std::endl;
}


/*CLOSE FILE AFTER READING*/
void closeReadFile(std::ifstream &readFile, std::string existingFile)
{
  readFile.close(); //close file after reading from it
  std::cout << "\nFile '" << existingFile << "' successfully closed"
               " after reading from it." << std::endl;
}


/*CLOSE FILE AFTER WRITING*/
void closeWrittenFile(std::ofstream &writeFile, std::string newFile)
{
  writeFile.close(); //close file after writing on int
  std::cout << "\nFile '" << newFile << "' successfully closed "
               "after writing to it." << std::endl;
}
