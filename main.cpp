#include <iostream>
#include <cmath>
#include <ctime>

#include <chrono>
#include <thread>

using namespace std;

bool esPrimo(long numero) {
  // Casos especiales
  if (numero == 0 || numero == 1 || numero == 4) return false;
  for (long x = 2; x < numero / 2; x++) {
    if (numero % x == 0) return false;
  }
  // Si no se pudo dividir por ninguno de los de arriba, sí es primo
  return true;
}



void sumaPrimosConvencional(long iterations){
    unsigned t0,t1;


    long result = 0;
    int primosCounter = 0;


    t0=clock();
    for(long x=1; x<=iterations; x++){

            for (long i=1; i <= x; i++){

                if(x%i==0){
                    primosCounter++;
                    //cout << "i: "<< i <<" x: "<< x <<endl;

                    if(primosCounter>2){
                        break;
                    }
                }
            }
        
        if (primosCounter==2){
            result += x;
        }
        else{
            //cout<<"No es primo :C "<< " x: "<< x << " primos counter: " << primosCounter << endl;

            //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            primosCounter = 0;

            continue;
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "The result is: " << result << " x: " << x << " primos counter: "<< primosCounter << endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(300));

    //cout << "x: " << x <<endl;
    primosCounter = 0;
    }
    t1 = clock();
    double time = (double(t1-t0)/double(CLOCKS_PER_SEC));

    cout << "Execution time: " << time << endl;
}


int main(){

    //sumaPrimosConvencional(5000000);
    sumaPrimosConvencional(50);



    return EXIT_SUCCESS;
}