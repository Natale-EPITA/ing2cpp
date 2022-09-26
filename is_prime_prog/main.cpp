#include <iostream>
#include <cmath>

int main()
{
    int nb;
    while (std::cin>>nb){
        bool premier = true;
        if (nb<=1){
            premier = false;
        }
        int i;
        for (i=2;i<=std::sqrt(nb);i++){
            if (nb%i==0){
                premier = false;
                break;
            }
        }
    
            std::cout<<nb<< " is a prime:"; 
            (premier)? std::cout<<" True\n" : std::cout<<" False\n";
        
    }
    return 0;
}