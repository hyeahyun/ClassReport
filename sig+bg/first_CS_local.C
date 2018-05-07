void first_CS_local(){

    //TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //Signal
    TFile *after_sig = new TFile("/u/user/hgass66/MadGraph/song/no/after_signal.root");
    TFile *before_sig = new TFile("/u/user/hgass66/MadGraph/song/no/beforesignal.root");
    TFile *pseudo_sig = new TFile("/u/user/hgass66/MadGraph/song/no/pseudosig.root");
    
    //background
    TFile *after_bkg = new TFile("/u/user/hgass66/MadGraph/song/no/after_Allbkg.root");
    TFile *before_bkg = new TFile("/u/user/hgass66/MadGraph/song/no/beforeAllbkg.root");
    TFile *pseudo_bkg = new TFile("/u/user/hgass66/MadGraph/song/no/pseudobkg.root");
    
    //signal + background
    //TFile *after_sigbkg = new TFile("/u/user/hgass66/MadGraph/song/no/after_sigbkg.root");
    //TFile *before_sigbkg = new TFile("/u/user/hgass66/MadGraph/song/no/beforesigbkg.root");

    //pseudo
    //TFile *pseudo_sigbkg = new TFile("/u/user/hgass66/MadGraph/song/no/pseudosigbkg.root");

    TCanvas *c1 = new TCanvas("c1","cross section",200,10,1400,1000);
    /////////////////////// histogram ///////////////////////
    //signal
    TH1F *after_sig_tMass = (TH1F*)after_sig->Get("htM");
    TH1F *before_sig_tMass = (TH1F*)before_sig->Get("htM");
    TH1F *pseudo_sig_tMass = (TH1F*)pseudo_sig->Get("signal_hist");
    //TH1F *bkg_tMass = (TH1F*)bkg->Get("htM");

    //background
    TH1F *after_bkg_tMass = (TH1F*)after_bkg->Get("htM");
    TH1F *before_bkg_tMass = (TH1F*)before_bkg->Get("htM");
    TH1F *pseudo_bkg_tMass = (TH1F*)pseudo_bkg->Get("signal_hist");
    
    //sig+bkg
    //TH1F *after_sigbkg_tMass = (TH1F*)after_sigbkg->Get("htM");
    //TH1F *before_sigbkg_tMass = (TH1F*)before_sigbkg->Get("htM");
    //TH1F *pseudo_sigbkg_tMass = (TH1F*)pseudo_sigbkg->Get("signal_data");

    TH2F * cs_hist = new TH2F("cs_hist"," ",100,0,500,100,0,2);

///////////Conditional statement//////////////
    //bkg_tMass->Scale(1./100.);
    //sigbkg_tMass->Scale(1./200.);
    after_sig_tMass->Rebin(5);
    before_sig_tMass->Rebin(5);
    pseudo_sig_tMass->Rebin(5);

    after_bkg_tMass->Rebin(5);
    before_bkg_tMass->Rebin(5);
    pseudo_bkg_tMass->Rebin(5);

    //pseudo_sigbkg_tMass->Rebin(5);

    //after_sigbkg_tMass->Rebin(5);
    //before_sigbkg_tMass->Rebin(5);
    //pseudo_sigbkg_tMass->Rebin(5);



    const double globle_cs = 78.1108923852+23.3633; //sig+bkg globel cross section
    //int totalN = before_sigbkg_tMass->Integral();
    //double weight = 100. * globle_cs / totalN;
   
    //cout << totalN << endl;

    TAxis *xaxis = after_sig_tMass->GetXaxis();
    double X_axis[20];
    double Y1[20];
    //cout << xaxis->GetBinCenter(17)<<endl;
    for(int i=0; i<20; i++){
	int j = i+1;
	double after_sig_entry = after_sig_tMass->GetBinContent(j);
	double before_sig_entry = before_sig_tMass->GetBinContent(j);
	double pseudo_sig_entry = pseudo_sig_tMass->GetBinContent(j);
	
	double after_bkg_entry = after_bkg_tMass->GetBinContent(j);
	double before_bkg_entry = before_bkg_tMass->GetBinContent(j);
	double pseudo_bkg_entry = pseudo_bkg_tMass->GetBinContent(j);
	
	X_axis[i] = xaxis->GetBinCenter(j);
	
	double sig_local_cs = pseudo_sig_entry * before_sig_entry / (after_sig_entry * 100.); // Lumi = 100
	double bkg_local_cs = pseudo_bkg_entry * before_bkg_entry / (after_bkg_entry * 100.); // Lumi = 100
	
	//double Observed_cs = globle_cs / local_cs;
	//double event_ratio = local_entry / totalN;

	double Observed_cs = sig_local_cs / bkg_local_cs;
	Y1[i] = Observed_cs;
	cs_hist->Fill(X_axis[i],Observed_cs);
    }

///////////////////TGraph/////////////////////////////

    
    //cs_hist->Draw();
    
    TGraph *CS = new TGraph(20,X_axis,Y1);

    CS->SetMarkerStyle(20);
    CS->SetMarkerSize(1);
    CS->SetTitle("Cross Section;M_{e,jet};#sigma/#sigma_{SM}");

    CS->Draw("ALP");


    //cout <<  "signal+bkg : " << sigbkg_tMass->Integral(4,40) << endl;
    //cout <<  "bkg : " << bkg_tMass->Integral(4,40) << endl;
///////////////////////////// Canvas ////////////////////////////////
    


   // cs_hist->GetXaxis()->SetTitle("M_{e,jet}");
   // cs_hist->GetYaxis()->SetTitle("cross-section");
   // cs_hist->SetMarkerSize(8);


   // cs_hist->Draw();

    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

}

