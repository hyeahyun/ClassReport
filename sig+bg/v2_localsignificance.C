#include <iostream>
#include "TROOT.h"


void v2_localsignificance(){
    
    TFile *bkg = new TFile("/u/user/hgass66/MadGraph/song/final/Allbkg.root");
    TFile *sigbkg = new TFile("/u/user/hgass66/MadGraph/song/final/newsigbkg.root");
    TFile *pseudo = new TFile("/u/user/hgass66/MadGraph/song/pseudo.root");

    TH1F *sigbkg_tMass = (TH1F*)sigbkg->Get("htM");
    TH1F *bkg_tMass = (TH1F*)bkg->Get("htM");
    TH1F *pseudodata = (TH1F*)pseudo->Get("sigbkg_hist");

    TH1F *sigbkg_2 = new TH1F("sigbkg_2","sigbkg",10000,0,10);
    TH1F *bkg_2 = new TH1F("bkg_2","bkg",10000,0,10);
   // TH1F *pseudo_2 = new TH1F("pseudo_2","pseudo",1000,0,10);

    TH2F *localsignificance_exp = new TH2F("localsignificance_exp","expected",20,0,500,100,0,10);
    TH2F *localsignificance_obs = new TH2F("localsignificance_obs","observed",20,0,500,100,0,10);

    sigbkg_tMass->Rebin(5);
    bkg_tMass->Rebin(5);

    sigbkg_tMass->Scale(1./100.);
    bkg_tMass->Scale(1./200.);

   // sigbkg_tMass->Draw();
   // bkg_tMass->Draw("same");
     
    TAxis *xaxis = sigbkg_tMass->GetXaxis();
    for(int i = 0; i < 20; i++)
    {
        double bkgsig_event = sigbkg_tMass->GetBinContent(i);
	double bkg_event = bkg_tMass->GetBinContent(i);
        double pseudo_event = pseudodata->GetBinContent(i);

	double X_axis = xaxis->GetBinCenter(i);

	for ( int j=0; j<10000; j++)
	{

	double a = gRandom->Poisson(bkgsig_event);	//sig+bkg
	double b = gRandom->Poisson(bkg_event);	//bkg
	
	sigbkg_2->Fill(a);
	bkg_2->Fill(b);

	double integ_bkg = bkg_2->Integral();
	double integ_exp = bkg_2->Integral(bkgsig_event * 1000,10000);
        double integ_obs = bkg_2->Integral(pseudo_event * 1000,10000);

	double expected_pvalue = 100*(integ_exp/integ_bkg);
        double observed_pvalue = 100*(integ_obs/integ_bkg);
      
	localsignificance_exp->Fill(X_axis,expected_pvalue);
        localsignificance_obs->Fill(X_axis,observed_pvalue);
	}}
    TCanvas *c1 = new TCanvas();
    localsignificance_exp->Draw();
    localsignificance_obs->Draw("same");

    localsignificance_exp->GetXaxis()->SetTitle("Energy");
    localsignificance_exp->GetYaxis()->SetTitle("Local p-value");

}
