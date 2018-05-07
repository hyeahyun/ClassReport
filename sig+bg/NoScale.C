void NoScale(){

    TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    //Signal
    TFile *signal = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/signal.root");
    

    //Single Top quarks
    TFile *SinAntiTop = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/SingleAntiTop.root");
    TFile *SinTop = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/SingleTop.root");
    
    //boson + jet
    TFile *wpj = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/w+j.root");
    TFile *wmj = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/w-j.root");
    TFile *zjet = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/zjet.root");
    
    //di-boson
    TFile *wpz = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/wpz.root");
    TFile *wmz = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/wmz.root");
    TFile *ww = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/ww.root");
    TFile *zz = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/zz.root");

    //W Mass histogram
    TH1F *sig_WMass = (TH1F*)signal->Get("histwM");
    
    TH1F *wMass_1 = (TH1F*)SinAntiTop->Get("histwM");
    TH1F *wMass_2 = (TH1F*)SinTop->Get("histwM");
    TH1F *wMass_3 = (TH1F*)wpj->Get("histwM");
    TH1F *wMass_4 = (TH1F*)wmj->Get("histwM");
    TH1F *wMass_5 = (TH1F*)zjet->Get("histwM");
    TH1F *wMass_6 = (TH1F*)wpz->Get("histwM");
    TH1F *wMass_7 = (TH1F*)wmz->Get("histwM");
    TH1F *wMass_8 = (TH1F*)ww->Get("histwM");
    TH1F *wMass_9 = (TH1F*)zz->Get("histwM");

    TH1F *BGWMass  = new TH1F("BGWMass","Background W Mass",1000,0,500);

    BGWMass->Add(wMass_1,1);
    BGWMass->Add(wMass_2,1);
    BGWMass->Add(wMass_3,1);
    BGWMass->Add(wMass_4,1);
    BGWMass->Add(wMass_5,1);
    BGWMass->Add(wMass_6,1);
    BGWMass->Add(wMass_7,1);
    BGWMass->Add(wMass_8,1);
    BGWMass->Add(wMass_9,1);

    //MissingET
    TH1F *sig_MET = (TH1F*)signal->Get("histMPT");

    TH1F *MET_1 = (TH1F*)SinAntiTop->Get("histMPT");
    TH1F *MET_2 = (TH1F*)SinTop->Get("histMPT");
    TH1F *MET_3 = (TH1F*)wpj->Get("histMPT");
    TH1F *MET_4 = (TH1F*)wmj->Get("histMPT");
    TH1F *MET_5 = (TH1F*)zjet->Get("histMPT");
    TH1F *MET_6 = (TH1F*)wpz->Get("histMPT");
    TH1F *MET_7 = (TH1F*)wmz->Get("histMPT");
    TH1F *MET_8 = (TH1F*)ww->Get("histMPT");
    TH1F *MET_9 = (TH1F*)zz->Get("histMPT");

    TH1F *BGMET = new TH1F("BGMET","Background MET",1000,0,1000);

    BGMET->Add(MET_1,1);
    BGMET->Add(MET_2,1);
    BGMET->Add(MET_3,1);
    BGMET->Add(MET_4,1);
    BGMET->Add(MET_5,1);
    BGMET->Add(MET_6,1);
    BGMET->Add(MET_7,1);
    BGMET->Add(MET_8,1);
    BGMET->Add(MET_9,1);

    //Electron + neutrino energy
    TH1F *sig_EPN = (TH1F*)signal->Get("histEPN");
    
    TH1F *EPN_1 = (TH1F*)SinAntiTop->Get("histEPN");
    TH1F *EPN_2 = (TH1F*)SinTop->Get("histEPN");
    TH1F *EPN_3 = (TH1F*)wpj->Get("histEPN");
    TH1F *EPN_4 = (TH1F*)wmj->Get("histEPN");
    TH1F *EPN_5 = (TH1F*)zjet->Get("histEPN");
    TH1F *EPN_6 = (TH1F*)wpz->Get("histEPN");
    TH1F *EPN_7 = (TH1F*)wmz->Get("histEPN");
    TH1F *EPN_8 = (TH1F*)ww->Get("histEPN");
    TH1F *EPN_9 = (TH1F*)zz->Get("histEPN");

    TH1F *AllEPN = new TH1F("AllEPN","Background Electron+neutrino energy",1000,0,1000);

    AllEPN->Add(EPN_1,1);
    AllEPN->Add(EPN_2,1);
    AllEPN->Add(EPN_3,1);
    AllEPN->Add(EPN_4,1);
    AllEPN->Add(EPN_5,1);
    AllEPN->Add(EPN_6,1);
    AllEPN->Add(EPN_7,1);
    AllEPN->Add(EPN_8,1);
    AllEPN->Add(EPN_9,1);

    //dijet mass
    TH1F *sig_jjM = (TH1F*)signal->Get("histjjM");
    
    TH1F *jjM_1 = (TH1F*)SinAntiTop->Get("histjjM");
    TH1F *jjM_2 = (TH1F*)SinTop->Get("histjjM");
    TH1F *jjM_3 = (TH1F*)wpj->Get("histjjM");
    TH1F *jjM_4 = (TH1F*)wmj->Get("histjjM");
    TH1F *jjM_5 = (TH1F*)zjet->Get("histjjM");
    TH1F *jjM_6 = (TH1F*)wpz->Get("histjjM");
    TH1F *jjM_7 = (TH1F*)wmz->Get("histjjM");
    TH1F *jjM_8 = (TH1F*)ww->Get("histjjM");
    TH1F *jjM_9 = (TH1F*)zz->Get("histjjM");

    TH1F *AlljjM = new TH1F("AlljjM","All dijet mass",1000,0,1000);

    AlljjM->Add(jjM_1,1);
    AlljjM->Add(jjM_2,1);
    AlljjM->Add(jjM_3,1);
    AlljjM->Add(jjM_4,1);
    AlljjM->Add(jjM_5,1);
    AlljjM->Add(jjM_6,1);
    AlljjM->Add(jjM_7,1);
    AlljjM->Add(jjM_8,1);
    AlljjM->Add(jjM_9,1);

    //jet + MET energy
    TH1F *sig_jpMET = (TH1F*)signal->Get("histtot");
    
    TH1F *jpMET_1 = (TH1F*)SinAntiTop->Get("histtot");
    TH1F *jpMET_2 = (TH1F*)SinTop->Get("histtot");
    TH1F *jpMET_3 = (TH1F*)wpj->Get("histtot");
    TH1F *jpMET_4 = (TH1F*)wmj->Get("histtot");
    TH1F *jpMET_5 = (TH1F*)zjet->Get("histtot");
    TH1F *jpMET_6 = (TH1F*)wpz->Get("histtot");
    TH1F *jpMET_7 = (TH1F*)wmz->Get("histtot");
    TH1F *jpMET_8 = (TH1F*)ww->Get("histtot");
    TH1F *jpMET_9 = (TH1F*)zz->Get("histtot");

    TH1F *AlljpMET = new TH1F("AlljpMET","All jet + MET energy",1000,0,1000);

    AlljpMET->Add(jpMET_1,1);
    AlljpMET->Add(jpMET_2,1);
    AlljpMET->Add(jpMET_3,1);
    AlljpMET->Add(jpMET_4,1);
    AlljpMET->Add(jpMET_5,1);
    AlljpMET->Add(jpMET_6,1);
    AlljpMET->Add(jpMET_7,1);
    AlljpMET->Add(jpMET_8,1);
    AlljpMET->Add(jpMET_9,1);

    //electron pt
    TH1F *sig_ElePt = (TH1F*)signal->Get("histElePt");
    
    TH1F *ElePt_1 = (TH1F*)SinAntiTop->Get("histElePt");
    TH1F *ElePt_2 = (TH1F*)SinTop->Get("histElePt");
    TH1F *ElePt_3 = (TH1F*)wpj->Get("histElePt");
    TH1F *ElePt_4 = (TH1F*)wmj->Get("histElePt");
    TH1F *ElePt_5 = (TH1F*)zjet->Get("histElePt");
    TH1F *ElePt_6 = (TH1F*)wpz->Get("histElePt");
    TH1F *ElePt_7 = (TH1F*)wmz->Get("histElePt");
    TH1F *ElePt_8 = (TH1F*)ww->Get("histElePt");
    TH1F *ElePt_9 = (TH1F*)zz->Get("histElePt");

    TH1F *AllElePt = new TH1F("AllElePt","electron pT",1000,0,200);

    AllElePt->Add(ElePt_1,1);
    AllElePt->Add(ElePt_1,2);
    AllElePt->Add(ElePt_1,3);
    AllElePt->Add(ElePt_1,4);
    AllElePt->Add(ElePt_1,5);
    AllElePt->Add(ElePt_1,6);
    AllElePt->Add(ElePt_1,7);
    AllElePt->Add(ElePt_1,8);
    AllElePt->Add(ElePt_1,9);


    // W Mass
    TCanvas *c1 = new TCanvas();
    sig_WMass->Rebin(15);
    BGWMass->Rebin(15);
    
    sig_WMass->SetLineColor(kRed);
    BGWMass->SetLineColor(kBlue);

    BGWMass->Draw();
    sig_WMass->Draw("same");

    BGWMass->GetXaxis()->SetTitle("M_{w}");
    BGWMass->GetYaxis()->SetTitle("Number of events");
    BGWMass->GetXaxis()->CenterTitle(true);

    // MissingET
    TCanvas *c2 = new TCanvas();
    sig_MET->Rebin(10);
    BGMET->Rebin(10);

    sig_MET->SetLineColor(kRed);
    BGMET->SetLineColor(kBlue);
    
    BGMET->Draw();
    sig_MET->Draw("same");
    
    BGMET->GetXaxis()->SetTitle("E_{miss}^{T}(GeV)");
    BGMET->GetYaxis()->SetTitle("Number of events");
    BGMET->GetXaxis()->CenterTitle(true);

    //Electron + neutrino
    TCanvas *c3 = new TCanvas();
    sig_EPN->Rebin(10);
    AllEPN->Rebin(10);

    sig_EPN->SetLineColor(kRed);
    AllEPN->SetLineColor(kBlue);
    AllEPN->Draw();
    sig_EPN->Draw("same");
    
    AllEPN->GetXaxis()->SetTitle("Electron + neutrino energy(GeV)");
    AllEPN->GetYaxis()->SetTitle("Number of events");
    AllEPN->GetXaxis()->CenterTitle(true);

    //dijet mass
    TCanvas *c4 = new TCanvas();
    sig_jjM->Rebin(10);
    AlljjM->Rebin(10);

    sig_jjM->SetLineColor(kRed);
    AlljjM->SetLineColor(kBlue);
    AlljjM->Draw();
    sig_jjM->Draw("same");
    
    AlljjM->GetXaxis()->SetTitle("M_{jj}");
    AlljjM->GetYaxis()->SetTitle("Number of events");
    AlljjM->GetXaxis()->CenterTitle(true);

    //jet + MET energy
    TCanvas *c5 = new TCanvas();
    sig_jpMET->Rebin(10);
    AlljpMET->Rebin(10);

    sig_jpMET->SetLineColor(kRed);
    AlljpMET->SetLineColor(kBlue);
    AlljpMET->Draw();
    sig_jpMET->Draw("same");
    
    AlljpMET->GetXaxis()->SetTitle("jet + MET energy(GeV)");
    AlljpMET->GetYaxis()->SetTitle("Number of events");
    AlljpMET->GetXaxis()->CenterTitle(true);

    //Electron pt
    TCanvas *c6 = new TCanvas();
    
    sig_ElePt->Rebin(10);
    AllElePt->Rebin(10);

    sig_ElePt->SetLineColor(kRed);
    AllElePt->SetLineColor(kBlue);
    AllElePt->Draw();
    sig_ElePt->Draw("same");
    
    AllElePt->GetXaxis()->SetTitle("Electron pT(GeV)");
    AllElePt->GetYaxis()->SetTitle("Number of events");
    AllElePt->GetXaxis()->CenterTitle(true);

    //gPad->BuildLegend();

}

