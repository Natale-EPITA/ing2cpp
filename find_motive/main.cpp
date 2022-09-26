#include <iostream>
#include <fstream>
#include <string>


int main(int argc , char** argv){
    
    std::fstream newFile;
    newFile.open(argv[1],std::ios::in);

    if(newFile.is_open() && argc==3){
        int cpt = 0;
        std::string line;
        std::string motive = argv[2];

        while(getline(newFile,line)){
            size_t pos = 0;
            std::string word ;

            while( (pos=line.find(" "))!= std::string::npos ){
                word = line.substr(0,pos);

                if(word.find(argv[2])!=std::string::npos){
                    cpt+=1;
                }
                line.erase(0,pos+1);// Pos + delimiter length
            }


        }
        std::cout << "The file "<<argv[1]<<" contains "<<cpt <<" words containing the motive "<< argv[2]<<"\n";
        return 0;
    }
std::cout<<"The file "<<argv[1]<<" could not be opened.\n";
return 1;
}