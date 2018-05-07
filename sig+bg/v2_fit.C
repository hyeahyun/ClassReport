/*double f1(double *x, double *par){
    return par[0]*TMath::Gaus(x,par[1],par[2],1)+[3]*TMath::Gaus(x,[4],[5],1);
}*/


void v2_fit(){

    //TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //Signal
    //TFile *signal = new TFile("/u/user/hgass66/MadGraph/song/data/signal.root");
   
    gStyle->SetOptFit(1111);

    //background
    TFile *bkg = new TFile("/u/user/hgass66/MadGraph/song/final/Allbkg.root");
    
    //signal + background
    TFile *sigbkg = new TFile("/u/user/hgass66/MadGraph/song/final/newsigbkg.root");

    /////////////////////// histogram ///////////////////////
    TH1F *sigbkg_tMass = (TH1F*)sigbkg->Get("htM");
    TH1F *bkg_tMass = (TH1F*)bkg->Get("htM");

    //bkg_tMass->Scale(1./100.);
    //sigbkg_tMass->Scale(1./200.);
///////////////////////////// Fitting ////////////////////////////////

    TF1 *fit = new TF1("fit","gaus(0)+expo(3)",0,500); 
    //fit->SetParameters(69,109,34,5,-106);
    fit->SetParLimits(3,0,150);
    fit->SetParLimits(4,150,500);
    //bkg_tMass->Rebin(15);


    
    //fit->SetParLimits(3,146.5,130);//gaus 3rd? 
    //fit->SetParLimits(4,1,3);//gaus 4th?
    sigbkg_tMass->Fit(fit);

    //cout<<"Vavilov mean = " << fit->GetParameter(2) << " +/-" << fit->GetParError(2) << endl;
    //cout<<"Vavilov sigma = " << fit->GetParameter(3) << " +/-" << fit->GetParError(3) << endl;

    sigbkg_tMass->SetLineColor(kBlue);
    fit->SetLineColor(kRed);

    sigbkg_tMass->Draw("e");
    fit->Draw("same");

    sigbkg_tMass->GetXaxis()->SetTitle("M_{e, jet}");
    sigbkg_tMass->GetYaxis()->SetTitle("Number of events");
    sigbkg_tMass->GetXaxis()->CenterTitle(true);

    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

}

