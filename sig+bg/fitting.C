struct Vavilov_Func {
    Vavilov_Func() {}

    double operator() (const double *x, const double *p){
	double kappa = p[0];
	double beta2 = p[1];
	return p[4]*(pdf.Pdf( (x[0]-p[2])/p[3], kappa,beta2) );
    }

    ROOT::Math::VavilovAccurate pdf;
};


void fitting(){

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
    //cout <<  "signal+bkg : " << sigbkg_tMass->Integral(0,100) << endl;
    //cout <<  "bkg : " << bkg_tMass->Integral(0,100) << endl;
///////////////////////////// Fitting ////////////////////////////////

    Vavilov_Func *func = new Vavilov_Func();
    TF1 *fit = new TF1("fit",func,0,500,5,"Vavilov_Func"); 
    fit->SetParNames("kappa","beta2","meen","sigma","Amp");
    fit->SetParameters(0.3,0.05,sigbkg_tMass->GetMean(),sigbkg_tMass->GetRMS(),sigbkg_tMass->GetEntries());
    fit->SetParLimits(0.01,0,10);
    fit->SetParLimits(1,0,1);
    //bkg_tMass->Rebin(15);


    
    //fit->SetParLimits(3,146.5,130);//gaus 3rd? 
    //fit->SetParLimits(4,1,3);//gaus 4th?
    TFitResultPtr r = sigbkg_tMass->Fit(fit,"S");
    TMatrixDSym cov = r->GetCovarianceMatrix();
    sigbkg_tMass->Fit(fit);

    cout<<"Vavilov mean = " << fit->GetParameter(2) << " +/-" << fit->GetParError(2) << endl;
    cout<<"Vavilov sigma = " << fit->GetParameter(3) << " +/-" << fit->GetParError(3) << endl;

    sigbkg_tMass->SetLineColor(kBlue);
    fit->SetLineColor(kRed);

    sigbkg_tMass->Draw("hist");
    fit->Draw("same");

    sigbkg_tMass->GetXaxis()->SetTitle("M_{e, jet}");
    sigbkg_tMass->GetYaxis()->SetTitle("Number of events");
    sigbkg_tMass->GetXaxis()->CenterTitle(true);

    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

}

