#include <iostream>
#include <vector>

std::vector<double> x = {1, 2, 3, 4, 5, 6};
std::vector<double> y = {1,4,9,16,25,36};

double learning_rate = 0.00001;

//y = wx + b

double w = 0.0;
double b = 0.0;

//gradient descent algorithm

std::vector<double> gradient_descent(){

    int i = 0;

    //derivative respect to w
    double dldw = 0.0;

    //derivative respect to b
    double dldb = 0.0;

while(i<x.size()){

    double xi = x[i];
    double yi = y[i];

    // (y - predicted)^2
    // (y - (wx + b))^2
    // dldw = -2x(y - (wx + b))

    dldw += -2*xi*(yi-(w*xi+b));

    // (y - predicted)^2
    // (y - (wx + b))^2
    // dldb = -2(y- (wx + b))

    dldb += -2*(yi-(w*xi + b));

    i++;
}

   double stepsize_w = dldw * learning_rate;
   double stepsize_b = dldb * learning_rate;

    w = w - stepsize_w;
    b = b - stepsize_b;

  return {w,b};
}


int main(){

std::vector<double> result;

    for(int j = 0; j<2500; j++){
       result = gradient_descent();
       std::cout<<"w "<<result[0]<<" "<<"b "<<result[1]<<std::endl;
    }

}

