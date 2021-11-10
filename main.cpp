#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#define READ_LINE 10

int main() {
  std::string line;
	std::vector<std::string> items(1);
	std::string workbook_name[256];
	std::ifstream data_file("./File/quiz_data.csv");
	
  for(int i=0;i<10;i++){
	//while(getline(data_file, line)){
    getline(data_file, line);
    int j = 0;

    std::istringstream s_line(line);

		while (getline(s_line, items[j], ',')) {
      j++;
      items.resize(j + 1);
		}
	}

	data_file.close();

	return 0;
}
