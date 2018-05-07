#include <iostream>
#include "TROOT.h"


void poisson(){

    TH1F *sigbkg = new TH1F("sigbkg","signal + background",2000000,0,20);
    TH1F *bkg = new TH1F("bkg","background",2000000,0,20);

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
//	int b1 = bkg -> GetBinContent(600001);
//	int b2 = bkg -> GetBinContent(657025);
//	cout << "b1:" << b1 << endl;
//	cout << "b2:" << b2 << endl;
    
    	double integ_bkg = bkg->Integral();
    	//double integ_glo_exp = sigbkg->Integral(0,700957);
    	double integ_glo_obs1 = bkg->Integral(564937,2000000);
	double integ_glo_exp1 = bkg->Integral(657025,2000000);
	double exclusion = sigbkg->Integral(0,564937);
	double integ_sigbkg = sigbkg->Integral();
	
	double pvalue_exp = 100*(integ_glo_exp1/integ_bkg);
	double pvalue_obs = 100*(integ_glo_obs1/integ_bkg);
	double exclusionrate = 100*(exclusion/integ_sigbkg);
//
//	double integ_glo_exp = bkg->IntegratePoissonFromRight():
	
	//double integ_loc_bkg = loc_bkg->Integral();
	//double integ_loc_exp = loc_bkg->Integral(6.57025,20);
	//double integ_loc_obs = loc_bkg->Integral(6.56990,20);
	
	cout << "integ_glo_exp:" << integ_glo_exp1 << endl;
	cout<< "expected p-value:" << pvalue_exp << "%"<< endl;
     // 
        cout << "integ_glo_obs:" << integ_glo_obs1 << endl;
	cout << "observed p-value:" << pvalue_obs <<"%"<<endl;
     // cout << "p-value1:" << integ_bkg << endl;
        cout << "exclusion rate:" << exclusionrate << "%"<< endl;


    sigbkg->SetLineColor(kRed);
    bkg->SetLineColor(kBlue);
    bkg->Draw();
    sigbkg->Draw("same");
    //bkg->GetXaxis()->SetRangeUser(0,6000);

    bkg->GetXaxis()->SetTitle("Number of events");
    bkg->GetYaxis()->SetTitle("Number of toy-experiments");

}
