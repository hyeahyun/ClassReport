void compare1(){

    TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //Signal
    TFile *signal = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/signal.root");
    

    //Single Top quark
    TFile *SingleTop = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/SingleTop.root");
    
    //w boson + jets
    TFile *w+jets = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/w+jets.root");
    
    //di-boson
    TFile *diboson = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/di-boson.root");

    //top quark + b jet
    TFile *t+b = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/t+b.root");
    
    // ttbar + boson
    TFile *tt~boson = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/tt~boson.root");

    // Drell-Yan
    TFile *DY = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/ppToll.root");
    
    /////////////////////// histogram ///////////////////////
    //electron energy + MET
    TH1F *sig_WMass = (TH1F*)signal->Get("histwM");
    
    TH1F *wMass_1 = (TH1F*)SingleTop->Get("histwM");
    TH1F *wMass_2 = (TH1F*)w+jets->Get("histwM");
    TH1F *wMass_3 = (TH1F*)diboson->Get("histwM");
    TH1F *wMass_4 = (TH1F*)t+b->Get("histwM");
    TH1F *wMass_5 = (TH1F*)tt~boson->Get("histwM");
    TH1F *wMass_6 = (TH1F*)DY->Get("histwM");

    TH1F *BGWMass  = new TH1F("BGWMass","Background W Mass",1000,0,500);

    BGWMass->Add(wMass_1,1);
    BGWMass->Add(wMass_2,1);
    BGWMass->Add(wMass_3,1);
    BGWMass->Add(wMass_4,1);
    BGWMass->Add(wMass_5,1);
    BGWMass->Add(wMass_6,1);


    //MissingET
    TH1F *sig_MET = (TH1F*)signal->Get("histMPT");

    TH1F *MET_1 = (TH1F*)SingleTop->Get("histMPT");
    TH1F *MET_2 = (TH1F*)w+jets->Get("histMPT");
    TH1F *MET_3 = (TH1F*)diboson->Get("histMPT");
    TH1F *MET_4 = (TH1F*)t+b->Get("histMPT");
    TH1F *MET_5 = (TH1F*)tt~boson->Get("histMPT");
    TH1F *MET_6 = (TH1F*)DY->Get("histMPT");

    TH1F *BGMET = new TH1F("BGMET","Background MET",1000,0,1000);

    BGMET->Add(MET_1,1);
    BGMET->Add(MET_2,1);
    BGMET->Add(MET_3,1);
    BGMET->Add(MET_4,1);
    BGMET->Add(MET_5,1);
    BGMET->Add(MET_6,1);

    //dijet mass
TH1F *sig_HT = (TH1F*)signal->Get("histHT");

TH1F *HT_1 = (TH1F*)SingleTop->Get("histHT");
TH1F *HT_2 = (TH1F*)w+jets->Get("histJHT");
TH1F *HT_3 = (TH1F*)diboson->Get("histHT");
TH1F *HT_4 = (TH1F*)t+b->Get("histHT");
TH1F *HT_5 = (TH1F*)tt~boson->Get("histHT");
TH1F *HT_6 = (TH1F*)DY->Get("histHT");

TH1F *AllHT = new TH1F("AllJpT","All dijet mass",1000,0,1000);

AllHT->Add(jjM_1,1);
AllHT->Add(jjM_2,1);
AllHT->Add(jjM_3,1);
AllHT->Add(jjM_4,1);
AllHT->Add(jjM_5,1);
AllHT->Add(jjM_6,1);

    //2 non b jets mass
    TH1F *sig_jjM = (TH1F*)signal->Get("histjjM");

    TH1F *jjM_1 = (TH1F*)SingleTop->Get("histjjM");
    TH1F *jjM_2 = (TH1F*)w+jets->Get("histjjM");
    TH1F *jjM_3 = (TH1F*)diboson->Get("histjjM");
    TH1F *jjM_4 = (TH1F*)t+b->Get("histjjM");
    TH1F *jjM_5 = (TH1F*)tt~boson->Get("histjjM");
    TH1F *jjM_6 = (TH1F*)DY->Get("histjjM");

    TH1F *AlljjM = new TH1F("AllJpT","All dijet mass",1000,0,1000);

    AlljjM->Add(jjM_1,1);
    AlljjM->Add(jjM_2,1);
    AlljjM->Add(jjM_3,1);
    AlljjM->Add(jjM_4,1);
    AlljjM->Add(jjM_5,1);
    AlljjM->Add(jjM_6,1);

    //elec pT
    TH1F *sig_ElePt = (TH1F*)signal->Get("histElePt");
    
    TH1F *ElePt_1 = (TH1F*)SingleTop->Get("histElePt");
    TH1F *ElePt_2 = (TH1F*)w+jets->Get("histElePt");
    TH1F *ElePt_3 = (TH1F*)diboson->Get("histElePt");
    TH1F *ElePt_4 = (TH1F*)t+b->Get("histElePt");
    TH1F *ElePt_5 = (TH1F*)tt~boson->Get("histElePt");
    TH1F *ElePt_6 = (TH1F*)DY->Get("histElePt");

    TH1F *AllElePt = new TH1F("AllElePt","All Elec pT",1000,0,1000);

    AllElePt->Add(jpMET_1,1);
    AllElePt->Add(jpMET_2,1);
    AllElePt->Add(jpMET_3,1);
    AllElePt->Add(jpMET_4,1);
    AllElePt->Add(jpMET_5,1);
    AllElePt->Add(jpMET_6,1);
    
    //electron mass
    TH1F *sig_EleM = (TH1F*)signal->Get("histEleM");
    
    TH1F *EleM_1 = (TH1F*)SingleTop->Get("histEleM");
    TH1F *EleM_2 = (TH1F*)w+jets->Get("histEleM");
    TH1F *EleM_3 = (TH1F*)diboson->Get("histEleM");
    TH1F *EleM_4 = (TH1F*)t+b->Get("histEleM");
    TH1F *EleM_5 = (TH1F*)tt~boson->Get("histEleM");
    TH1F *EleM_6 = (TH1F*)DY->Get("histEleM");

    TH1F *AllEleM = new TH1F("AllEleM","electron Mass",1000,0,200);

    AllEleM->Add(ElePt_1,1);
    AllEleM->Add(ElePt_2,1);
    AllEleM->Add(ElePt_3,1);
    AllEleM->Add(ElePt_4,1);
    AllEleM->Add(ElePt_5,1);
    AllEleM->Add(ElePt_6,1);


    // ttbar pT
    TH1F *sig_ttpT = (TH1F*)signal->Get("histtot");

    TH1F *ttpT_1 = (TH1F*)SingleTop->Get("histtot");
    TH1F *ttpT_2 = (TH1F*)w+jets->Get("histtot");
    TH1F *ttpT_3 = (TH1F*)diboson->Get("histtot");
    TH1F *ttpT_4 = (TH1F*)t+b->Get("histtot");
    TH1F *ttpT_5 = (TH1F*)tt~boson->Get("histtot");
    TH1F *ttpT_6 = (TH1F*)DY->Get("histtot");

    TH1F *AllttpT = new TH1F("AllttpT","All ttbar pT",1000,0,1000);

    AllttpT->Add(jjM_1,1);
    AllttpT->Add(jjM_2,1);
    AllttpT->Add(jjM_3,1);
    AllttpT->Add(jjM_4,1);
    AllttpT->Add(jjM_5,1);
    AllttpT->Add(jjM_6,1);

    //ttbar Mass
    TH1F *sig_ttM = (TH1F*)signal->Get("histJpT");

    TH1F *ttM_1 = (TH1F*)SingleTop->Get("histJpT");
    TH1F *ttM_2 = (TH1F*)w_jets->Get("histJpT");
    TH1F *ttM_3 = (TH1F*)diboson->Get("histJpT");
    TH1F *ttM_4 = (TH1F*)t+b->Get("histJpT");
    TH1F *ttM_5 = (TH1F*)tt~boson->Get("histJpT");
    TH1F *ttM_6 = (TH1F*)DY->Get("histJpT");

    TH1F *AlljjM = new TH1F("AllJpT","All dijet mass",1000,0,1000);

    AlljjM->Add(jjM_1,1);
    AlljjM->Add(jjM_2,1);
    AlljjM->Add(jjM_3,1);
    AlljjM->Add(jjM_4,1);
    AlljjM->Add(jjM_5,1);
    AlljjM->Add(jjM_6,1);



    // W Mass
    TCanvas *c1 = new TCanvas();
    sig_WMass->Rebin(15);
    BGWMass->Rebin(15);
    float sig_norm1 = sig_WMass->Integral(0,500);
    float bg_norm1 = BGWMass->Integral(0,500);
    
    c1->SetLogy();
    sig_WMass->Scale(1./sig_norm1);
    BGWMass->Scale(1./bg_norm1);

    sig_WMass->SetLineColor(kRed);
    BGWMass->SetLineColor(kBlue);

    sig_WMass->Draw();
    BGWMass->Draw("same");

    sig_WMass->GetXaxis()->SetTitle("M_{w}");
    sig_WMass->GetYaxis()->SetTitle("percentage of events");
    sig_WMass->GetXaxis()->CenterTitle(true);

    // MissingET
    TCanvas *c2 = new TCanvas();
    sig_MET->Rebin(10);
    BGMET->Rebin(10);
    float sig_norm2 = sig_MET->Integral(0,1000);
    float bg_norm2 = BGMET->Integral(0,1000);
    sig_MET->Scale(1./sig_norm2);
    BGMET->Scale(1./bg_norm2);

    c2->SetLogy();
    sig_MET->SetLineColor(kRed);
    BGMET->SetLineColor(kBlue);
    
    sig_MET->Draw();
    BGMET->Draw("same");
    
    sig_MET->GetXaxis()->SetTitle("E_{miss}^{T}(GeV)");
    sig_MET->GetYaxis()->SetTitle("percentage of events");
    sig_MET->GetXaxis()->CenterTitle(true);

    //Electron + neutrino
    TCanvas *c3 = new TCanvas();
    sig_EPN->Rebin(10);
    AllEPN->Rebin(10);
    float sig_norm3 = sig_EPN->Integral(0,1000);
    float bg_norm3 = AllEPN->Integral(0,1000);
    sig_EPN->Scale(1./sig_norm3);
    AllEPN->Scale(1./bg_norm3);

    c3->SetLogy();
    sig_EPN->SetLineColor(kRed);
    AllEPN->SetLineColor(kBlue);
    sig_EPN->Draw();
    AllEPN->Draw("same");
    
    sig_EPN->GetXaxis()->SetTitle("Electron + Neutrino energy(GeV)");
    sig_EPN->GetYaxis()->SetTitle("percentage of events");
    sig_EPN->GetXaxis()->CenterTitle(true);

    //dijet mass
    TCanvas *c4 = new TCanvas();
    sig_jjM->Rebin(10);
    AlljjM->Rebin(10);
    float sig_norm4 = sig_jjM->Integral(0,1000);
    float bg_norm4 = AlljjM->Integral(0,1000);
    sig_jjM->Scale(1./sig_norm4);
    AlljjM->Scale(1./bg_norm4);

    c4->SetLogy();
    sig_jjM->SetLineColor(kRed);
    AlljjM->SetLineColor(kBlue);
    sig_jjM->Draw();
    AlljjM->Draw("same");
    
    sig_jjM->GetXaxis()->SetTitle("M_{jj}");
    sig_jjM->GetYaxis()->SetTitle("percentage of events");
    sig_jjM->GetXaxis()->CenterTitle(true);

    //jet + MET energy
    TCanvas *c5 = new TCanvas();
    sig_jpMET->Rebin(10);
    AlljpMET->Rebin(10);
    float sig_norm5 = sig_jpMET->Integral(0,1000);
    float bg_norm5 = AlljpMET->Integral(0,1000);
    sig_jpMET->Scale(1./sig_norm5);
    AlljpMET->Scale(1./bg_norm5);

    c5->SetLogy();
    sig_jpMET->SetLineColor(kRed);
    AlljpMET->SetLineColor(kBlue);
    sig_jpMET->Draw();
    AlljpMET->Draw("same");
    
    sig_jpMET->GetXaxis()->SetTitle("jet + Electron + Neutrino energy(GeV)");
    sig_jpMET->GetYaxis()->SetTitle("percentage of events");
    sig_jpMET->GetXaxis()->CenterTitle(true);

    //Electron pt
    TCanvas *c6 = new TCanvas();
    
    sig_ElePt->Rebin(10);
    AllElePt->Rebin(10);
    float sig_norm6 = sig_ElePt->Integral(0,1000);
    float bg_norm6 = AllElePt->Integral(0,1000);
    sig_ElePt->Scale(1./sig_norm6);
    AllElePt->Scale(1./bg_norm6);

    c6->SetLogy();
    sig_ElePt->SetLineColor(kRed);
    AllElePt->SetLineColor(kBlue);
    AllElePt->Draw();
    sig_ElePt->Draw("same");
    
    AllElePt->GetXaxis()->SetTitle("Electron pT(GeV)");
    AllElePt->GetYaxis()->SetTitle("percentage of events");
    AllElePt->GetXaxis()->CenterTitle(true);

    //gPad->BuildLegend();

}

