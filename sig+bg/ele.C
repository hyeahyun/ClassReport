void ele(){

    TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //Signal
    TFile *signal = new TFile("/u/user/hgass66/MadGraph/song/ele/signal.root");
    
    //background
    TFile *bkg = new TFile("/u/user/hgass66/MadGraph/song/ele/Allbkg.root");
    
    //signal + background
    //TFile *sigbkg = new TFile("/u/user/hgass66/MadGraph/song/final/newsigbkg.root");

    /////////////////////// histogram ///////////////////////
    //electron energy + MET
    //TH1F *sig_tMass = (TH1F*)signal->Get("htM");
    TH1F *sig_tMass = (TH1F*)signal->Get("htM");
    TH1F *bkg_tMass = (TH1F*)bkg->Get("htM");
   
    //electron pT
    TH1F *sig_elepT = (TH1F*)signal->Get("helepT");
    TH1F *bkg_elepT = (TH1F*)bkg->Get("helepT");

    //electron eta
    TH1F *sig_eleeta = (TH1F*)signal->Get("heleeta");
    TH1F *bkg_eleeta = (TH1F*)bkg->Get("heleeta");

///////////////////////////// Canvas ////////////////////////////////

    TCanvas *c1 = new TCanvas();
    
    //sig_tMass->Rebin(15);
    //sigbkg_tMass->Rebin(15);
    //bkg_tMass->Rebin(15);

    //sig_tMass->SetLineColor(2);
    sig_tMass->SetLineColor(kRed);
    bkg_tMass->SetLineColor(kBlue);

    //sig_tMass->Draw();
    sig_tMass->Draw();
    bkg_tMass->Draw("same");

    sig_tMass->GetXaxis()->SetTitle("M_{#mu, jet}");
    sig_tMass->GetYaxis()->SetTitle("Number of events");
    sig_tMass->GetXaxis()->CenterTitle(true);

    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

    //electron pT
    TCanvas *c2 = new TCanvas();
 
    sig_elepT->SetLineColor(kRed);
    bkg_elepT->SetLineColor(kBlue);

    sig_elepT->Draw();
    bkg_elepT->Draw("same");

    sig_elepT->GetXaxis()->SetTitle("Number of jets w/o cut");
    sig_elepT->GetYaxis()->SetTitle("Number of events");
    sig_elepT->GetXaxis()->CenterTitle(true);

    //electron eta
    TCanvas *c3 = new TCanvas();

    sig_eleeta->SetLineColor(kRed);
    bkg_eleeta->SetLineColor(kBlue);

    sig_eleeta->Draw();
    bkg_eleeta->Draw("same");

    sig_eleeta->GetXaxis()->SetTitle("Number of jets with cut");
    sig_eleeta->GetYaxis()->SetTitle("Number of events");
    sig_eleeta->GetXaxis()->CenterTitle(true);

}

