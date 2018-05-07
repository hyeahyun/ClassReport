#include <iostream>
#include "TROOT.h"


void local_poisson(){

    TH1F *sigbkg = new TH1F("sigbkg","signal + background",2000000,0,20);
    TH1F *bkg = new TH1F("bkg","background",2000000,0,20);

    for(int i = 0; i < 1000000; i++)
    {
	double a = gRandom->PoissonD(5.67549);	//sig+bkg
	double b = gRandom->PoissonD(2.33083);	//bkg
	//float a = gRandom->Poisson(7.00953);	//pseudo data	
	//float a = gRandom->Poisson(6.57025);	//loc sig+bkg	
	//float b = gRandom->Poisson(3.04632);	//loc bkg	
	//float a = gRandom->Poisson(567.538);	//loc pseudo data	
	
	sigbkg->Fill(a);
	bkg->Fill(b);
	//cout << a << endl;
    }
//	int b1 = bkg -> GetBinContent(600001);
//	int b2 = bkg -> GetBinContent(657025);
//	cout << "b1:" << b1 << endl;
//	cout << "b2:" << b2 << endl;
    
    	double integ_bkg = bkg->Integral();
    	double integ_glo_exp = bkg->Integral(567549,2000000);
    //	double integ_glo_exp1 = bkg->Integral();
	double pvalue = 100*(integ_glo_exp/integ_bkg);
//	double integ_glo_exp = bkg->IntegratePoissonFromRight():
	
	//double integ_loc_bkg = loc_bkg->Integral();
	//double integ_loc_exp = loc_bkg->Integral(6.57025,20);
	//double integ_loc_obs = loc_bkg->Integral(6.56990,20);
	
	cout << "integ_glo_exp:" << integ_glo_exp << endl;
	cout << "p-value:" << pvalue << "%"<< endl;
     //  cout << "p-value1:" << integ_bkg << endl;



    sigbkg->SetLineColor(kRed);
    bkg->SetLineColor(kBlue);
    bkg->Draw();
    sigbkg->Draw("same");
    //bkg->GetXaxis()->SetRangeUser(0,6000);

    bkg->GetXaxis()->SetTitle("Number of events");
    bkg->GetYaxis()->SetTitle("Number of toy-experiments");

}
