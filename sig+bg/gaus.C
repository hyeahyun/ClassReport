#include <iostream>
#include "TROOT.h"


void gaus(){

    TH1F *sigbkg = new TH1F("sigbkg","signal + background",20,0,20);
    TH1F *bkg = new TH1F("bkg","background",20,0,20);

    for(int i = 0; i < 1000000; i++)
    {
	double a = gRandom->PoissonD(6.57025);	//sig+bkg
	double b = gRandom->PoissonD(3.0462);	//bkg
	//float a = gRandom->Poisson(7.00953);	//pseudo data	
	//float a = gRandom->Poisson(6.57025);	//loc sig+bkg	
	//float b = gRandom->Poisson(3.04632);	//loc bkg	
	//float a = gRandom->Poisson(6.56990);	//loc pseudo data	
	
	sigbkg->Fill(a);
	bkg->Fill(b);
	//cout << gRandom->PoissonD(6.57025) << endl;
    }
	TF1 *fData = new TF1("fData","gaus(0)",0,10);

	fData->SetParLimits(1,6.57,6.58);

	sigbkg->Fit(fData);
    
    	double integ_bkg = bkg->Integral();
	

    sigbkg->SetLineColor(kRed);
    bkg->SetLineColor(kBlue);
    //bkg->Draw();
    sigbkg->Draw();
    fData->Draw("same");
    //bkg->GetXaxis()->SetRangeUser(0,6000);

    bkg->GetXaxis()->SetTitle("Number of events");
    bkg->GetYaxis()->SetTitle("Number of toy-experiments");

}
