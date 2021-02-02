#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if(argc < 3)
        return 1 ;
    std::ifstream inFile1(argv[1]) ;
    std::ifstream inFile2(argv[2]) ;
    std::string line1, line2 ;
    bool diff = 0 ;
    int lineCounter = 0 ;
    if (inFile1.is_open() && inFile2.is_open()  )
    {
        while ( getline (inFile1,line1) && getline (inFile2,line2))
        {
            lineCounter ++ ;
            if(line1[line1.size() -1 ] == ' ')
            {
                line1.pop_back() ;
            }
            if(line1[line2.size() -1 ] == ' ')
            {
                line2.pop_back() ;
            }
            if(line1 != line2)
            {
                diff = 1 ;
                break ;
            }
        }
        inFile1.close();
        inFile2.close();

    }
    else
    {
        return 2 ;
    }
    if(diff)
    {
        std::cout << "The two files are different, in line number "<< lineCounter <<'\n';
        std::cout << "Expected \" " << line1 << " \" found \" " << line2 <<" \"\n" ;
    }
    else
    {
        std::cout << "the two files are same \n" ;
    }
return 0 ;
}
