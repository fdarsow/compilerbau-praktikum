#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc <= 1) {
        cout << "No file provided." << endl;
        return 0;
    }
    ostream* output = &cout;
    ofstream output_file;
    if(argc == 3) {
        output_file.open (argv[2]);
        output = &output_file;
    }

    string line;
    ifstream source (argv[1]);
    if (source.is_open())
    {
        bool last_new_line = false;
        while ( getline (source,line) )
        {
            for (int i = 0; i < line.length(); i++) {
                if(!isalpha(line[i])) {
                    if (!last_new_line) {
                        *output <<  '\n';
                        last_new_line = true;
                    }
                }
                else {
                    *output << line[i];
                    last_new_line = false;
                }
            }
            if (!last_new_line) {
                *output <<  '\n';
                last_new_line = true;
            }

        }
        source.close();
    }
    return 0;
}
