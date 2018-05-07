void Fit(){

  
    //gStyle->SetOptFit(1111);

    //background
    TFile *bkg = new TFile("/u/user/hgass66/MadGraph/song/final/Allbkg.root");
    
    //signal + background
    TFile *sigbkg = new TFile("/u/user/hgass66/MadGraph/song/final/newsigbkg.root");

    TH1F *sigbkg_tMass = (TH1F*)sigbkg->Get("htM");
    TH1F *bkg_tMass = (TH1F*)bkg->Get("htM");

    //bkg_tMass->Scale(1./100.);
    //sigbkg_tMass->Scale(1./200.);
    cout <<  "signal+bkg : " << sigbkg_tMass->Integral(0,100) << endl;
    cout <<  "bkg : " << bkg_tMass->Integral(0,100) << endl;
///////////////////////////// Fitting ////////////////////////////////

	//fitGaus->SetParameters(1000,5,1);
	//gaus = new TF1("gaus","gaus",0,160);
	//exp = new TF1("exp","exp",150,500);
	TF1 *fData = new TF1("fData","gaus(0)+landau(3)",0,500);
	
	fData->SetParLimits(1,100,130);
	fData->SetParLimits(2,30,40);
	fData->SetParLimits(4,110,130);
	fData->SetParLimits(5,30,45);



	sigbkg_tMass->Fit(fData);
	    
    sigbkg_tMass->SetLineColor(kBlue);
    //fitGaus->SetLineColor(kRed);

    sigbkg_tMass->Draw("hist");
    fData->Draw("same");

    sigbkg_tMass->GetXaxis()->SetTitle("M_{e, jet}");
    sigbkg_tMass->GetYaxis()->SetTitle("Number of events");
    sigbkg_tMass->GetXaxis()->CenterTitle(true);

    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

}

