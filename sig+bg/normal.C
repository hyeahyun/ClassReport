#include "TMath.h"

void normal(){

    double XMIN = -1;
    double XMAX = -1;
    long YMAX = 600000;
    int rebin = 1;

    const double Lumi = 100;

    const double xsecSignal = 23.3633;
    const double xsecBKG = 78.1108923852+23.3633;
    const double xsecRealBKG = 78.1108923852;

    TString dirname = "/u/user/hgass66/MadGraph/song/data27";

    TFile *fSignal        = TFile::Open(dirname +"/signal.root");
    TFile *fBKG           = TFile::Open(dirname +"/BKG.root");
    TFile *fRealBKG       = TFile::Open(dirname +"/Allbkg.root");

    TString histname = "htM"; XMAX=500; XMIN=0; YMAX=45; rebin=1;

    TH1F *hSignal = (TH1F*)fSignal->Get(histname); hSignal->Scale(xsecSignal*Lumi/100000) ;
    TH1F *hBKG    = (TH1F*)fBKG->Get(histname);    hBKG->Scale(xsecBKG*Lumi/200000) ;  //Signal + BKG
    TH1F *hRealBKG = (TH1F*)fRealBKG->Get(histname); hSignal->Scale(xsecSignal*Lumi/100000) ;

    hBKG->SetLineColor(41);hBKG->SetFillColor(41);
    hSignal->SetLineColor(2);hSignal->SetFillColor(2);

    hBKG->Rebin(rebin);
    hSignal->Rebin(rebin);

    cout << "Nevents Signal" << hSignal->Integral() << endl;
    cout << "Nevents Background" << hBKG->Integral() << endl;

    TCanvas *c1 = new TCanvas();

    TH2F *nul = new TH2F("nul","",2,XMIN, XMAX, 2, 0.09, YMAX);
    nul->GetYaxis()->SetTitle("Events");
    nul->GetYaxis()->SetTitleSize(0.04);
    nul->GetYaxis()->SetLabelSize(0.04);
    nul->Draw();
    hBKG->Draw("same hist");
    hSignal->Draw("same hist");

    TLegend *l0 = new TLegend(0.65,0.89,0.90,0.65);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);

     TLegendEntry* l02 = l0->AddEntry(hSignal,"Signal"   ,"f"  ); l02->SetTextColor(hSignal->GetLineColor());
     TLegendEntry* l03 = l0->AddEntry(hBKG,"BKG"   ,"f"  ); l03->SetTextColor(hBKG->GetLineColor());

     l0->Draw();

}
