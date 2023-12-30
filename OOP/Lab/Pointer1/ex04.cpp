#include <iostream>
#include <iomanip> 
#include <math.h>

void GeoAndHarmoMean()
{
    int size = 0;
    double input[100];
    double number;
    double GeometirxMean = 1;
    double HarmonicMean;
    double denominator = 0;
    double numerator = 0;

    while (size < 100){
        std::cin >> number;
        if (number == 99999)
            break;
        else{
            input[size] = number;
            size++;
        }
    }

    for (int i = 0; i < size; i++){
        GeometirxMean *= input[i];
    }
    GeometirxMean = pow(GeometirxMean, 1.0/size);

    for (int i = 0; i < size; i++){
        denominator += 1/input[i];
    }
    HarmonicMean = size/denominator;

    std::cout << "geometrix mean is " << GeometirxMean << "\n";
    std::cout << "harmonic mean is " << HarmonicMean << "\n";
}

int main(){
    GeoAndHarmoMean();
    return 0;
}
