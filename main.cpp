#include <iostream>
#include <cmath>
#include <ctime>

#include <chrono>
#include <thread>
#include <omp.h>


using namespace std;

bool esPrimo(long long n){
  if (n < 2){
    return false;
  }
  for(long long i = 2; i<=sqrt(n);i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

void sumaPrimosRapida(long long iterations){
    long long n = 0;
    long long result;
    bool decoy = false;

    //// Paralelización de código
    #pragma omp for
    for(long long x=0; x<iterations;x++){
        decoy = esPrimo(x);

        if(decoy){
            result += x;
            cout << "result: "<<result<<endl;
        }
    }

    cout<<"The final result is: "<< result << endl;

}

void sumaPrimosConvencional(long long iterations){

    long long result = 0;
    int primosCounter = 0;


    for(long long x=1; x<=iterations; x++){

            for (long long i=1; i <= x; i++){

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
}


int main(){

    clock_t t0=clock();
    //sumaPrimosConvencional(5000000);

    sumaPrimosRapida(5000000);

    float time = (clock()-t0)*1000/CLOCKS_PER_SEC;

    cout << "Execution time: " << time << " miliseconds"<<endl;


    return EXIT_SUCCESS;
}