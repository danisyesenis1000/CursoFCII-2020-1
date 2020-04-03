#include<iostream>
#include<iomanip>
#include<vector>

//DECLARATION OF FUNCTIONS
std::vector<unsigned short int> Divisors(unsigned short int);
unsigned short int SumOfElements(const std::vector<unsigned short int> &);
void PrintVector(const std::vector<unsigned short int> &);
bool Perfect(unsigned short int);

//MAIN FUNCTION
int main()
{ 
  //Upper bound to look for perfect numbers
  unsigned short int UppBound = 10000;
  
  std::cout << "Looking for perfect numbers less than or equal to " 
            << UppBound << ": " << std::endl;
  
  for(unsigned short int n = 1; n <= UppBound; n++)
  {
    if (Perfect(n) == true)
    {
      std::cout << "\n" << n << " is a perfect number. Divisors: \n";
      PrintVector(Divisors(n));
    }
  }
  
  return(0);
}

//FUNCTIONS AND METHODS

//Function returning a vector with the divisors of "N"
std::vector<unsigned short int> Divisors(unsigned short int N)
{
  std::vector<unsigned short int> Divisors;
  
  unsigned short int bound = 1;
  
  while (bound < N)
  {
    if (N % bound == 0)
    {
      Divisors.push_back(bound);
    }
    
    bound += 1;
  }
  
  return(Divisors);
}

//Function to add up all the elements of the vector "Vec"
unsigned short int SumOfElements(const std::vector<unsigned short int> &Vec)
{
  unsigned short int SumOfElem = 0;
  
  size_t i;
  
  for(i = 0; i < Vec.size(); i++)
  {
    SumOfElem += Vec[i];
  }
  
  return(SumOfElem);
}

//Function to print all the elements of the vector "Vec"
void PrintVector(const std::vector<unsigned short int> &Vec)
{
  size_t i;
  
  for(i = 0; i < Vec.size(); ++i)
  {
    std::cout << std::left << std::setw(5) << Vec[i];
  }
  
  std::cout << std::endl;
}

//GOAL FUNCTION: returns "true" if "n" is a perfect number
bool Perfect(unsigned short int n)
{
  //Internal variables
  unsigned short int DiviSum;
  std::vector<unsigned short int> DiviVec;
    
  DiviVec = Divisors(n);
  DiviSum = SumOfElements(DiviVec);
    
  if (DiviSum == n) { return(true); }
  
  else { return(false); }  
}
