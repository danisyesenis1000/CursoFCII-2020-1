#include <iostream>
#include <string>

//First part: replace all occurrences of 'e' by 'x'
std::string ReplaceEbyX(std::string input)
{
  std::string output = input; //avoid overwriting the input
  unsigned int length = int( output.length() );
  
  for(unsigned int i = 0; i < length; i++) //loop to find all events
  {
    switch ( output.at(i) )
    { //replace one character: 'e', at its position 'i', by string "x"
      case 'e': output.replace(i, 1, "x"); 
    }
  }
  
  return(output);
}

//Second part: search first occurrence of <findstr> inside <input> 
//and replace it with <replstr>
std::string ReplaceFirstOc(std::string input, 
                           std::string findstr,
                           std::string replstr)
{
  std::string output = input; //avoid overwriting the input
  unsigned int lengthRemove = int( findstr.length() );
  unsigned int indexFirstOc = output.find( findstr );
  
  //replace first occurrence of "findtstr" with "replstr"
  output.replace(indexFirstOc, lengthRemove, replstr);
  
  return(output);
}

//Third part: same as second part, replacing ALL occurrences
std::string ReplaceAllOc(std::string input, 
                           std::string findstr,
                           std::string replstr)
{
  std::string output = input; //avoid overwriting the input
  unsigned int lengthRemove = int( findstr.length() );
  
  unsigned int indexFirstOc = output.find(findstr); //first occurrence
  unsigned int position = indexFirstOc; //index to be looped
  
  //while the index remains less than the modified output string
  while ( position < int( output.length() ) )
  {
    output.replace(position, lengthRemove, replstr);
    position = output.find( findstr, position + 1 ); //refresh occurrence index
  }
  
  return(output);
}

int main(void)
{
  std::cout << "\nTest run with custom strings: \n" << std::endl;
  std::string test = "mis estimados colegas de mis hermanos";
  std::string out1 = ReplaceEbyX(test);
  std::string out2 = ReplaceFirstOc(test, "mis", "Los");
  std::string out3 = ReplaceAllOc(test, "mis", "los");
  
  std::cout << test << " -> " << out1 << std::endl;
  std::cout << test << " -> " << out2 << std::endl;
  std::cout << test << " -> " << out3 << std::endl;
  
  //
  
  std::cout << "\nTest run with book strings: \n" << std::endl;
  std::string Test = "La figura 4-4 ilustra la salida del programa 4-2";
  std::string Out1 = ReplaceEbyX(Test);
  std::string Out2 = ReplaceFirstOc(Test, "4-", "3-");
  std::string Out3 = ReplaceAllOc(Test, "4-", "3-");
  
  std::cout << Test << " -> " << Out1 << std::endl;
  std::cout << Test << " -> " << Out2 << std::endl;
  std::cout << Test << " -> " << Out3 << std::endl;
  
  return(0);
}
