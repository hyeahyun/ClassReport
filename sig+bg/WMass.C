void WMass(){

    TCanvas *c1 = new TCanvas();

    TFile *f_bg = new TFile("AllBackground.root");
    TFile *f_sig = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/signal.root");

    TH1F *h_bg = (TH1F*)f_bg->Get("");
    TH1F *h_sig = (TH1F*)f_sig->Get("histwM");

    float norm1 = h_bg -> Integral(0,500);
    float norm2 = h_sig -> Integral(0,500);

    h_bg>Scale(1./norm1);
    h_sig>Scale(1./norm1);

    h_bg->SetLineColor(kRed);
    h_sig->SetLineColor(kBlue);

    c1->SetLogy();

    //h1->GetYaxis()->SetRangeUser(0.001,1.);

    h_bg->Draw();
    h_sig->Draw("same");

    h_bg->GetYaxis()->SetTitle("percentage of events");

    leg = new TLegend(0.15,0.65,0.35,0.85);
    leg->AddEntry(h_bg,"Background","le");
    leg->AddEntry(h_sig,"Signal","le");
    leg->Draw();

}


