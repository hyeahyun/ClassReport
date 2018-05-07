#include <iostream>
#include "TROOT.h"
//#include "TRandom.h"
//
double f1(int k, int l)
{
    double func = TMath::Exp(-l)*TMath::Power(l,k);
    for (int i=1; i<=k; i++){
	func /= i;
    }
    return func;
}

void seokjoon(){

    TF1 *fun = new TF1("Poisson","TMath::Poisson(x,[0])",10);	 

	fun->Draw();
}
