#include "./../include/Machine.h"
#include <iterator>


Machine::Machine(){
  this->pointer = 0;
  this->reserved_words.push_back("Estados");
  this->reserved_words.push_back("Inicial");
  this->reserved_words.push_back("Ha");
  this->reserved_words.push_back("He");
  this->reserved_words.push_back("Alfabeto");
  this->reserved_words.push_back("MT");
}

void Machine::loadFile(std::string filename){
  std::ifstream file;
  std::string cadena, substring;
  file.open(filename, std::ios::in);
  if(file.is_open()){
    while(!file.eof()){
      getline(file, cadena);
      /* cadena.erase(remove(cadena.begin(), cadena.end(), ' ')); */
      std::cout << "Cadena: " << cadena << std::endl;
      this->analyzer(cadena);
    }
    file.close();
  }
  else{
    std::cout << "No se pudo abrir \n";
  }
}

int Machine::getIndex(std::string ref, char c){
  auto it = std::find(ref.begin(), ref.end(), c);
  if(it != ref.end()){
    return std::distance(ref.begin(), it);
  }
  return -1;
}

std::string Machine::trimString(int x, int y, std::string ref){
  return ref.substr(0, x) + ref.substr(y, ref.length()-1);
}


void Machine::analyzer(std::string line){
  std::string aux = "";
  for(int i = 0; i < line.length(); i++){
    if(line[i] == '('){
      break;
    }
    else{
      aux += line[i];
    }
  }
  std::cout << "Filtered Line: " << aux << std::endl;
}







