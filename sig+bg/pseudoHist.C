void pseudoHist(){

    //TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //signal + background
    TFile *sigbkg = new TFile("/u/user/hgass66/MadGraph/song/pseudo.root");

    /////////////////////// histogram ///////////////////////
    //electron energy + MET
    //TH1F *sig_tMass = (TH1F*)signal->Get("htM");
    TH1F *pseudo = (TH1F*)sigbkg->Get("signal_hist");

///////////////////////////// Canvas ////////////////////////////////

    TCanvas *c1 = new TCanvas();
    
    //sigbkg_tMass->SetLineColor(kRed);
    //bkg_tMass->SetLineColor(kBlue);

//    sigbkg_tMass->Rebin(5);
//    bkg_tMass->Rebin(5);
    //sig_tMass->Draw();
    pseudo->Draw("hist");

    pseudo->GetXaxis()->SetTitle("M_{e, jet}");
    pseudo->GetYaxis()->SetTitle("Number of events");
    pseudo->GetXaxis()->CenterTitle(true);


}

