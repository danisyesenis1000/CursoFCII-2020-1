#include<iostream>
#include<iomanip>
#include<vector>


void Fib_Vector(unsigned int n)
{
  //Error
  if (n < 2) 
  {
    std::cout << "Invalid input. Fibonacci sequence has sense for at least the first two terms." << std::endl;
    return; //Finish this function
  }
  
  //Variables of interest to generate the Fibonacci sequence
  int previous = 0, current = 1, next = 0;
  
  //Vector initialization: empty vector with no size defined yet
  std::vector<int> Fib;
  
  //Counting variables used in "for" loops
  size_t CreationIndex, PrintIndex;
  
  //First two elements of the Fibonacci sequence
  Fib.push_back(previous);
  Fib.push_back(current);
  
  //Next terms. As there are already two elements (indices 0, 1), 
  //loop starts with index 2
  for (CreationIndex = 2; CreationIndex < n; CreationIndex++)
  {
    next = previous + current;
    
    //Appends element at the end of the vector 
    Fib.push_back(next);
    
    previous = current;
    current = next;
  }
  
  //PRINTING: Same as with an array
  std::cout << "\nFibonacci sequence up to " << n << " terms (using std::vector):\n"
            << "|" << std::setw(8) << " i " << "|"
                   << std::setw(8) << " F(i) " << "|" << std::endl;
  for(PrintIndex = 0; PrintIndex < n; PrintIndex++)
  {
    std::cout << std::setw(8) << PrintIndex << " " 
              << std::setw(8) << Fib[PrintIndex] << std::endl;
  }
  
}

void Fib_Array(unsigned int n)
{
  //Error
  if (n < 2) 
  {
    std::cout << "Invalid input. Fibonacci sequence has sense for at least the first two terms." << std::endl;
    return; //Finish this function
  }
  
  //Variables of interest to generate the Fibonacci sequence
  int previous = 0, current = 1, next = 0;
  
  //Array initialization: length n, first two elements added
  int Fib[n] = {previous, current};
  
    //Counting variables used in "for" loops
  size_t CreationIndex, PrintIndex;
  
  //Next terms. As there are already two elements (indices 0, 1), 
  //loop starts with index 2
  for (CreationIndex = 2; CreationIndex < n; CreationIndex++)
  {
    next = previous + current;

    //Element at position "CreationIndex" is assigned the right value
    Fib[CreationIndex] = next;
    
    previous = current;
    current = next;
  }
  
  //PRINTING: Same as with a vector
  std::cout << "\nFibonacci sequence up to " << n << " terms (using array):\n"
            << "|" << std::setw(8) << " i " << "|"
                   << std::setw(8) << " F(i) " << "|" << std::endl;
  for(PrintIndex = 0; PrintIndex < n; PrintIndex++)
  {
    std::cout << std::setw(8) << PrintIndex << " "
              << std::setw(8) << Fib[PrintIndex] << std::endl;
  }
  
}

int main()
{
  //Warning: Functions not protected against float, negative or some other bad inputs.
  Fib_Vector(11);
  Fib_Array(17);
  
  return(0);
}
