# include <iostream>
# include <fstream>
# include <filesystem>
using namespace std;

void call_rec(string path, string target){

    if(filesystem::is_symlink(path))
        return;

    for (const auto & entry : filesystem::directory_iterator(path)){
    
        if(filesystem::is_directory(entry.path())){

            call_rec(entry.path(), target);

        }
        else{
            
            std::cerr << entry.path() << std::endl;
            ifstream file(entry.path());
            string line;
            while(getline(file, line)){
                cerr << line <<endl;
                if( line.find( target, 0 ) != string::npos ){
                    string path = entry.path();
                    cout << path << endl;
                    file.close();
                    return;
                }
            }
            file.close();

        }
        
    }
    
}

int main(int argc, char *argv[]){

    cerr<< argv[1] << " " << argv[2] << endl;

    string path(argv[1]);
    string number(argv[2]);
    //cerr<< path <<endl;
    call_rec(path, number);


    return 0;
}