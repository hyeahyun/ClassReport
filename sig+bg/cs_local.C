void cs_local(){

    //TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //Signal
    //TFile *signal = new TFile("/u/user/hgass66/MadGraph/song/data/signal.root");
    
    //background
    TFile *bkg = new TFile("/u/user/hgass66/MadGraph/song/final/Allbkg.root");
    
    //signal + background
    TFile *sigbkg = new TFile("/u/user/hgass66/MadGraph/song/final/newsigbkg.root");

    /////////////////////// histogram ///////////////////////
    //electron energy + MET
    //TH1F *sig_tMass = (TH1F*)signal->Get("htM");
    TH1F *sigbkg_tMass = (TH1F*)sigbkg->Get("htM");
    TH1F *bkg_tMass = (TH1F*)bkg->Get("htM");

///////////integral//////////////
    //bkg_tMass->Scale(1./100.);
    //sigbkg_tMass->Scale(1./200.);
    sigbkg_tMass->Rebin(5);

    const double cs = 101.4741923852; //sig+bkg cross section
    
	for(int i=0; i<20; i++){
	double local_entry = sigbkg_tMass->GetBinContent(i);
    cout <<  "signal+bkg : " << sigbkg_tMass->Integral(4,40) << endl;
    cout <<  "bkg : " << bkg_tMass->Integral(4,40) << endl;
///////////////////////////// Canvas ////////////////////////////////

    TCanvas *c1 = new TCanvas();
    
    //sig_tMass->Rebin(15);
    //sigbkg_tMass->Rebin(15);
    //bkg_tMass->Rebin(15);


    //sig_tMass->SetLineColor(2);
    sigbkg_tMass->SetLineColor(kRed);
    bkg_tMass->SetLineColor(kBlue);

//    sigbkg_tMass->Rebin(5);
//    bkg_tMass->Rebin(5);
    //sig_tMass->Draw();
    sigbkg_tMass->Draw("e");
    bkg_tMass->Draw("same e");

    sigbkg_tMass->GetXaxis()->SetTitle("M_{e, jet}");
    sigbkg_tMass->GetYaxis()->SetTitle("Number of events");
    sigbkg_tMass->GetXaxis()->CenterTitle(true);

    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

}

