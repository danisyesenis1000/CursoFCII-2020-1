#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

void CFILE(string);
void RFILE(fstream&);

int main()
{
  string nfile = "datos.txt";   

  CFILE(nfile);         

  fstream fileent(nfile.c_str(),ios::in);  
  
  
  RFILE(fileent);          
  fileent.close();                   
  return 0;
}


void CFILE(string name)
{
  fstream file(name.c_str(),ios::out);
  if(file.fail())
    {
      cout << "Fallo abrir el archivo" << endl;
      exit(1);
    }

  string Names[4]={"B Caldwell","D Memcheck","R Potter","W Rosen"};
  string Number[4]={"555-88-2222","555-77-4444","555-77-6666","555-99-8888"};
  double Rate[4]={7.32,8.32,6.54,9.80};
  int Hour[4]={37,40,40,35};
  for(int i=0;i<4;i++)
    {
      file << left << setw(11) << *(Names+i) << setw(12) << *(Number+i) << setw(5) << fixed << setprecision(2) << *(Rate+i) << setw(2) << *(Hour+i) << endl;
    }

  file.close(); 
}

void RFILE(fstream& file)
{
  string name1;
  string name2;
  string number1;
  double rate;
  double hour;
  double pay;
  cout << left <<setw(14) << "Nombre" << setw(14) << "Seguro social" << setw(7) << fixed << setprecision(3) << "Pago" << endl;
  cout << endl;
  for(int i=0;i<4;i++)
    {
      file >> name1 >> name2 >> number1 >> rate >> hour;
      pay=rate*hour;
      cout << left << setw(14) << name1+" "+name2 << setw(14) << number1 << setw(7) << pay << endl;;
    }
}
