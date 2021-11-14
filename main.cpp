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
	std::vector<std::string> workbook_name(1);
	std::ifstream data_file("./File/quiz_data3.csv");
  int n = 0;
	
	while(getline(data_file, line))
  {
    int j = 0;
    std::istringstream s_line(line);

		while (getline(s_line, items[j], ',')) {
      j++;
      items.resize(j + 1);
		}

    if(items[0] != workbook_name[n - 1]){
      workbook_name[n] = items[0];
      n++;
      workbook_name.resize(n + 1);
    }
	}
  
	data_file.close();

	return 0;
}


