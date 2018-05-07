void v2_first_CS_local(){
    TCanvas *c1 = new TCanvas();

    TFile *after_sig = new TFile("/u/user/hgass66/MadGraph/song/no/after_signal.root");
    TFile *before_sig = new TFile("/u/user/hgass66/MadGraph/song/no/beforesignal.root");
    TFile *pseudo_sig = new TFile("/u/user/hgass66/MadGraph/song/no/pseudosig.root");
    
    //background
    TFile *after_bkg = new TFile("/u/user/hgass66/MadGraph/song/no/after_Allbkg.root");
    TFile *before_bkg = new TFile("/u/user/hgass66/MadGraph/song/no/beforeAllbkg.root");
    TFile *pseudo_bkg = new TFile("/u/user/hgass66/MadGraph/song/no/pseudobkg.root");
    
    TH1F *after_sig_tMass = (TH1F*)after_sig->Get("htM");
    TH1F *before_sig_tMass = (TH1F*)before_sig->Get("htM");
    TH1F *pseudo_sig_tMass = (TH1F*)pseudo_sig->Get("signal_hist");
    //TH1F *bkg_tMass = (TH1F*)bkg->Get("htM");

    //background
    TH1F *after_bkg_tMass = (TH1F*)after_bkg->Get("htM");
    TH1F *before_bkg_tMass = (TH1F*)before_bkg->Get("htM");
    TH1F *pseudo_bkg_tMass = (TH1F*)pseudo_bkg->Get("signal_hist");
    
    TH2F *cs_hist = new TH2F("cs_hist"," ",20,0,500,100,0,2);
    //sigbkg_tMass->Scale(1./200.);
    after_sig_tMass->Rebin(5);
    before_sig_tMass->Rebin(5);
    pseudo_sig_tMass->Rebin(5);

    after_bkg_tMass->Rebin(5);
    before_bkg_tMass->Rebin(5);
    pseudo_bkg_tMass->Rebin(5);

    const double globle_cs = 78.1108923852+23.3633; //sig+bkg globel cross section
    //int totalN = before_sigbkg_tMass->Integral();
    TAxis *xaxis = after_sig_tMass->GetXaxis();
    
    double X_axis[20];
    double Y1[20];
    //cout << xaxis->GetBinCenter(17)<<endl;
    for(int i=0; i<20; i++){
	double after_sig_entry = after_sig_tMass->GetBinContent(i);
	double before_sig_entry = before_sig_tMass->GetBinContent(i);
	double pseudo_sig_entry = pseudo_sig_tMass->GetBinContent(i);
	
	double after_bkg_entry = after_bkg_tMass->GetBinContent(i);
	double before_bkg_entry = before_bkg_tMass->GetBinContent(i);
	double pseudo_bkg_entry = pseudo_bkg_tMass->GetBinContent(i);
	
	X_axis[i] = xaxis->GetBinCenter(i);
	
	double sig_local_cs = (pseudo_sig_entry * before_sig_entry) / (after_sig_entry * 100.); // Lumi = 100
	double bkg_local_cs = (pseudo_bkg_entry * before_bkg_entry) / (after_bkg_entry * 100.); // Lumi = 100

	double Observed_cs = (sig_local_cs / bkg_local_cs);
	Y1[i] = Observed_cs;
	cs_hist->Fill(X_axis[i],Observed_cs);
    
    
    TGraph *CS = new TGraph(20,X_axis,Y1);

    CS->SetMarkerStyle(22);
    CS->SetMarkerSize(8);
    CS->Draw("a");
}}

