void compare3(){

    //TFile *outFile = new TFile("AllBackground.root","recreate");
    //TCanvas *c1 = new TCanvas();

    /////////////////////// TFile ///////////////////////
    //Signal
    TFile *signal = new TFile("/u/user/hgass66/MadGraph/song/data17/signal.root");
    

    //Single Top quark
    TFile *SingleTop = new TFile("/u/user/hgass66/MadGraph/song/data17/sum/SingleTop.root");
    
    //w boson + jets
    TFile *wjets = new TFile("/u/user/hgass66/MadGraph/song/data17/sum/wjets.root");
    
    //di-boson
    TFile *diboson = new TFile("/u/user/hgass66/MadGraph/song/data17/sum/diboson.root");

    //top quark + b jet
    TFile *tb = new TFile("/u/user/hgass66/MadGraph/song/data17/sum/tb.root");
    
    // ttbar + boson
    TFile *ttboson = new TFile("/u/user/hgass66/MadGraph/song/data17/sum/ttboson.root");

    // Drell-Yan
    TFile *DY = new TFile("/u/user/hgass66/MadGraph/song/data17/sum/ppToll.root");
    
    /////////////////////// histogram ///////////////////////
    //electron energy + MET
    TH1F *sig_wMass = (TH1F*)signal->Get("histwM");
    
    TH1F *wMass_1 = (TH1F*)SingleTop->Get("histwM");
    TH1F *wMass_2 = (TH1F*)wjets->Get("histwM");
    TH1F *wMass_3 = (TH1F*)diboson->Get("histwM");
    TH1F *wMass_4 = (TH1F*)tb->Get("histwM");
    TH1F *wMass_5 = (TH1F*)ttboson->Get("histwM");
    TH1F *wMass_6 = (TH1F*)DY->Get("histwM");
    

    //MissingET
    TH1F *sig_MET = (TH1F*)signal->Get("histMPT");

    TH1F *MET_1 = (TH1F*)SingleTop->Get("histMPT");
    TH1F *MET_2 = (TH1F*)wjets->Get("histMPT");
    TH1F *MET_3 = (TH1F*)diboson->Get("histMPT");
    TH1F *MET_4 = (TH1F*)tb->Get("histMPT");
    TH1F *MET_5 = (TH1F*)ttboson->Get("histMPT");
    TH1F *MET_6 = (TH1F*)DY->Get("histMPT");
    
    //HT
    TH1F *sig_HT = (TH1F*)signal->Get("hisHT");

    TH1F *HT_1 = (TH1F*)SingleTop->Get("hisHT");
    TH1F *HT_2 = (TH1F*)wjets->Get("hisHT");
    TH1F *HT_3 = (TH1F*)diboson->Get("hisHT");
    TH1F *HT_4 = (TH1F*)tb->Get("hisHT");
    TH1F *HT_5 = (TH1F*)ttboson->Get("hisHT");
    TH1F *HT_6 = (TH1F*)DY->Get("hisHT");


    //2 non b jets mass
    TH1F *sig_jjM = (TH1F*)signal->Get("histjjM");

    TH1F *jjM_1 = (TH1F*)SingleTop->Get("histjjM");
    TH1F *jjM_2 = (TH1F*)wjets->Get("histjjM");
    TH1F *jjM_3 = (TH1F*)diboson->Get("histjjM");
    TH1F *jjM_4 = (TH1F*)tb->Get("histjjM");
    TH1F *jjM_5 = (TH1F*)ttboson->Get("histjjM");
    TH1F *jjM_6 = (TH1F*)DY->Get("histjjM");
    

    //elec pT
    TH1F *sig_ElePt = (TH1F*)signal->Get("histElePt");
    
    TH1F *ElePt_1 = (TH1F*)SingleTop->Get("histElePt");
    TH1F *ElePt_2 = (TH1F*)wjets->Get("histElePt");
    TH1F *ElePt_3 = (TH1F*)diboson->Get("histElePt");
    TH1F *ElePt_4 = (TH1F*)tb->Get("histElePt");
    TH1F *ElePt_5 = (TH1F*)ttboson->Get("histElePt");
    TH1F *ElePt_6 = (TH1F*)DY->Get("histElePt");

    
    //electron mass
    TH1F *sig_EleM = (TH1F*)signal->Get("histEleM");
    
    TH1F *EleM_1 = (TH1F*)SingleTop->Get("histEleM");
    TH1F *EleM_2 = (TH1F*)wjets->Get("histEleM");
    TH1F *EleM_3 = (TH1F*)diboson->Get("histEleM");
    TH1F *EleM_4 = (TH1F*)tb->Get("histEleM");
    TH1F *EleM_5 = (TH1F*)ttboson->Get("histEleM");
    TH1F *EleM_6 = (TH1F*)DY->Get("histEleM");



    // ttbar pT
    TH1F *sig_ttpT = (TH1F*)signal->Get("histtot");

    TH1F *ttpT_1 = (TH1F*)SingleTop->Get("histtot");
    TH1F *ttpT_2 = (TH1F*)wjets->Get("histtot");
    TH1F *ttpT_3 = (TH1F*)diboson->Get("histtot");
    TH1F *ttpT_4 = (TH1F*)tb->Get("histtot");
    TH1F *ttpT_5 = (TH1F*)ttboson->Get("histtot");
    TH1F *ttpT_6 = (TH1F*)DY->Get("histtot");


    //ttbar Mass
    TH1F *sig_ttM = (TH1F*)signal->Get("histMtt");

    TH1F *ttM_1 = (TH1F*)SingleTop->Get("histMtt");
    TH1F *ttM_2 = (TH1F*)wjets->Get("histMtt");
    TH1F *ttM_3 = (TH1F*)diboson->Get("histMtt");
    TH1F *ttM_4 = (TH1F*)tb->Get("histMtt");
    TH1F *ttM_5 = (TH1F*)ttboson->Get("histMtt");
    TH1F *ttM_6 = (TH1F*)DY->Get("histMtt");


    //electron eta
    TH1F *sig_eta = (TH1F*)signal->Get("histEleEta");

    TH1F *eta_1 = (TH1F*)SingleTop->Get("histEleEta");
    TH1F *eta_2 = (TH1F*)wjets->Get("histEleEta");
    TH1F *eta_3 = (TH1F*)diboson->Get("histEleEta");
    TH1F *eta_4 = (TH1F*)tb->Get("histEleEta");
    TH1F *eta_5 = (TH1F*)ttboson->Get("histEleEta");
    TH1F *eta_6 = (TH1F*)DY->Get("histEleEta");

///////////////////////////// Canvas ////////////////////////////////

    // ele + MET
    TCanvas *c1 = new TCanvas();
    
    sig_wMass->Rebin(15);
    wMass_1->Rebin(15);
    wMass_2->Rebin(15);
    wMass_3->Rebin(15);
    wMass_4->Rebin(15);
    wMass_5->Rebin(15);
    wMass_6->Rebin(15);

    sig_wMass->SetLineColor(1);
    wMass_1->SetLineColor(2);
    wMass_2->SetLineColor(3);
    wMass_3->SetLineColor(4);
    wMass_4->SetLineColor(5);
    wMass_5->SetLineColor(6);
    wMass_6->SetLineColor(7);

    sig_wMass->Draw();
    wMass_1->Draw("sames");
    wMass_2->Draw("sames");
    wMass_3->Draw("sames");
    wMass_4->Draw("sames");
    wMass_5->Draw("sames");
    wMass_6->Draw("sames");

    sig_wMass->GetXaxis()->SetTitle("electron energy + E^{miss}_{T}");
    sig_wMass->GetYaxis()->SetTitle("Number of events");
    sig_wMass->GetXaxis()->CenterTitle(true);

    // MissingET
    TCanvas *c2 = new TCanvas();
    sig_MET->Rebin(10);
    MET_1->Rebin(10);
    MET_2->Rebin(10);
    MET_3->Rebin(10);
    MET_4->Rebin(10);
    MET_5->Rebin(10);
    MET_6->Rebin(10);

    sig_MET->SetLineColor(1);
    MET_1->SetLineColor(2);
    MET_2->SetLineColor(3);
    MET_3->SetLineColor(4);
    MET_4->SetLineColor(5);
    MET_5->SetLineColor(6);
    MET_6->SetLineColor(7);
    
    MET_6->Draw();
    MET_1->Draw("same");
    MET_2->Draw("same");
    MET_3->Draw("same");
    MET_4->Draw("same");
    MET_5->Draw("same");
    sig_MET->Draw("same");
     
    MET_6->GetXaxis()->SetRangeUser(0,400);
    MET_6->GetXaxis()->SetTitle("E_{miss}^{T}(GeV)");
    MET_6->GetYaxis()->SetTitle("Number of events");
    MET_6->GetXaxis()->CenterTitle(true);
    gStyle->SetOptStat(0);

    //HT
    TCanvas *c3 = new TCanvas();
    sig_HT->Rebin(10);
    HT_1->Rebin(10);
    HT_2->Rebin(10);
    HT_3->Rebin(10);
    HT_4->Rebin(10);
    HT_5->Rebin(10);
    HT_6->Rebin(10);

    sig_HT->SetLineColor(1);
    HT_1->SetLineColor(2);
    HT_2->SetLineColor(3);
    HT_3->SetLineColor(4);
    HT_4->SetLineColor(5);
    HT_5->SetLineColor(6);
    HT_6->SetLineColor(7);
    
    sig_HT->Draw();
    HT_1->Draw("same");
    HT_2->Draw("same");
    HT_3->Draw("same");
    HT_4->Draw("same");
    HT_5->Draw("same");
    HT_6->Draw("same");
    
    sig_HT->GetXaxis()->SetTitle("HT");
    sig_HT->GetYaxis()->SetTitle("Number of events");
    sig_HT->GetXaxis()->CenterTitle(true);
    gStyle->SetOptStat(0);

    //dijet mass
    TCanvas *c4 = new TCanvas();
    //sig_jjM->Rebin(10);
    //AlljjM->Rebin(10);

    sig_jjM->SetLineColor(1);
    jjM_1->SetLineColor(2);
    jjM_2->SetLineColor(3);
    jjM_3->SetLineColor(4);
    jjM_4->SetLineColor(5);
    jjM_5->SetLineColor(6);
    jjM_6->SetLineColor(7);
    
    sig_jjM->Draw();
    jjM_1->Draw("same");
    jjM_2->Draw("same");
    jjM_3->Draw("same");
    jjM_4->Draw("same");
    jjM_5->Draw("same");
    jjM_6->Draw("same");
    
    sig_jjM->GetXaxis()->SetTitle("M_{jj}");
    sig_jjM->GetYaxis()->SetTitle("Number of events");
    sig_jjM->GetXaxis()->CenterTitle(true);

    //electron mass
    TCanvas *c5 = new TCanvas();
    //sig_jpMET->Rebin(10);
    //AlljpMET->Rebin(10);

    sig_EleM->SetLineColor(1);
    EleM_1->SetLineColor(2);
    EleM_2->SetLineColor(3);
    EleM_3->SetLineColor(4);
    EleM_4->SetLineColor(5);
    EleM_5->SetLineColor(6);
    EleM_6->SetLineColor(7);
    
    sig_EleM->Draw();
    EleM_1->Draw("same");
    EleM_2->Draw("same");
    EleM_3->Draw("same");
    EleM_4->Draw("same");
    EleM_5->Draw("same");
    EleM_6->Draw("same");
    
    sig_EleM->GetXaxis()->SetTitle("M_{e}");
    sig_EleM->GetYaxis()->SetTitle("Number of events");
    sig_EleM->GetXaxis()->CenterTitle(true);

    //Electron pt
    TCanvas *c6 = new TCanvas();
    
    sig_ElePt->Rebin(10);
    ElePt_1->Rebin(10);
    ElePt_2->Rebin(10);
    ElePt_3->Rebin(10);
    ElePt_4->Rebin(10);
    ElePt_5->Rebin(10);
    ElePt_6->Rebin(10);

    sig_ElePt->SetLineColor(1);
    ElePt_1->SetLineColor(2);
    ElePt_2->SetLineColor(3);
    ElePt_3->SetLineColor(4);
    ElePt_4->SetLineColor(5);
    ElePt_5->SetLineColor(6);
    ElePt_6->SetLineColor(7);
    
    sig_ElePt->Draw();
    ElePt_1->Draw("same");
    ElePt_2->Draw("same");
    ElePt_3->Draw("same");
    ElePt_4->Draw("same");
    ElePt_5->Draw("same");
    ElePt_6->Draw("same");
    
    sig_ElePt->GetXaxis()->SetRangeUser(0,400);
    sig_ElePt->GetXaxis()->SetTitle("Electron pT(GeV)");
    sig_ElePt->GetYaxis()->SetTitle("Number of events");
    sig_ElePt->GetXaxis()->CenterTitle(true);
    gStyle->SetOptStat(0);

    //gPad->BuildLegend();

    //ttbar pT
    TCanvas *c7 = new TCanvas();

    sig_ttpT->SetLineColor(1);
    ttpT_1->SetLineColor(2);
    ttpT_2->SetLineColor(3);
    ttpT_3->SetLineColor(4);
    ttpT_4->SetLineColor(5);
    ttpT_5->SetLineColor(6);
    ttpT_6->SetLineColor(7);

    sig_ttpT->Draw();
    ttpT_1->Draw("same");
    ttpT_2->Draw("same");
    ttpT_3->Draw("same");
    ttpT_4->Draw("same");
    ttpT_5->Draw("same");
    ttpT_6->Draw("same");

    sig_ttpT->GetXaxis()->SetTitle("ttbar pT");
    sig_ttpT->GetYaxis()->SetTitle("Number of events");
    sig_ttpT->GetXaxis()->CenterTitle(true);

    //ttbar mass
    TCanvas *c8 = new TCanvas();

    sig_ttM->SetLineColor(1);
    ttM_1->SetLineColor(2);
    ttM_2->SetLineColor(3);
    ttM_3->SetLineColor(4);
    ttM_4->SetLineColor(5);
    ttM_5->SetLineColor(6);
    ttM_6->SetLineColor(7);

    sig_ttM->Draw();
    ttM_1->Draw("same");
    ttM_2->Draw("same");
    ttM_3->Draw("same");
    ttM_4->Draw("same");
    ttM_5->Draw("same");
    ttM_6->Draw("same");

    sig_ttM->GetXaxis()->SetTitle("ttbar mass");
    sig_ttM->GetYaxis()->SetTitle("Number of events");
    sig_ttM->GetXaxis()->CenterTitle(true);

    //electron eta
    TCanvas *c9 = new TCanvas();

    sig_eta->SetLineColor(1);
    eta_1->SetLineColor(2);
    eta_2->SetLineColor(3);
    eta_3->SetLineColor(4);
    eta_4->SetLineColor(5);
    eta_5->SetLineColor(6);
    eta_6->SetLineColor(7);

    sig_eta->Draw();
    eta_1->Draw("same");
    eta_2->Draw("same");
    eta_3->Draw("same");
    eta_4->Draw("same");
    eta_5->Draw("same");
    eta_6->Draw("same");

    sig_eta->GetXaxis()->SetRangeUser(-4,4);
    sig_eta->GetXaxis()->SetTitle("Electron eta");
    sig_eta->GetYaxis()->SetTitle("Number of events");
    sig_eta->GetXaxis()->CenterTitle(true);
    gStyle->SetOptStat(0);

}

