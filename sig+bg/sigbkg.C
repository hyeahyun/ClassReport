void sigbkg(){

    TFile *outFile = new TFile("AllBackground.root","recreate");
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
   
    //number of jet w/o jet cut
    TH1F *sigbkg_Njet1 = (TH1F*)sigbkg->Get("hNjet1");
    TH1F *bkg_Njet1 = (TH1F*)bkg->Get("hNjet1");

    //number of jet with jet cut
    TH1F *sigbkg_Njet2 = (TH1F*)sigbkg->Get("hNjet2");
    TH1F *bkg_Njet2 = (TH1F*)bkg->Get("hNjet2");

    bkg_Njet1->Scale(1./100.);
    sigbkg_Njet1->Scale(1./200.);

    bkg_Njet2->Scale(1./100.);
    sigbkg_Njet2->Scale(1./200.);
///////////////////////////// Canvas ////////////////////////////////

    TCanvas *c1 = new TCanvas();
    
    //sig_tMass->Rebin(15);
    //sigbkg_tMass->Rebin(15);
    //bkg_tMass->Rebin(15);

    //sig_tMass->SetLineColor(2);
    sigbkg_tMass->SetLineColor(kRed);
    bkg_tMass->SetLineColor(kBlue);

    //sig_tMass->Draw();
    sigbkg_tMass->Draw();
    bkg_tMass->Draw("same");

    sigbkg_tMass->GetXaxis()->SetTitle("M_{#mu, jet}");
    sigbkg_tMass->GetYaxis()->SetTitle("Number of events");
    sigbkg_tMass->GetXaxis()->CenterTitle(true);

    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

    //number of jets w/o cut
    TCanvas *c2 = new TCanvas();
 
    sigbkg_Njet1->SetLineColor(kRed);
    bkg_Njet1->SetLineColor(kBlue);

    sigbkg_Njet1->Draw();
    bkg_Njet1->Draw("same");

    sigbkg_Njet1->GetXaxis()->SetTitle("Number of jets w/o cut");
    sigbkg_Njet1->GetYaxis()->SetTitle("Number of events");
    sigbkg_Njet1->GetXaxis()->CenterTitle(true);

    //number of jets with cut
    TCanvas *c3 = new TCanvas();

    sigbkg_Njet2->SetLineColor(kRed);
    bkg_Njet2->SetLineColor(kBlue);

    sigbkg_Njet2->Draw();
    bkg_Njet2->Draw("same");

    sigbkg_Njet2->GetXaxis()->SetTitle("Number of jets with cut");
    sigbkg_Njet2->GetYaxis()->SetTitle("Number of events");
    sigbkg_Njet2->GetXaxis()->CenterTitle(true);

}

