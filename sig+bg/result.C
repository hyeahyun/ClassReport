void result(){

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
/*int a_bkg = 0;
int a_sigbkg = 0;
int max_bkg;
int max_sigbkg;
for(int i=0; i<100; i++){

    int b_bkg = bkg_tMass->GetBinContent(i);
    int b_sigbkg = sigbkg_tMass->GetBinContent(i);

    if(a_bkg < b_bkg){
	a_bkg = b_bkg;
	max_bkg = i;
    }
    if(a_sigbkg < b_sigbkg){
	a_sigbkg = b_sigbkg;
	max_skgbkg = i;
    }
}
    cout << "bkg max bin : " << max_bkg << endl;
    cout << "bkg max bin content : " << a_bkg << endl;
    cout << "sig+bkg max bin : " << max_sigbkg << endl;
    cout << "sig+bkg max bin content : " << a_sigbkg << endl;
 */
    bkg_tMass->Scale(1./100.);
    sigbkg_tMass->Scale(1./200.);
    cout <<  "signal+bkg : " << sigbkg_tMass->Integral() << endl;
    cout <<  "bkg : " << bkg_tMass->Integral() << endl;
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

