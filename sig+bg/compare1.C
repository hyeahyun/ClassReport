void compare1(){

    TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //Signal
    TFile *signal = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/signal.root");
    

    //Single Top quark
    TFile *t~w+ = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/t~w+.root");
    TFile *tw- = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/tw-.root");
    
    //w boson + jets
    TFile *w+jets = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/w+jets.root");
    TFile *w-jets = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/w-j.root");
    
    //di-boson
    TFile *w+z = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/wpz.root");
    TFile *w-z = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/wmz.root");
    TFile *ww = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/ww.root");

    //top quark + b jet
    TFile *tb~ = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/tb~.root");
    TFile *t~b = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/t~b.root");
   
    // ttbar + boson
    TFile *tt~z = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/tt~z.root");
    TFile *tt~w+ = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/tt~w+.root");

    TFile *tt~w- = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/tt~w-.root");

    // Drell-Yan
    TFile *DY = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/ppToll.root");
    
    /////////////////////// histogram ///////////////////////
    //W Mass histogram
    TH1F *sig_WMass = (TH1F*)signal->Get("histwM");
    
    TH1F *wMass_1 = (TH1F*)t~w+->Get("histwM");
    TH1F *wMass_2 = (TH1F*)tw-->Get("histwM");
    TH1F *wMass_3 = (TH1F*)w+jets->Get("histwM");
    TH1F *wMass_4 = (TH1F*)w-jets->Get("histwM");
    TH1F *wMass_5 = (TH1F*)w+z->Get("histwM");
    TH1F *wMass_6 = (TH1F*)w-z->Get("histwM");
    TH1F *wMass_7 = (TH1F*)ww->Get("histwM");
    TH1F *wMass_8 = (TH1F*)tb~->Get("histwM");
    TH1F *wMass_9 = (TH1F*)t~b->Get("histwM");
    TH1F *wMass_10 = (TH1F*)tt~z->Get("histwM");
    TH1F *wMass_11 = (TH1F*)tt~w+->Get("histwM");
    TH1F *wMass_12 = (TH1F*)tt~w-->Get("histwM");
    TH1F *wMass_13 = (TH1F*)DY-->Get("histwM");

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
    BGWMass->Add(wMass_10,1);
    BGWMass->Add(wMass_11,1);
    BGWMass->Add(wMass_12,1);
    BGWMass->Add(wMass_13,1);


    //MissingET
    TH1F *sig_MET = (TH1F*)signal->Get("histMPT");

    TH1F *MET_1 = (TH1F*)t~w+->Get("histMPT");
    TH1F *MET_2 = (TH1F*)tw-->Get("histMPT");
    TH1F *MET_3 = (TH1F*)w+jets->Get("histMPT");
    TH1F *MET_4 = (TH1F*)w-jets->Get("histMPT");
    TH1F *MET_5 = (TH1F*)w+z->Get("histMPT");
    TH1F *MET_6 = (TH1F*)w-z->Get("histMPT");
    TH1F *MET_7 = (TH1F*)ww->Get("histMPT");
    TH1F *MET_8 = (TH1F*)tb~->Get("histMPT");
    TH1F *MET_9 = (TH1F*)t~b->Get("histMPT");
    TH1F *MET_10 = (TH1F*)tt~z->Get("histMPT");
    TH1F *MET_11 = (TH1F*)tt~w+->Get("histMPT");
    TH1F *MET_12 = (TH1F*)tt~w-->Get("histMPT");
    TH1F *MET_13 = (TH1F*)DY->Get("histMPT");

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
    BGMET->Add(MET_10,1);
    BGMET->Add(MET_11,1);
    BGMET->Add(MET_12,1);
    BGMET->Add(MET_13,1);

    //dijet mass
TH1F *sig_JpT = (TH1F*)signal->Get("histJpT");

TH1F *JpT_1 = (TH1F*)t~w+->Get("histJpT");
TH1F *JpT_2 = (TH1F*)tw-->Get("histJpT");
TH1F *JpT_3 = (TH1F*)w+jets->Get("histJpT");
TH1F *JpT_4 = (TH1F*)w-jets->Get("histJpT");
TH1F *JpT_5 = (TH1F*)w+z->Get("histJpT");
TH1F *JpT_6 = (TH1F*)w-z->Get("histJpT");
TH1F *JpT_7 = (TH1F*)ww->Get("histJpT");
TH1F *JpT_8 = (TH1F*)tb~->Get("histJpT");
TH1F *JpT_9 = (TH1F*)t~b->Get("histJpT");
TH1F *JpT_10 = (TH1F*)tt~z->Get("histJpT");
TH1F *_11 = (TH1F*)tt~w+->Get("histJpT");
TH1F *jjM_12 = (TH1F*)tt~w-->Get("histJpT");
TH1F *jjM_13 = (TH1F*)DY->Get("histJpT");

TH1F *AlljjM = new TH1F("AllJpT","All dijet mass",1000,0,1000);

AlljjM->Add(jjM_1,1);
AlljjM->Add(jjM_2,1);
AlljjM->Add(jjM_3,1);
AlljjM->Add(jjM_4,1);
AlljjM->Add(jjM_5,1);
AlljjM->Add(jjM_6,1);
AlljjM->Add(jjM_7,1);
AlljjM->Add(jjM_8,1);
AlljjM->Add(jjM_9,1);
AlljjM->Add(jjM_10,1);
AlljjM->Add(jjM_11,1);
AlljjM->Add(jjM_12,1);
AlljjM->Add(jjM_13,1);

    //2 non b jets mass
    TH1F *sig_jjM = (TH1F*)signal->Get("histjjM");

    TH1F *jjM_1 = (TH1F*)t~w+->Get("histjjM");
    TH1F *jjM_2 = (TH1F*)tw-->Get("histjjM");
    TH1F *jjM_3 = (TH1F*)w+jets->Get("histjjM");
    TH1F *jjM_4 = (TH1F*)w-jets->Get("histjjM");
    TH1F *jjM_5 = (TH1F*)w+z->Get("histjjM");
    TH1F *jjM_6 = (TH1F*)w-z->Get("histjjM");
    TH1F *jjM_7 = (TH1F*)ww->Get("histjjM");
    TH1F *jjM_8 = (TH1F*)tb~->Get("histjjM");
    TH1F *jjM_9 = (TH1F*)t~b->Get("histjjM");
    TH1F *jjM_10 = (TH1F*)tt~z->Get("histjjM");
    TH1F *jjM_11 = (TH1F*)tt~w+->Get("histjjM");
    TH1F *jjM_12 = (TH1F*)tt~w-->Get("histjjM");
    TH1F *jjM_13 = (TH1F*)DY->Get("histjjM");

    TH1F *AlljjM = new TH1F("AllJpT","All dijet mass",1000,0,1000);

    AlljjM->Add(jjM_1,1);
    AlljjM->Add(jjM_2,1);
    AlljjM->Add(jjM_3,1);
    AlljjM->Add(jjM_4,1);
    AlljjM->Add(jjM_5,1);
    AlljjM->Add(jjM_6,1);
    AlljjM->Add(jjM_7,1);
    AlljjM->Add(jjM_8,1);
    AlljjM->Add(jjM_9,1);
    AlljjM->Add(jjM_10,1);
    AlljjM->Add(jjM_11,1);
    AlljjM->Add(jjM_12,1);
    AlljjM->Add(jjM_13,1);

    //elec pT
    TH1F *sig_ElePt = (TH1F*)signal->Get("histElePt");
    
    TH1F *ElePt_1 = (TH1F*)t~w+->Get("histElePt");
    TH1F *ElePt_2 = (TH1F*)tw-->Get("histElePt");
    TH1F *ElePt_3 = (TH1F*)w+jets->Get("histElePt");
    TH1F *ElePt_4 = (TH1F*)w-jets->Get("histElePt");
    TH1F *ElePt_5 = (TH1F*)w+z->Get("histElePt");
    TH1F *ElePt_6 = (TH1F*)w-z->Get("histElePt");
    TH1F *ElePt_7 = (TH1F*)ww->Get("histElePt");
    TH1F *ElePt_8 = (TH1F*)tb~->Get("histElePt");
    TH1F *ElePt_9 = (TH1F*)t~b->Get("histElePt");
    TH1F *ElePt_10 = (TH1F*)tt~z->Get("histElePt");
    TH1F *ElePt_11 = (TH1F*)tt~w+->Get("hisElePt");
    TH1F *ElePt_12 = (TH1F*)tt~w-->Get("hisElePt");
    TH1F *ElePt_13 = (TH1F*)DY~->Get("histElePt");

    TH1F *AllElePt = new TH1F("AllElePt","All Elec pT",1000,0,1000);

    AllElePt->Add(jpMET_1,1);
    AllElePt->Add(jpMET_2,1);
    AllElePt->Add(jpMET_3,1);
    AllElePt->Add(jpMET_4,1);
    AllElePt->Add(jpMET_5,1);
    AllElePt->Add(jpMET_6,1);
    AllElePt->Add(jpMET_7,1);
    AllElePt->Add(jpMET_8,1);
    AllElePt->Add(jpMET_9,1);
    AllElePt->Add(jpMET_10,1);
    AllElePt->Add(jpMET_11,1);
    AllElePt->Add(jpMET_12,1);
    AllElePt->Add(jpMET_13,1);

    //electron mass
    TH1F *sig_EleM = (TH1F*)signal->Get("histEleM");
    
    TH1F *EleM_1 = (TH1F*)t~w+->Get("histEleM");
    TH1F *EleM_2 = (TH1F*)tw-->Get("histEleM");
    TH1F *EleM_3 = (TH1F*)w+jets->Get("histEleM");
    TH1F *EleM_4 = (TH1F*)w-jets->Get("histEleM");
    TH1F *EleM_5 = (TH1F*)w+z->Get("histEleM");
    TH1F *EleM_6 = (TH1F*)w-z->Get("histEleM");
    TH1F *EleM_7 = (TH1F*)ww->Get("histEleM");
    TH1F *EleM_8 = (TH1F*)tb~->Get("histEleM");
    TH1F *EleM_9 = (TH1F*)t~b->Get("histEleM");
    TH1F *EleM_10 = (TH1F*)tt~z->Get("histEleM");
    TH1F *EleM_11 = (TH1F*)tt~w+->Get("histEleM");
    TH1F *EleM_12 = (TH1F*)tt~w-->Get("histEleM");
    TH1F *EleM_13 = (TH1F*)DY->Get("histEleM");

    TH1F *AllEleM = new TH1F("AllEleM","electron Mass",1000,0,200);

    AllEleM->Add(ElePt_1,1);
    AllEleM->Add(ElePt_2,1);
    AllEleM->Add(ElePt_3,1);
    AllEleM->Add(ElePt_4,1);
    AllEleM->Add(ElePt_5,1);
    AllEleM->Add(ElePt_6,1);
    AllEleM->Add(ElePt_7,1);
    AllEleM->Add(ElePt_8,1);
    AllEleM->Add(ElePt_9,1);
    AllEleM->Add(ElePt_10,1);
    AllEleM->Add(ElePt_11,1);
    AllEleM->Add(ElePt_12,1);
    AllEleM->Add(ElePt_13,1);


    // ttbar pT
    TH1F *sig_ttpT = (TH1F*)signal->Get("histtot");

    TH1F *ttpT_1 = (TH1F*)t~w+->Get("histtot");
    TH1F *ttpT_2 = (TH1F*)tw-->Get("histtot");
    TH1F *ttpT_3 = (TH1F*)w+jets->Get("histtot");
    TH1F *ttpT_4 = (TH1F*)w-jets->Get("histtot");
    TH1F *ttpT_5 = (TH1F*)w+z->Get("histtot");
    TH1F *ttpT_6 = (TH1F*)w-z->Get("histtot");
    TH1F *ttpT_7 = (TH1F*)ww->Get("histtot");
    TH1F *ttpT_8 = (TH1F*)tb~->Get("histtot");
    TH1F *ttpT_9 = (TH1F*)t~b->Get("histtot");
    TH1F *ttpT_10 = (TH1F*)tt~z->Get("histtot");
    TH1F *ttpT_11 = (TH1F*)tt~w+->Get("histtot");
    TH1F *ttpT_12 = (TH1F*)tt~w-->Get("histtot");
    TH1F *ttpT_13 = (TH1F*)DY->Get("histtot");

    TH1F *AllttpT = new TH1F("AllttpT","All ttbar pT",1000,0,1000);

    AllttpT->Add(jjM_1,1);
    AllttpT->Add(jjM_2,1);
    AllttpT->Add(jjM_3,1);
    AllttpT->Add(jjM_4,1);
    AllttpT->Add(jjM_5,1);
    AllttpT->Add(jjM_6,1);
    AllttpT->Add(jjM_7,1);
    AllttpT->Add(jjM_8,1);
    AllttpT->Add(jjM_9,1);
    AllttpT->Add(jjM_10,1);
    AllttpT->Add(jjM_11,1);
    AllttpT->Add(jjM_12,1);
    AllttpT->Add(jjM_13,1);

    //ttbar Mass
    TH1F *sig_ttM = (TH1F*)signal->Get("histJpT");

    TH1F *ttM_1 = (TH1F*)t~w+->Get("histJpT");
    TH1F *ttM_2 = (TH1F*)tw-->Get("histJpT");
    TH1F *ttM_3 = (TH1F*)w+jets->Get("histJpT");
    TH1F *ttM_4 = (TH1F*)w-jets->Get("histJpT");
    TH1F *ttM_5 = (TH1F*)w+z->Get("histJpT");
    TH1F *ttM_6 = (TH1F*)w-z->Get("histJpT");
    TH1F *ttM_7 = (TH1F*)ww->Get("histJpT");
    TH1F *ttM_8 = (TH1F*)tb~->Get("histJpT");
    TH1F *ttM_9 = (TH1F*)t~b->Get("histJpT");
    TH1F *ttM_10 = (TH1F*)tt~z->Get("histJpT");
    TH1F *ttM_11 = (TH1F*)tt~w+->Get("histJpT");
    TH1F *ttM_12 = (TH1F*)tt~w-->Get("histJpT");
    TH1F *ttM_13 = (TH1F*)DY->Get("histJpT");

    TH1F *AlljjM = new TH1F("AllJpT","All dijet mass",1000,0,1000);

    AlljjM->Add(jjM_1,1);
    AlljjM->Add(jjM_2,1);
    AlljjM->Add(jjM_3,1);
    AlljjM->Add(jjM_4,1);
    AlljjM->Add(jjM_5,1);
    AlljjM->Add(jjM_6,1);
    AlljjM->Add(jjM_7,1);
    AlljjM->Add(jjM_8,1);
    AlljjM->Add(jjM_9,1);
    AlljjM->Add(jjM_10,1);
    AlljjM->Add(jjM_11,1);
    AlljjM->Add(jjM_12,1);
    AlljjM->Add(jjM_13,1);



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

