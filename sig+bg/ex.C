#include <iostream>

void ex(){

    //TH1D *sigbkg = new TH1D("sigbkg","signal + background",200,0,20);

    TH1D *h1 = new TH1D("bkg","",200,0,20);

    for(int i = 0; i < 10000; i++)
    {
	float a = gRandom->Poisson(6.57025);	//sig+bkg

	double b = gRandom->PoissonD(3.5);	//bkg
	//float a = gRandom->Poisson(7.00953);	//pseudo data	
	//float a = gRandom->Poisson(6.57025);	//loc sig+bkg	
	//float b = gRandom->Poisson(3.04632);	//loc bkg	
	//float a = gRandom->Poisson(6.56990);	//loc pseudo data	
	
	cout << b << endl;
 	//h1 -> Fill(b);
    }
	//h1->Draw();

	double integ_bkg = h1->Integral();
    	double integ_sig = h1->Integral(66,200);
	double pvalue = 100*(integ_sig/integ_bkg);
	
	int bin1 = h1 -> GetBinContent(11);
	int bin2 = h1 -> GetBinContent(66);


	//cout << "integ_glo_exp:" << integ_glo_exp << endl;
	//cout << "p-value:" << pvalue << "%"<< endl;
   	cout << "bin1:" << bin1 << endl;
   	cout << "bin2:" << bin2 << endl;
    


}
