#include <fstream>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>

double randomNum();
const double limiter = 1.0;
const int iterations = 500000;
const int skewness = 2; 

int main(){
    srand(time(NULL));
    std::ofstream myStream;
    myStream.open("output.txt");

    double total = 0;
    for(int i = 0; i < iterations; i++) {
        double temp = randomNum();
        // double temp = (double) rand() / RAND_MAX;  
        total += temp;
        // std::cout << temp << '\n';
        myStream << temp << std:: endl;
    }    

    std::cout << '\n' << "average "<< total/iterations << '\n';

    myStream.close();
    return 0;
}

double randomNum() {
    double ran = ((double) rand() / RAND_MAX);
    // std::cout << ran << "\n";
    // if (ran > .5) {
    //     ran -= .5;
    // } else if (ran <.5) {
    //     ran *= -1;
    // }
    // double modified = sqrt(ran);  
    double modified = pow(ran, .5);
    // numbers 0 to 1, skewed left 
    // std::cout << modified << "\n";
    // double distance = (1 - modified)/1.5;
    double distance = (1 - modified);
    //numbers 0 to 1, skewed right
    distance /= 2;
    //numbers 0 to .5. creates logarithimic scale to .5, where it should become harder to get farther
    // std::cout << distance << "\n";
    double ran2 = ((double) rand() / RAND_MAX);
    if(ran2 < .5) {
        return .5 - distance;
    } else {
        return .5 + distance;
    }
    // std::cout << modified;

    // return distance;
}